#include<motor_control.h>
#include <Arduino.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<strain_guage.h>

bool direction = 0;



static void real_move_one_step(int pulseDuration)
{
        for (int i = 0; i < pulse_in_one_step; ++i) 
    {
        digitalWrite(Real_pulse_pin, HIGH);
         delayMicroseconds (pulseDuration);
        digitalWrite(Real_pulse_pin, LOW);
        delayMicroseconds(pulseDuration);
    }
}
static void imagnary_move_one_step(int pulseDuration)
{
    for (int i = 0; i < pulse_in_one_step; ++i) 
    {
        digitalWrite(imagnary_pulse_pin, HIGH);
        delayMicroseconds(pulseDuration);
        digitalWrite(imagnary_pulse_pin, LOW);
        delayMicroseconds(pulseDuration);
    }
}

void generate_steps(int number_of_steps, int pulseDuration) {
   for(int j=0;j<number_of_steps;j++)
   {
    if(object_detected_between_extremes())
     { 
        imagnary_move_one_step(pulseDuration);
      
     }
   
   
    else
      {
        real_move_one_step(pulseDuration);
        
      }
   
   

   }
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
void motor_init() {
    pinMode(DIRECTION_PIN, OUTPUT);
    pinMode(ENABLE_PIN, OUTPUT);
    pinMode(Real_pulse_pin, OUTPUT);
    digitalWrite(DIRECTION_PIN, HIGH);  // Assuming HIGH is the initial direction
}
void enable_motor() {
    digitalWrite(ENABLE_PIN, HIGH);
}
void disable_motor() {
    digitalWrite(ENABLE_PIN, LOW);
}