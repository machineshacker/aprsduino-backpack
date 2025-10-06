#ifndef COORD_FORMAT_H
#define COORD_FORMAT_H

// Required for boolean type
#include <stdbool.h>

// Size of the conversion buffer
#define CONV_BUF_SIZE 16

// Declaration of the conversion function
char* deg_to_nmea(long deg, bool is_lat);

#endif // COORD_FORMAT_H