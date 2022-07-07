/**
* Baseando se na documentação
*   https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/mcpwm.html
*/
#include "Servo.h"

/**
 * @brief Convert angle to duty value
 *
 * @param angle
 * @return uint32_t
 */
static inline uint32_t angle_to_duty(int angle)
{
    return (angle + SERVO_MAX_DEGREE) * (SERVO_MAX_PULSEWIDTH_US - SERVO_MIN_PULSEWIDTH_US) / (2 * SERVO_MAX_DEGREE) + SERVO_MIN_PULSEWIDTH_US;
}
/**
 * @brief Convert duty to angle value
 *
 * @param duty
 * @return uint32_t
 */
static inline uint32_t duty_to_angle(int duty)
{
    return  ((duty -  SERVO_MIN_PULSEWIDTH_US) * (2 * SERVO_MAX_DEGREE))/ (SERVO_MAX_PULSEWIDTH_US - SERVO_MIN_PULSEWIDTH_US)  - SERVO_MAX_DEGREE;
}
/**
 * @brief Servo one initialization with hardware parameters
 *
 */
void initServoUm() {
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, SERVO_UM);

    mcpwm_config_t pwm_config = {
        .frequency = 50, // frequency do servo
        .cmpr_a = 0,
        .counter_mode = MCPWM_UP_COUNTER,
        .duty_mode = MCPWM_DUTY_MODE_0,
    };
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);

    servoUmPos = servoUmRead();

}
/**
 * @brief Write servo One angle
 *
 * @param angle
 */
void servoUmWrite(int angle) {
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM0A, angle_to_duty(angle));
    vTaskDelay(pdMS_TO_TICKS(100)); //Delay tempo rotação servo
}
/**
 * @brief Read servo One angle
 *
 * @return uint32_t
 */
uint32_t servoUmRead() {
    return duty_to_angle(mcpwm_get_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM0A));
}
/**
 * @brief Servo two initialization with hardware parameters
 *
 */
void initServoDois() {
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM1A, SERVO_DOIS);

    mcpwm_config_t pwm_config = {
        .frequency = 50, // frequency do servo
        .cmpr_a = 0,
        .counter_mode = MCPWM_UP_COUNTER,
        .duty_mode = MCPWM_DUTY_MODE_0,
    };
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_1, &pwm_config);
    servoDoisPos = servoDoisRead();
}
/**
 * @brief Write servo Two angle
 *
 * @param angle
 */
void servoDoisWrite(int angle) {
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM1A, angle_to_duty(angle));
    vTaskDelay(pdMS_TO_TICKS(100)); //Delay tempo rotação servo
}
/**
 * @brief Read servo Two angle
 *
 * @param angle
 */
uint32_t servoDoisRead() {
    return duty_to_angle(mcpwm_get_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM1A));
}
/**
 * @brief Servo three initialization with hardware parameters
 *
 */
void initServoTres() {
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM2A, SERVO_TRES);

    mcpwm_config_t pwm_config = {
        .frequency = 50, // frequency do servo
        .cmpr_a = 0,
        .counter_mode = MCPWM_UP_COUNTER,
        .duty_mode = MCPWM_DUTY_MODE_0,
    };
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_2, &pwm_config);
    servoTresPos = servoTresRead();
}
/**
 * @brief Write servo Three angle
 *
 * @param angle
 */
void servoTresWrite(int angle) {
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_2, MCPWM2A, angle_to_duty(angle));
    vTaskDelay(pdMS_TO_TICKS(100)); //Delay tempo rotação servo
}
/**
 * @brief Read servo Three angle
 *
 * @param angle
 */
uint32_t servoTresRead() {
    return duty_to_angle(mcpwm_get_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_2, MCPWM2A));
}
/**
 * @brief Servo four initialization with hardware parameters
 *
 */
void initServoQuatro() {
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, SERVO_QUATRO);

    mcpwm_config_t pwm_config = {
        .frequency = 50, // frequency do servo
        .cmpr_a = 0,
        .counter_mode = MCPWM_UP_COUNTER,
        .duty_mode = MCPWM_DUTY_MODE_0,
    };
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);
    servoQuatroPos = servoQuatroRead();
}
/**
 * @brief Write servo Four angle
 *
 * @param angle
 */
void servoQuatroWrite(int angle) {
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM0B, angle_to_duty(angle));
    vTaskDelay(pdMS_TO_TICKS(100)); //Delay tempo rotação servo
}
/**
 * @brief Read servo Four angle
 *
 * @param angle
 */
uint32_t servoQuatroRead() {
    return duty_to_angle(mcpwm_get_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM0B));
}