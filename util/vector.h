//
// Created by Boris on 9/26/2025.
//

#ifndef VECTOR_H
#define VECTOR_H
struct vector {
    float x,y,z;
};

inline struct vector bv(float x,float y,float z) {
    struct vector v = {x,y,z};
    return v;
}



#endif //VECTOR_H
