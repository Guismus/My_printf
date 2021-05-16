/*
** EPITECH PROJECT, 2020
** Task01
** File description:
** alphabeen minuscule
*/

int my_get_nbr(char *str)
{
    int nb = 0;
    int i = 0;
    int a = 1;
    while (str[i]) {
        i = i + 1;
        a = a * 10;
    }
    i = 0;
    a = a / 10;
    while (str[i]) {
        nb = nb + (str[i] - 48) * a;
        i = i + 1;
        a = a / 10;
    }
    return (nb);
}
