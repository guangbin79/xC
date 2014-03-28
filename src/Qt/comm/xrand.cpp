#include "../../xrand.h"
#include<QtGlobal>

void xrand_srand(xuint32_t seed)
{
    qsrand((uint)seed);
}

xint32_t xrand_rand()
{
    return (xint32_t)qrand();
}
