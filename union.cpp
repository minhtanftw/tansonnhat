union Adcvalue{
    uint16_t fullValue;
    struct{
        uint8_t lowByte;
        uint8_t highByte;

    }bytes;

};

void readADC(void) {
    union Adcvalue adc;
    //Supposed low byte is read first, high byte is read later
    adc.bytes.lowBytes = read_adc_low_bytes_register();
    adc.bytes.highByte = read_adc_high_byte_register();

    // Now 16-bit values ​​can be accessed
    printf("ADC Value: %u\n", adc.fullValue);

}