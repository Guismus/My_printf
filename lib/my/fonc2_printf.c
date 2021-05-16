/*
** EPITECH PROJECT, 2020
** eval_expr
** File description:
** ecvghbjn
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void my_putchar(char);
void my_putstr(char *);
int my_put_nbr(int nb);
int my_get_nbr(char *str);
int my_strlen_nbr(char const *str, int i);
int my_intlen(int nb);
int my_strlen(char const *str);
int pourcent_str3(char *str, int i, va_list ap, int space);

char *my_revstr(char *str)
{
    int i = 0;
    int n = 0;
    int m = 0;
    char* temp = malloc(sizeof(char) * (my_strlen(str) + 1));
    
    while (str[i] != 0) 
        i = i + 1;
    i = i - 1;
    while (i >= 0) {
        temp[n] = str[i];
        n = n + 1;
        i = i - 1;
    }
    temp[n] = '\0';
    while (temp[m] != 0) {
        str[m] = temp[m];
        m = m + 1;
    }
    str[m] = temp[m];
    return (str);
}

void is_binary(va_list ap, int n)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int c = 0;
    char *str = malloc(sizeof(char) * 500);
    int i = 0;
    while (nb > 0) {
        if (nb / 2 * 2 == nb)
            c = 0;
        if (nb / 2 * 2 != nb)
            c = 1;
        nb = nb / 2;
        str[i] = c + 48;
        i = i + 1;
    }
    while (n > i) {
        my_putchar(' ');
        n = n - 1;
    }
    str[i] = 0;
    my_revstr(str);
    my_putstr(str);
    free(str);
}

void is_pourcent(va_list ap, int n)
{
    while (n > 1) {
        my_putchar(' ');
        n = n - 1;
    }
    my_putchar('%');
}

void is_float(va_list ap, int n)
{
    double nbr = 0;
    int i = 0;

    nbr = va_arg(ap, double);
    int nb = nbr * 1000000;
    i = my_intlen(nb) + 1;
    n = n - i;
    if (n < 0)
        n = 0;
    while (n > 0) {
        my_putchar(' ');
        n = n - 1;
    }
    my_put_nbr(nb / 1000000);
    my_putchar('.');
    my_put_nbr(nb % 1000000);
}

int pourcent_str2(char *str, int i, va_list ap, int space)
{
    if (str[i] == '%') {
        is_pourcent(ap, space);
    return (i + 1);
    }
    if (str[i] == 'f') {
        is_float(ap, space);
    return (i + 1);
    }
    if (str[i] == 'b') {
        is_binary(ap, space);
    return (i + 1);
    }
    pourcent_str3(str, i, ap, space);
}
