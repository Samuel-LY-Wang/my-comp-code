#include <stdio.h>

int main() {
    int count = 14;

    int *int_ptr = &count;
    printf("%i\n", int_ptr);

    int **int_ptr2 = &int_ptr;

    *int_ptr = 446;

    printf("%i\n", int_ptr);
    printf("%i\n", *int_ptr2);
    printf("%i\n", *int_ptr2+2);
}