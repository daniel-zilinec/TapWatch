/*
 * led.h
 *
 *  Created on: Aug 31, 2021
 *      Author: hello
 */

#ifndef SRC_LED_H_
#define SRC_LED_H_

#include "main.h"

#define BLINK_DELAY		200		// [ms]

enum color_e
{
	BLACK,
	RED,
	GREEN,
	BLUE,
	PURPLE
};

void led_set_rgb(uint8_t red, uint8_t green, uint8_t blue);
void led_set_color(enum color_e color);
void led_blink_count(uint8_t num, enum color_e color);

#endif /* SRC_LED_H_ */
