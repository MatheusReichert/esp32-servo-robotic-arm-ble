#include "Servo.h"

 

static inline uint32_t angle_to_duty(int angle)
{
    return (angle + SERVO_MAX_DEGREE) * (SERVO_MAX_PULSEWIDTH_US - SERVO_MIN_PULSEWIDTH_US) / (2 * SERVO_MAX_DEGREE) + SERVO_MIN_PULSEWIDTH_US;
}

static inline uint32_t duty_to_angle(int duty)
{
    return  ((duty -  SERVO_MIN_PULSEWIDTH_US) * (2 * SERVO_MAX_DEGREE))/ (SERVO_MAX_PULSEWIDTH_US - SERVO_MIN_PULSEWIDTH_US)  - SERVO_MAX_DEGREE;  
}

void initServoUmInit(){
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, SERVO_UM); 

    mcpwm_config_t pwm_config = {
        .frequency = 50, // frequency do servo
        .cmpr_a = 0,   
        .counter_mode = MCPWM_UP_COUNTER,
        .duty_mode = MCPWM_DUTY_MODE_0,
    };
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);
}

void servoUmWrite(int angle){
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, angle_to_duty(angle));
    vTaskDelay(pdMS_TO_TICKS(100)); //Delay tempo rotação servo
}

uint32_t servoUmRead(){
    return duty_to_angle(mcpwm_get_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A));
}

void initServoDoisInit(){
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, SERVO_DOIS); 

    mcpwm_config_t pwm_config = {
        .frequency = 50, // frequency do servo
        .cmpr_a = 0,   
        .counter_mode = MCPWM_UP_COUNTER,
        .duty_mode = MCPWM_DUTY_MODE_0,
    };
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);
}

void servoDoisWrite(int angle){
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, angle_to_duty(angle));
    vTaskDelay(pdMS_TO_TICKS(100)); //Delay tempo rotação servo
}

uint32_t servoDoisRead(){
    return duty_to_angle(mcpwm_get_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A));
}

void initServoTresInit(){
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, SERVO_TRES); 

    mcpwm_config_t pwm_config = {
        .frequency = 50, // frequency do servo
        .cmpr_a = 0,   
        .counter_mode = MCPWM_UP_COUNTER,
        .duty_mode = MCPWM_DUTY_MODE_0,
    };
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);
}

void servoTresWrite(int angle){
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, angle_to_duty(angle));
    vTaskDelay(pdMS_TO_TICKS(100)); //Delay tempo rotação servo
}

uint32_t servoTresRead(){
    return duty_to_angle(mcpwm_get_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A));
}

void initServoQuatroInit(){
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, SERVO_QUATRO); 

    mcpwm_config_t pwm_config = {
        .frequency = 50, // frequency do servo
        .cmpr_a = 0,   
        .counter_mode = MCPWM_UP_COUNTER,
        .duty_mode = MCPWM_DUTY_MODE_0,
    };
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);
}

void servoQuatroWrite(int angle){
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, angle_to_duty(angle));
    vTaskDelay(pdMS_TO_TICKS(100)); //Delay tempo rotação servo
}

uint32_t servoQuatroRead(){
    return duty_to_angle(mcpwm_get_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A));
}