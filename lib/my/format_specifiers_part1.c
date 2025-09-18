/*
** EPITECH PROJECT, 2022
** format_specifiers_part1
** File description:
** Format specifiers functions part 1 (%d, %i, %s, %c, %%)
*/

#include "my.h"

void handle_int(va_list list, flag_char_t *element)
{
    int arg = va_arg(list, int);
    if (arg > 0 && element->space_flag == 1){
        my_putchar(32);
    }
    my_put_nbr(arg);
}

void handle_uint(va_list list, flag_char_t *element)
{
    int arg = va_arg(list, unsigned int);
    if (arg >= 0){
        my_put_nbr(arg);
    }
}

void handle_str(va_list list, flag_char_t *element)
{
    my_putstr(va_arg(list, char*));
}

void handle_char(va_list list, flag_char_t *element)
{
    my_putchar(va_arg(list, int));
}
