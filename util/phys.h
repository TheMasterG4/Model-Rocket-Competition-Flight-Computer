//
// Created by Boris on 9/26/2025.
//

#ifndef PHYS_H
#define PHYS_H
#include "vector.h"
#include <time.h>


static struct vector d = {0,0,0};
static float highest = 0;
static struct vector v = {0,0,0};
static struct vector a = {0,0,0};


static float t=0;
static float t1 = 0;


static int updateTime() {
    const float now = clock();
    if(now-t1==0) return 0;
    t = (now - t1) / CLOCKS_PER_SEC;
    t1 = now;
    return 1;
}

static void updPos() {
    if(d.y<-10){return;}

    ///Figure out inputs
    struct vector newPos ={0,0,0};
    const struct vector v1 =v;

    v.x=(newPos.x-d.x)/t;

    v.y=(newPos.y-d.y)/t;

    v.z=(newPos.z-d.z)/t;

    a.x=(v1.x-v.x)/t;
    a.y=(v1.y-v.y)/t;
    a.z=(v1.y-v.y)/t;

    d=newPos;
    if(d.y>highest){highest=d.y;}
    printf("Elapsed: %f seconds\n", highest);
}




static void update() {
    if(updateTime()==0){ return;}
    updPos();
}
#endif //PHYS_H
