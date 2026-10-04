#include <stdio.h>
#include "status.h"

void print_status(status_t status)
{
    printf("Heat: %u\n", status.heat);
    printf("Cool: %u\n", status.cool);
    printf("Fan: %u\n", status.fan);
    printf("Fault: %u\n", status.fault);
    printf("Mode: %u\n", status.mode);
    printf("Reserved: %u\n", status.reserved);
    printf("setpoint: %d\n", status.setpoint);
}

int main(void)
{
    printf("Normal example: \n");
    print_status(status_unpack(0x1631));

    printf("\nNegative setpoint: \n");
    print_status(status_unpack(0xFB00));
    
    printf("\nInvalid mode:\n"),
    print_status(status_unpack(0x1671));

    return 0;
}