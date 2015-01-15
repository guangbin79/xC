/*
 *  sys_rand.mm
 *  sys_api
 *
 *  Created by caiyw on 14-12-2.
 *  Copyright 2014 navinfo. All rights reserved.
 *
 */

#include "../../include/sys_rand.h"


void sys_srand(unsigned int seed){
    srand(seed);
}

int sys_rand(){
    return rand();
}


