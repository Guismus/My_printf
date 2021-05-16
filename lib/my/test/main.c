#include <stdio.h>

int my_printf (char *str, ...);

int main(void)
{
    my_printf("%d", 256);
    my_printf("\t123%d123", 256);
    my_printf("\t%s", "test");
    my_printf("\t123%c123", 'a');
    my_printf("\t%f", 10.2);
    my_printf("\t//");
//------------------------------------------------------//
    printf("\n");
//------------------------------------------------------//
    printf("%d", 256);
    printf("\t123%d123", 256);
    printf("\t%s", "test");
    printf("\t123%c123", 'a');
    printf("\t%f", 10.2);
    printf("\t//");
//------------------------------------------------------//
    printf("\n");
}
