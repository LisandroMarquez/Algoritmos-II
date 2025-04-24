/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/

#include "queries.h"

/**
 * @brief Total de lluvias de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
int year_rainfall(WeatherTable a, int year) {
    int total = 0;
    for (int i = 0; i < MONTHS; i++)
    {
      for (int j = 0; j < DAYS; j++)
      {
        total += a[year-FST_YEAR][i][j]._rainfall;
      }
      
    }
    return total;
}
