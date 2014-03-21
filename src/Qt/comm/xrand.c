#include "../../rand.h"
#include<QtGlobal>

void xrand_srand(xuint32_t seed)
{
    qsrand(seed);
}

xint32_t xrand_rand()
{
    return qrand();
}
