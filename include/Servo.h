#ifndef SERVO_H
#define SERVO_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/mcpwm.h"


#define SERVO_MIN_PULSEWIDTH_US (500) // Largura de pulso minima em micro segundos
#define SERVO_MAX_PULSEWIDTH_US (2500) // Largura de pulso maxima do servo  em micro segundos
#define SERVO_MAX_DEGREE        (180)   // Angulo max

#define SERVO_UM GPIO_NUM_15
#define SERVO_DOIS GPIO_NUM_23   
#define SERVO_TRES GPIO_NUM_34   
#define SERVO_QUATRO GPIO_NUM_17     

int servoUmPos;
int servoDoisPos;
int servoTresPos;
int servoQuatroPos;

void initServoUmInit();
void initServoDoisInit();
void initServoTresInit();
void initServoQuatroInit();

void servoUmWrite(int angle);
void servoDoisWrite(int angle);
void servoTresWrite(int angle);
void servoQuatroWrite(int angle);

uint32_t servoUmRead();
uint32_t servoDoisRead();
uint32_t servoTresRead();
uint32_t servoQuatroRead();



#endif