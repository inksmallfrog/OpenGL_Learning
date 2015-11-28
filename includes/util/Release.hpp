#ifndef _INKSMALLFROG_UTIL_RELEASE_
#define _INKSMALLFROG_UTIL_RELEASE_

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) if((p) != NULL){delete (p); (p) = NULL;}
#endif

#ifndef ARRAY_LENGTH
#define ARRAY_LENGTH(array) sizeof(array) / sizeof(array[0])
#endif

#ifndef ZERO_MEMORY
#define ZERO_MEMORY(array) for(int i = 0; i < ARRAY_LENGTH(array); ++i){array[i] = 0;}

#endif
