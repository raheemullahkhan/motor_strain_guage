
#include "motor_control.h"
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <strain_guage.h>
#define STACK_SIZE 2048
#define DELAY_MS 1000

void task1(void *pulse_duration) {

        int duration=5;
    while (1) {
        generate_steps(64, duration);
        changeDirection();
        
        generate_steps(64, duration);
        changeDirection(); 
        
    }
}

void task2(void *parameter) {
  while (true) {
    Serial.println("Task 2 is running");
    vTaskDelay(pdMS_TO_TICKS(DELAY_MS));
  }
}

void setup() {
  Serial.begin(115200);
      motor_init();
    enable_motor();
    set_up_direction();
    initialize_strian_guage();

  
  xTaskCreatePinnedToCore(task1, "Task1", STACK_SIZE, NULL, 1, NULL, 1);  // Run task1 on core 1
  xTaskCreate(task2, "Task2", STACK_SIZE, NULL, 1, NULL);
}

void loop() {
  // Nothing to do here, tasks run independently
}
