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
char *my_revstr(char *str);
int my_intlen(int nb);
int my_strlen(char const *str);
int pourcent_str2(char *str, int i, va_list ap, int space);
int my_printf (char *str, ...);

void make_0(char c)
{
    if (c < 10)
        my_printf("\\00%d", c);
    else if (c < 100)
        my_printf("\\0%d", c);
    else
        my_printf("\\%d", c);
}

void is_string2(va_list ap, int n)
{
    char *str = va_arg(ap, char*);
    int i = 0;
    n = n - my_strlen(str);
    if (n < 0)
        n = 0;
    while (n > 0) {
        my_putchar(' ');
        n = n - 1;
    }
    while (str[i] != 0) {
        if (str[i] < 32 || str[i] == 127) {
            make_0(str[i]);
            i = i + 1;
        } else {
        my_putchar(str[i]);
        i = i + 1;
        }
    }
}

void is_unsigned(va_list ap, int n)
{
    unsigned int nbr = va_arg(ap, int);
    int i = my_intlen(nbr);
    n = n - i;
    if (n < 0)
        n = 0;
    while (n > 0) {
    my_putchar(' ');
    n = n - 1;
    }
    my_put_nbr(nbr);
}

void is_octal(va_list ap, int n)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *str = malloc(sizeof(char) * 500);
    int i = 0;
    while (nb != 0) {
        str[i] = nb % 8 + 48;
        i = i + 1;
        nb = nb / 8;
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

int pourcent_str3(char *str, int i, va_list ap, int space)
{
    if (str[i] == 'S') {
        is_string2(ap, space);
    return (i + 1);
    }
    if (str[i] == 'u') {
        is_unsigned(ap, space);
    return (i + 1);
    }
    if (str[i] == 'o') {
        is_octal(ap, space);
    return (i + 1);
    }
    while (space > 0) {
        my_putchar(' ');
        space = space - 1;
    }
    return (i);
}
