/*
** EPITECH PROJECT, 2020
** Task01
** File description:
** alphabeen minuscule
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;
    
    while (str[i] != 0) {
        my_putchar(str[i]);
        i = i + 1;
    }
}
