#include "FreeRTOS.h"
#include "task.h"
#include "main.h"

void Task1_LED(void *pvParameters){
    while(1){
        HAL_GPIO_Toogle(LED_GPIO_PORT, LED_PIN);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

}
void Task2_Sensor(void *pvParameters){
    while(1){
        int sensor_value = HAL_ADC_GetValue(&hadc1);
        if (sensor_value > 1000) {
            HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
void Task3_Button(void *pvParemeter){
    while(1) {
        if (HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin) == GPIO_PIN_SET) {
            // Thay đổi chu kỳ LED
        }
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

int main(void) {
    HAL_init();
    SystemClock_Config();
    xTaskCreate(Task1_LED, "LED", 128, NULL, 1, NULL);
    xTaskCreate(Task2_Sensor, "Sensor", 128, NULL, 1, NULL);
    xTaskCreate(Task3_Button, "Button", 128, NULL, 1, NULL);
    vTaskStartScheduler();
    while (1) {}
}