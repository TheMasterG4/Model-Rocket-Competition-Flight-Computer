#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/// Assume flight computer is x32 only, will change if not the case

#include "util/vector.c"
#include "util/phys.c"

int main(void){
    while(1) {
        update();
    }

    return 0;
}
