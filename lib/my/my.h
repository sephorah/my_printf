/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Day 09 - Task 02 - my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <stdarg.h>
    #define ABS(x) (((x) > 0) ? (x) : ((x) * (-1)))
typedef struct flag_character{
    int plus_flag;
    int space_flag;
    int hyphen_flag;
    int zero_flag;
    int hashtag_flag;
} flag_char_t;
typedef void (*handle_conversion)(va_list, flag_char_t*);
typedef struct handle_function{
    char flag_conv;
    flag_char_t flags_char;
    handle_conversion fptr;
} handle_funct;
    void my_putchar(char c);
    int my_put_nbr(int nb);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    long int my_pow_10(int power);
    int nb_len(int nb);
    int nb_isneg(int *nb);
void handle_int(va_list list, flag_char_t *element);
void handle_str(va_list list, flag_char_t *element);
void handle_char(va_list list, flag_char_t *element);
void handle_octal(va_list list, flag_char_t *element);
void handle_x(va_list list, flag_char_t *element);
void handle_uppercase_x(va_list list, flag_char_t *element);
void handle_bin(va_list list, flag_char_t *element);
void handle_uint(va_list list, flag_char_t *element);
void handle_p(va_list list, flag_char_t *element);
void handle_percentage(va_list list, flag_char_t *element);
void handle_e(va_list list, flag_char_t *element);
void handle_uppercase_e(va_list list, flag_char_t *element);
double my_pow_10_neg(int power);
void display_exponant(char letter, int exponant);
double my_round_float(double *nb, int precision, int *exponant);
int display_digits(double nb, int precision, int *exponant);
double process_neg_nb(double nb, int *exponant);
double process_pos_nb(double nb, int *exponant);
    int my_putnbr_base(unsigned long long nbr, char const *base);
    int my_printf(const char *restrict format, ...);
#endif
