/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_printf
*/

#include "my.h"

void add_flags_char(flag_char_t *element, char flag_ch)
{
    switch (flag_ch){
    case ' ':
        element->space_flag = 1;
        break;
    default:
        break;
    }
}

int detect_flag_conv(handle_funct *arr, char flag_ch, char input, va_list l)
{
    int len = 13;
    char flag_conver;
    for (int i = 0; i < len; i += 1){
        flag_conver = arr[i].flag_conv;
        if (input == flag_conver){
            add_flags_char(&arr[i].flags_char, flag_ch);
            arr[i].fptr(l, &arr[i].flags_char);
            break;
        }
    }
}

char detect_flag_char(handle_funct *arr, const char *format, int *i)
{
    int len = 13;
    char flag_char = format[*i];
    char flag_conver;
    for (int i = 0; i < 13; i += 1){
        flag_conver = arr[i].flag_conv;
        if (flag_char == flag_conver){
            return flag_char;
        }
    }
    while (format[*i] == flag_char){
        *i += 1;
    }
    flag_char = format[*i - 1];
    return flag_char;
}

void disp_arg(va_list list, const char *format, int *i)
{
    char flag_char;
    int array_len = 13;
    flag_char_t fc_arr[] = {
        {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0},
        {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0},
        {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0},
        {0,0,0,0,0} };
    handle_funct handle_func_arr[] = {
        {'d', fc_arr[0], handle_int}, {'i', fc_arr[1], handle_int},
        {'o', fc_arr[2], handle_octal}, {'s', fc_arr[3], handle_str},
        {'c', fc_arr[4], handle_char}, {'%', fc_arr[5], handle_percentage},
        {'u', fc_arr[6], handle_uint}, {'x', fc_arr[7], handle_x},
        {'X', fc_arr[8], handle_uppercase_x}, {'b', fc_arr[9], handle_bin},
        {'p', fc_arr[10], handle_p}, {'e', fc_arr[11], handle_e},
        {'E', fc_arr[12], handle_uppercase_e}
    };
    flag_char = detect_flag_char(handle_func_arr, format, i);
    detect_flag_conv(handle_func_arr, flag_char, format[*i], list);
}

int my_printf(const char *restrict format, ...)
{
    va_list list;
    int i = 0;
    va_start(list, format);
    while (format[i] != '\0'){
        if (format[i] == '%'){
            i += 1;
            disp_arg(list, format, &i);
        } else {
            my_putchar(format[i]);
        }
        i += 1;
    }
    va_end(list);
    return 0;
}
