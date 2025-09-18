/*
** EPITECH PROJECT, 2022
** my_put_nbr_base
** File description:
** myprintf
*/

#include <stdio.h>
#include "my.h"

int my_putnbr_base(unsigned long long nbr, char const *base)
{
    int len = my_strlen(base);

    if (nbr > 0){
        my_putnbr_base(nbr / len, base);
    }

    if (nbr == 0){
        return 0;
    }
    my_putchar(base[nbr % len]);
}
