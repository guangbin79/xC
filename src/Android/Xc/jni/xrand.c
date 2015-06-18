#include "../../../../xrand.h"
#include <stdlib.h>


void xrand_srand(xuint32_t seed)
{
	srand(seed);
}

xint32_t xrand_rand()
{
	return rand();
}


