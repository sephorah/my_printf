/*
** EPITECH PROJECT, 2022
** format_specifiers_part3
** File description:
** myprintf
*/

#include "my.h"

int display_digits(double nb, int precision, int *exponant)
{
    int i = 1;
    int p = 1;
    int digit;

    my_round_float(&nb, precision, exponant);
    my_put_nbr((int)nb);
    my_putchar('.');
    while (i <= precision){
        p = p * 10;
        digit = (int)(nb * p) % 10;
        if ((int)digit >= 0 && (int)digit <= 9){
            my_put_nbr(digit);
        } else {
            my_put_nbr(0);
        }
        i += 1;
    }
}

double process_neg_nb(double nb, int *exponant)
{
    while ((int)nb == 0){
        nb = nb * 10;
        *exponant -= 1;
    }
    return nb;
}

double process_pos_nb(double nb, int *exponant)
{
    while ((int)nb >= 10){
        nb = nb / 10;
        *exponant += 1;
    }
    return nb;
}

void handle_e(va_list list, flag_char_t *element)
{
    double nb = va_arg(list, double);
    double res;
    int precision = 6;
    int exponant = 0;
    if ((int)nb == 0){
        res = process_neg_nb(nb, &exponant);
        display_digits(res, precision, &exponant);
    } else {
        res = process_pos_nb(nb, &exponant);
        display_digits(res, precision, &exponant);
    }
    display_exponant('e', exponant);
}

void handle_p(va_list list, flag_char_t *element)
{
    unsigned long long arg = va_arg(list, unsigned long long);
    my_putstr("0x");
    my_putnbr_base(arg, "0123456789abcdef");
}
