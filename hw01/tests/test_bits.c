#include <stdio.h>
#include <stdint.h>
#include "bits.h"
#include "status.h"

static int tests_run = 0;
static int tests_failed = 0;

static void check_u32(const char *name, uint32_t actual, uint32_t expected)
{
    tests_run++;

    if (actual == expected)
    {
        printf("PASS: %s\n", name);
    }
    else
    {
        printf("FAIL: %s (expected %u, got %u)\n",
               name, expected, actual);
        tests_failed++;
    }
}

static void check_i32(const char *name, int32_t actual, int32_t expected)
{
    tests_run++;

    if (actual == expected)
    {
        printf("PASS: %s\n", name);
    }
    else
    {
        printf("FAIL: %s (expected %d, got %d)\n",
               name, expected, actual);
        tests_failed++;
    }
}

int main(void)
{
    /* get_field tests */
    check_u32("get_field normal",
              get_field(0xDA, 2, 3), 6);

    check_u32("get_field width 1",
              get_field(0x1, 0, 1), 1);

    check_u32("get_field width 32",
              get_field(0xFFFFFFFF, 0, 32), 0xFFFFFFFF);

    check_u32("get_field position 31",
              get_field(0x80000000, 31, 1), 1);

    check_u32("get_field invalid width",
              get_field(0xDA, 0, 33), 0);

    check_u32("get_field invalid position",
              get_field(0xDA, 32, 1), 0);

    /* set_field tests */
    check_u32("set_field normal",
              set_field(0xDA, 2, 3, 0x1), 0xC6);

    check_u32("set_field width 1",
              set_field(0x0, 0, 1, 1), 1);

    check_u32("set_field width 32",
              set_field(0xFFFFFFFF, 0, 32, 0), 0);

    check_u32("set_field value too wide",
              set_field(0x0, 4, 3, 0xF), 0x70);

    /* sign_extend tests */
    check_i32("sign_extend positive",
              sign_extend(0x5, 4), 5);

    check_i32("sign_extend negative",
              sign_extend(0xD, 4), -3);

    check_i32("sign_extend width 1 positive",
              sign_extend(0x0, 1), 0);

    check_i32("sign_extend width 1 negative",
              sign_extend(0x1, 1), -1);

    check_i32("sign_extend width 32",
              sign_extend(0xFFFFFFFF, 32), -1);

    /* status_unpack tests */
    status_t normal = status_unpack(0x1631);

    check_u32("status heat", normal.heat, 1);
    check_u32("status cool", normal.cool, 0);
    check_u32("status fan", normal.fan, 0);
    check_u32("status fault", normal.fault, 0);
    check_u32("status mode", normal.mode, 3);
    check_u32("status reserved", normal.reserved, 0);
    check_i32("status setpoint", normal.setpoint, 22);

    status_t negative = status_unpack(0xFB00);
    check_i32("status negative setpoint",
              negative.setpoint, -5);

    status_t invalid = status_unpack(0x1671);
    check_u32("status invalid mode becomes OFF",
              invalid.mode, 0);

    printf("\nSummary: %d passed, %d failed\n",
           tests_run - tests_failed, tests_failed);

    return tests_failed == 0 ? 0 : 1;
}