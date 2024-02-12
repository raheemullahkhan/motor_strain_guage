#include<motor_control.h>
#include <Arduino.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<strain_guage.h>

bool direction = false;

void motor_init() {
    pinMode(DIRECTION_PIN, OUTPUT);
    pinMode(ENABLE_PIN, OUTPUT);
    pinMode(PULSE_PIN, OUTPUT);
    digitalWrite(DIRECTION_PIN, HIGH);  // Assuming HIGH is the initial direction
}

void enable_motor() {
    digitalWrite(ENABLE_PIN, HIGH);
}

void disable_motor() {
    digitalWrite(ENABLE_PIN, LOW);
}

void generate_steps(int number_of_steps, int pulseDuration) {
    for (int i = 0; i < number_of_steps * pulse_in_one_step; ++i) {
        digitalWrite(PULSE_PIN, HIGH);
        delayMicroseconds(pulseDuration);
        digitalWrite(PULSE_PIN, LOW);
        delayMicroseconds(pulseDuration);
    }
 Serial.println(read_strain_guage());
}

void changeDirection() {
    direction = !direction;
    digitalWrite(DIRECTION_PIN, direction);  // Toggle direction
}

void set_down_direction() {
    digitalWrite(DIRECTION_PIN, LOW);
}

void set_up_direction() {
    digitalWrite(DIRECTION_PIN, HIGH);
}
