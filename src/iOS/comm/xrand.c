#include "../../../xrand.h"
#include "../include/sys_rand.h"



void xrand_srand(xuint32_t seed)
{
    sys_srand(seed);
}

xint32_t xrand_rand()
{
    return sys_rand();
}
