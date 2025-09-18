/*
** EPITECH PROJECT, 2022
** format_specifiers_part2.c
** File description:
** format_specifiers_part2
*/

#include "my.h"

void handle_octal(va_list list, flag_char_t *element)
{
    int arg = va_arg(list, unsigned int);
    my_putnbr_base(arg, "01234567");
}

void handle_x(va_list list, flag_char_t *element)
{
    int arg = va_arg(list, unsigned int);
    my_putnbr_base(arg, "0123456789abcdef");
}

void handle_uppercase_x(va_list list, flag_char_t *element)
{
    int arg = va_arg(list, unsigned int);
    my_putnbr_base(arg, "0123456789ABCDEF");
}

void handle_bin(va_list list, flag_char_t *element)
{
    int arg = va_arg(list, unsigned int);
    my_putnbr_base(arg, "01");
}
