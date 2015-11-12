#ifndef _INKSMALLFROG_UTIL_RELEASE_
#define _INKSMALLFROG_UTIL_RELEASE_

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) if((p) != NULL){delete (p); (p) = NULL;}
#endif

#endif
