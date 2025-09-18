/*
** EPITECH PROJECT, 2022
** handle_e_functions.c
** File description:
** functions for %e
*/

#include "my.h"

double my_round_float(double *nb, int precision, int *exponant)
{
    int i = 1;
    int p = 1;
    int digit1;
    int digit2;
    int diff;
    digit1 = (int)(*nb * my_pow_10(precision)) % 10;
    digit2 = (int)(*nb * my_pow_10(precision + 1)) % 10;
    if (digit2 >= 5 && digit2 <= 9){
        *nb += my_pow_10_neg(precision);
    }
    if ((int)*nb >= 10){
        *nb = *nb / 10;
        *exponant += 1;
    }
}

double my_pow_10_neg(int power)
{
    int i = 0;
    double result = 1;
    while (i < power){
        result /= 10;
        i += 1;
    }
    return result;
}

void display_exponant(char letter, int exponant)
{
    my_putchar(letter);
    if (exponant <= 9 && exponant >= 0){
        my_putchar('+');
        my_put_nbr(0);
    } else if (exponant <= 0 && exponant >= -9){
        my_putchar('-');
        my_put_nbr(0);
    }
    my_put_nbr(ABS(exponant));
}
