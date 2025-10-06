#include "coord_format.h"
#include <stdio.h>
#include <string.h>
#include <cassert>

void test_deg_to_nmea() {
    // Test cases for latitude
    assert(strcmp(deg_to_nmea(34052230, true), "3403.13N") == 0);
    assert(strcmp(deg_to_nmea(-34052230, true), "3403.13S") == 0);

    // Test cases for longitude
    assert(strcmp(deg_to_nmea(118243680, false), "11814.62E") == 0);
    assert(strcmp(deg_to_nmea(-118243680, false), "11814.62W") == 0);

    // Edge cases
    assert(strcmp(deg_to_nmea(0, true), "0000.00N") == 0);
    assert(strcmp(deg_to_nmea(0, false), "00000.00E") == 0);
    assert(strcmp(deg_to_nmea(90000000, true), "9000.00N") == 0);
    assert(strcmp(deg_to_nmea(-90000000, true), "9000.00S") == 0);
    assert(strcmp(deg_to_nmea(180000000, false), "18000.00E") == 0);
    assert(strcmp(deg_to_nmea(-180000000, false), "18000.00W") == 0);
}

int main() {
    printf("Running tests...\n");
    test_deg_to_nmea();
    printf("Tests passed!\n");
    return 0;
}