#ifndef _INKSMALLFROG_MATH3D_UTIL_
#define  _INKSMALLFROG_MATH3D_UTIL_

#include <cmath>

#ifndef PI
#define PI 3.14159
#endif

#ifndef PI_DEGREE
#define PI_DEGREE 180
#endif

#ifndef DEGREE_TO_RADIO
#define DEGREE_TO_RADIO(a) ((a) / PI_DEGREE * PI)
#endif

#ifndef RADIO_TO_DEGREE
#define RADIO_TO_DEGREE(a) ((a) / PI * PI_DEGREE)
#endif

#endif
