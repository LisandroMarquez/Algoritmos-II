/*
  @file weather_utils.c
  @brief Defines main program function
*/

#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "weather_table.h"

/** @brief Obtener temperatura mínima en general.*/ 
int minTemperature(WeatherTable a);

/** @brief Obtener temperatura maxima por anio.*/
int maxTemYear(WeatherTable a, int year);

/** @brief Obtener un arreglo con la temperatura maxima en una lista por anio.*/
void maxTempYearArray(WeatherTable a, int out[]);

/** @brief Obtener la cantidad maxima de precipitacion por anio.*/
unsigned int maxPrepMonth(WeatherTable a, int year, int month);

/** @brief Obtener un arreglo con la cantidad maxima de precipitacion en una lista por anio.*/
void maxPrepMonthArray(WeatherTable a, int out[]);

#endif // _WEATHER_UTILS_H