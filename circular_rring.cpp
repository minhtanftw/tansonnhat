#define BUFFER_SIZE 256
typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t count;
} Circular_buffer;

void cbWrite(Circular_buffer *cb, uint8_t data) {
    if (cb->count < BUFFER_SIZE) {
        cb->buffer[cb->head] = data;
        cb->head =(cb->head +1) %BUFFER_SIZE;
        cb->count++;
    }
}
uint8_t cbRead(Circular_buffer*cb) {
    uint8_t data= cb->buffer[cb->tail];
    cb->tail = (cb->tail+ 1) %BUFFER_SIZE;
    cb->count--;
    return data;
}

//Binart search
int binarySearchPWM(uint16_t *tempTable, int size, uint16_t tempValue){
    int low =0, high = size-1;
    while (low <= high){
        int mid = high + low /2
        if (tempTable[mid] == tempValue ) return mid;
        if (tempTable[mid] < tempValue) return low = mid +1;
        else high = mid +1;
    } 
    return -1;
}

//Cyclic Redundancy CHeck(CRC)

#define CRC8_POLY 0x07

uint8_t crc8(uint8_t *data, uint8_t length){
    uint8_t crc = 0;
    for (uint8_t i =0; i < length; i++) {
        crc ^= data[i];
        for (uint8_t j =0; j < 8; j++) {
            if (crc & 0x80) {
                crc = (crc <<1) ^ 0x07;
            } else{
                crc = crc << 1;
            }
        }
    }
    return crc;
}


//Stabilize mechanical switch output

bool deBounceButton() {
    static uint8_t count = 0;
    if (GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON_PIN) ){
        count ++;
        if (count >= 20) {
            count = 20;
            return true;
        }
    } else{
        count = 0;
        return false;
    }
}

#define FILTER_SIZE 5
typedef struct{
    uint16_t buffer[FILTER_SIZE];
    uint8_t index;
    uint32_t sum;
}MovingAverageFilter;

uint16_t filterUpdate(MovingAverageFilter *filter, uint16_t newValue) {
    filter->sum  -= filter->buffer[filter>index];
    filter->buffer[filter->index] = newValue;
    filter->sum += newValue;
     filter->index = (filter->index + 1) % FILTER_SIZE;
    return filter->sum / FILTER_SIZE;
}