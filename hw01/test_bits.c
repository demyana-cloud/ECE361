#include <stdio.h>
#include "bits.h"

int main(void)
{
    printf("Testing print_binary: \n");
    print_binary(0x2c, 8);
    print_binary(0xFFFFFFFF, 32);

    printf("\nTesting get_field:\n");
    printf("Normal: %u\n", get_field(0xDA, 2, 3));
    printf("Width1: %u\n", get_field(0x1, 0, 1));
    printf("Width 32: %u\n", get_field(0xFFFFFFFF, 0, 32));
    printf("Invalid width: %u\n", get_field(0xDA, 0, 33));
    printf("Invalid position: %u\n", get_field(0xDA, 32, 1));

    printf("\nTesting set_field:\n");
    print_binary(set_field(0xDA, 2, 3, 0x1), 8);
    print_binary(set_field(0x00, 0, 1,1), 8);
    print_binary(set_field(0xFFFFFFFF, 0, 32, 0), 32);

    printf("\nTesting sign_extend:\n");
    printf("positive: %d\n", sign_extend(0x5, 4));
    printf("Negative: %d\n", sign_extend(0xD, 4));
    printf("width 1 positive: %d\n", sign_extend(0x0, 1));
    printf("width 1 negative: %d\n", sign_extend(0x1, 1));
    printf("width 32: %d\n", sign_extend(0xFFFFFFFF, 32));

    return 0;
}