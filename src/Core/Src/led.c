/*
 * led.c
 *
 *  Created on: Aug 31, 2021
 *      Author: hello
 */


#include "led.h"
#include "cmsis_os.h"

/**
 * @brief Blink given times with pre-defined color
 * @param num number of blinks
 * @param color color enum
 */
void led_blink_count(uint8_t num, enum color_e color)
{
	for (uint8_t i = 0; i < num; ++i)
	{
		led_set_color(color);
		osDelay(BLINK_DELAY);
		led_set_color(BLACK);
		osDelay(BLINK_DELAY);
	}
}


/**
 * @brief Set pre-defined color
 * @param color color enum
 */
void led_set_color(enum color_e color)
{
	switch (color)
	{
		case BLACK:
			led_set_rgb(0, 0, 0);
			break;

		case RED:
			led_set_rgb(1, 0, 0);
			break;

		case GREEN:
			led_set_rgb(0, 1, 0);
			break;

		case BLUE:
			led_set_rgb(0, 0, 1);
			break;

		case PURPLE:
			led_set_rgb(1, 0, 1);
			break;


	}
}

/**
 * @brief Enable/disable LEDs (0 - disabled)
 * @param red red LED
 * @param green green LED
 * @param blue blue LED
 * @retval none
 */
void led_set_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	// LD3 - red
	// LD2 - green
	// LD1 - blue

	if (red)
	{
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
	}

	if (green)
	{
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	}

	if (blue)
	{
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
	}
}
