/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "weather_table.h"
#include "weather_utils.h"

int minTemperature(WeatherTable a) {
    int temp = 276447231;
    for (int i = 0; i < YEARS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            for (int k = 0; k < DAYS; k++) {
                if (a[i][j][k]._min_temp < temp) {
                    temp = a[i][j][k]._min_temp;
                }
            }
        }
    }
    return temp;
}

int maxTempYear(WeatherTable a, int year) {
    int temp = -276447231;
    for (int j = 0; j < MONTHS; j++) {
        for (int k = 0; k < DAYS; k++) {
            if (a[year][j][k]._max_temp > temp) {
                temp = a[year][j][k]._max_temp;
            }
        }
    }
    return temp;
}

void maxTempYearArray(WeatherTable a, int out[]) {
    int temperature;
    for (int i = 0; i < YEARS; i++) {
        temperature = maxTempYear(a, i);
        out[i] = temperature;
    }
}

unsigned int maxPrepMonth(WeatherTable a, int year, int month) {
    unsigned int total = 0;
        for (int k = 0; k < DAYS; k++) {
            total += a[year][month][k]._rainfall;
        }
    return total;
}

void maxPrepMonthArray(WeatherTable a, int out[]) {
    int month;
    unsigned int aux, prep = 0;
    for (int i = 0; i < YEARS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            aux = maxPrepMonth(a, i, j);
            if (prep < aux) {
                prep = aux;
                month = j+1;
            }
        }
        out[i] = month;
        prep = 0;
    }
}