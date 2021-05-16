/*
** EPITECH PROJECT, 2020
** Task01
** File description:
** ahabeten minscule
*/

int my_strlen(char const *str)
{
    int i = 0;
    int j = 0;
    while (str[i] != 0) {
        i = i + 1;
    }
    return (i);
}
