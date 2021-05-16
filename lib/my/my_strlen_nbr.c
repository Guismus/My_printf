/*
** EPITECH PROJECT, 2020
** Task01
** File description:
** alphabeen minuscule
*/

int my_putchar(char c);

int my_strlen_nbr(char const *str, int i)
{    
    while (str[i] >= '0' && str[i] <= '9' && str[i])
        i = i + 1;
    return (i);
}

int my_intlen(int nb)
{
    int a = 1;
    int i = 0;
    if (nb < 0)
        i = i + 1;
    while (nb / a != 0) {
        a = a * 10;
        i = i + 1;
    }
    return (i);
}
