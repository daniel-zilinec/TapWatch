/*
 * time.c
 *
 *  Created on: Aug 31, 2021
 *      Author: hello
 */

#include <clock.h>
#include "rtc.h"


/**
 * @brief read time and date from RTC and store it in time.h structure
 */
struct tm time_get()
{
	struct tm time;

	RTC_TimeTypeDef rtc_time = {0};
	RTC_DateTypeDef rtc_date = {0};

	HAL_RTC_GetTime(&hrtc, &rtc_time, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &rtc_date, RTC_FORMAT_BIN);

	time.tm_hour = rtc_time.Hours;
	time.tm_min = rtc_time.Minutes;
	time.tm_sec = rtc_time.Seconds;

	time.tm_year = rtc_date.Year + 2000;
	time.tm_mon = rtc_date.Month;
	time.tm_mday = rtc_date.Date;

	return time;
}
