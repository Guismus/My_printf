/*
** EPITECH PROJECT, 2020
** Task01
** File description:
** alphabeen minuscule
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char);
void my_putstr(char *);
void is_number(va_list ap);
void is_string(va_list ap);
void is_char(va_list ap);
int pourcent_str(char *str, int i, va_list ap);

int my_printf (char *str, ...)
{
    int i = 0;
    va_list ap;
    
    va_start(ap, str);
    while (str[i]) {
        if (str[i] == '%')
            i = pourcent_str(str, i + 1, ap);
        else {
            my_putchar(str[i]);
            i = i + 1;
        }
    }
    va_end(ap);
}
