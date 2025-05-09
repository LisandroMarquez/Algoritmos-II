/*
  @file weather_table.h
  @brief defines table helpers methods. These methods operates over multidimensional (year, month, day) array of weather
*/
#ifndef _STRFUNCS_H
#define _STRFUNCS_H

#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Devuelve la longitud de la cadena apuntada por str
 * @param[in] str la cadena en cuestión
 */
size_t string_length(const char *str);


/**
 * @brief Devuelve una nueva cadena en memoria dinámica que se obtiene
 *        tomando los caracteres de str que son distintos del caracter c
 * @param[in] str la cadena en cuestión,
 * @param[in] c el caracter a eliminar de la cadena 'str'
 */
char *string_filter(const char *str, char c);

/**
 * @brief Devuelve si la cadena apuntada por str es simétrica en cuanto que
 * el primer caracter coincide con el último, el segundo con el penúltimo, etc.
 * @param[in] str la cadena en cuestión
 */
bool string_is_symmetric(const char *str);

#endif // _STRFUNCS_H