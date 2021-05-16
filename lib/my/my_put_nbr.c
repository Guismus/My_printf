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
int my_printf (char *str, ...);

int my_put_nbr(int nb)
{
    if (nb == -1234567890) {
        write(1, "-1234567890", 1);
        return (0);
    }
    if (nb < 0) {
        nb = -nb;
        write (1, "-", 1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(nb + '0');
    return (0);
}

int my_put_float(int nb)
{
    if (nb < 0) {
        nb = -nb;
        write (1, "-", 1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(nb + '0');
    return (0);
}