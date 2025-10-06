#include "coord_format.h"
#include <stdio.h>
#include <stdlib.h>

// Buffer for conversions
static char conv_buf[CONV_BUF_SIZE];

/*
**  Convert degrees in long format to APRS string format
**  DDMM.hhN for latitude and DDDMM.hhW for longitude
**  D is degrees, M is minutes and h is hundredths of minutes.
**  http://www.aprs.net/vm/DOS/PROTOCOL.HTM
*/
char* deg_to_nmea(long deg, bool is_lat) {
  bool is_negative = (deg < 0);
  deg = labs(deg);

  unsigned long b = (deg % 1000000UL) * 60UL;
  unsigned long a = (deg / 1000000UL) * 100UL + b / 1000000UL;
  b = (b % 1000000UL) / 10000UL;

  if (is_lat) {
    char hemisphere = is_negative ? 'S' : 'N';
    snprintf(conv_buf, CONV_BUF_SIZE, "%04lu.%02lu%c", a, b, hemisphere);
  } else {
    char hemisphere = is_negative ? 'W' : 'E';
    snprintf(conv_buf, CONV_BUF_SIZE, "%05lu.%02lu%c", a, b, hemisphere);
  }
  return conv_buf;
}