/*
** EPITECH PROJECT, 2020
** eval_expr
** File description:
** ecvghbjn
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char);
void my_putstr(char *);
int my_put_nbr(int nb);
int my_get_nbr(char *str);
int my_strlen_nbr(char const *str, int i);
int my_intlen(int nb);
int my_strlen(char const *str);
int pourcent_str2(char *str, int i, va_list ap, int space);

void is_number(va_list ap, int n)
{
    int nbr = 0;
    int i = 0;

    nbr = va_arg(ap, int);
    i = my_intlen(nbr);
    n = n - i;
    if (n < 0)
        n = 0;
    while (n > 0) {
    my_putchar(' ');
    n = n - 1;
    }
    my_put_nbr(nbr);
}

void is_string(va_list ap, int n)
{
    char *string = va_arg(ap, char*);
    n = n - my_strlen(string);
    if (n < 0)
        n = 0;
    while (n > 0) {
    my_putchar(' ');
    n = n - 1;
    }
    my_putstr(string);
}

void is_char(va_list ap, int n)
{
    int a;

    while (n > 1) {
        my_putchar(' ');
        n = n - 1;
    }
    a = va_arg(ap, int);
    my_putchar(a);
}

int space_str(char *str, int i)
{
    int n = 0;
    char* space = malloc(sizeof(char) * my_strlen_nbr(str, i));

    while (str[i] >= '0' && str[i] <= '9') {
        space[n] = str[i];
        i = i + 1;
        n = n + 1;
    }
    if (n != 0) {
        space[n] = '\0';
        n = my_get_nbr(space);
    }
    free(space);
    return (n);
}

int pourcent_str(char *str, int i, va_list ap)
{
    int space = space_str(str, i);
    while (str[i] >= '0' && str[i] <= '9') {
        i = i + 1;
    }
    if (str[i] == 's') {
        is_string(ap, space);
        return (i + 1);
    }
    if (str[i] == 'c') {
        is_char(ap, space);
        return (i + 1);
    }
    if (str[i] == 'i' || str[i] == 'd') {
        is_number(ap, space);
        return (i + 1);
    }
    return (pourcent_str2(str, i, ap, space));
}
