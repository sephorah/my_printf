/*
** EPITECH PROJECT, 2022
** format_specifiers_part4.c
** File description:
** format specifiers functions
*/

#include "my.h"

void handle_percentage(va_list list, flag_char_t *element)
{
    my_putchar('%');
}

void handle_uppercase_e(va_list list, flag_char_t *element)
{
    double nb = va_arg(list, double);
    double res;
    int	precision = 6;
    int exponant = 0;
    if ((int)nb == 0){
        res = process_neg_nb(nb, &exponant);
        display_digits(res, precision, &exponant);
    } else {
        res = process_pos_nb(nb, &exponant);
        display_digits(res, precision, &exponant);
    }
    display_exponant('E', exponant);
}
