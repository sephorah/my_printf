/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** Day 04 - Task 02 - my_putstr
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    while (*str != '\0'){
        my_putchar(*str);
        str += 1;
    }
    return 0;
}
