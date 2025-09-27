#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Assume flight computer is x32 only, will change if not the case


struct vector {
    float x,y,z;
};
int main(void){
    /// PRIMARY DATA
    struct vector d = {0,0,0};
    float highest = 0;
    struct vector v = {0,0,0};
    struct vector a = {0,0,0};

    /// PRIMARY TIME DATA
    float t=0;
    float t1 = 0;
    float now;


    short flag=0; /// Prevent over-writing the file!

    while(1) {
        ///Simple clock to increment time up from when the program starts.
        now = clock();
        if(now-t1==0) continue; ///This loops directly until
        t = (now - t1) / CLOCKS_PER_SEC;
        t1 = now;
        /// END clock


        /// New input data
        struct vector d1 ={0,0,0}; /// Takes in a new location from the flight altimeter, currently makes a 0,0,0 vector as a placeholder.
        const struct vector v1 =v; /// Copy, as original v changes.
        /// END new data


        /// Updates
        v.x=(d1.x-d.x)/t;
        v.y=(d1.y-d.y)/t;
        v.z=(d1.z-d.z)/t;

        a.x=(v1.x-v.x)/t;
        a.y=(v1.y-v.y)/t;
        a.z=(v1.y-v.y)/t;
        /*
         *This above updates the velocity and acceleration vectors based on the formula of:
         *(Vf-V0)/t = a
         *(Df-D0)/t = V
         *
         *While this does not represent a perfect formula for the vectors, it does accurately and precisely
         *update the vectors based on where the rocket is. This is not useful for height data, but it is useful
         *for maneuvers along with stalling the program long enough to have a change in the clock() function's output.
         *
         *Maneuvers will be programmed in, however they will be inoperable unless otherwise planned.
         *[The functions will work and everything will be fully complete, however without an actual means of
         *maneuvering the rocket, the functions would be useless to execute, so to be as precise on time as
         *possible, they will not be executed here.]
         */

        d=d1; /// Update original position as the new position

        /// Height check,
        /// if d.y>highest then still going up
        /// if d.y<highest then falling ->
        /// if d.y=highest then stationary -> loop
        if(d.y>highest) {
            highest=d.y;
        } else if(flag ==0 && highest>d.y){
            flag=1;
            FILE *file = fopen("C:/Users/Boris/OneDrive/Desktop/RocketFlightComp/util/highest.txt", "w"); /// Placeholder file location
            if (file != NULL) {
                fprintf(file, "%f", highest); /// Record highest point, nothing more
                fclose(file);
            } else {
                perror("File opening failed");
            }
        }
    }
}
