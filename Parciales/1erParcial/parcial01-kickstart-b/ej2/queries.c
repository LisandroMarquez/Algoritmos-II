/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/

#include "queries.h"

/**
 * @brief Máxima temperatura de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
int year_max_temp(WeatherTable a, int year) {
  int temp = -276447231;
    for (int j = 0; j < MONTHS; j++) {
        for (int k = 0; k < DAYS; k++) {
            if (a[year-FST_YEAR][j][k]._max_temp > temp) {
                temp = a[year-FST_YEAR][j][k]._max_temp;
            }
        }
    }
    return temp;
}
