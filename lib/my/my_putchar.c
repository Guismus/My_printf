/*
** EPITECH PROJECT, 2020
** Task03
** File description:
** fois jusqun
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}
