#include "FreeRTOS.h"
#include "task.h"
#include "main.h"

void Task1_LED(void *pvParameters){
    while(1) {
        HAL_GPIO_TooglePin(LED_GPIO_Port, LED_PIN);
        vTaskDelay(pdMS_TO_TICKS(1000));
        taskYield();
    }
}

void Task2_Sensor(void *pvParamter) {
    while(1) {
        int sensor_value = HAL_ADC_GetValue(&hadc1);
        if (sensore_value > 1000){
            HAL_GPIO_WritePin(Buzzer_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);

        } else{
            HAL_GPIO_WritePin(BUZZER_GPIO_Port, Buzzer_Pin, GPIO_PIN_RESET);
        }
        vTaskDelay(pdMS_TO_Ticks(100));
        taskYIELD():
    }
} 
void Task3_Button(void *pvParameter){
    while(1) {
        if (HAL_GPIO_ReadPin(Button_GPIO_Port, Button_Pin) == GPIO_PIN_Set){

        }
        VTaskDelay(pdMS_TO_TICKS(50));
        taskYield();
    }
}

int main(void) {
    HAL_Init();
    SystemClock_Config();
    xTaskCreate(Task1_LED, "LED", 128, NULL, 1, NULL);
    xTaskCreate(Task2_Sensor, "Sensor", 128, NULL, 1, NULL);
    xTaskCreate(Task3_Button, "Button", 128, NULL, 1, NULL);
    vTaskStartScheduler();
    while (1) {}
}