/******************************
 * Filename: vectorMath.c
 * Description: Holds the math and helper functions
 * Author: Charlie Lemerand
 * Date: 9/30/2025
 * Compile: gcc vector.c vectorMath.c -o vector
******************************/

#include "vectorMath.h"
#include <stdio.h>
#include <string.h>

// Adds vectors a and b together and saves it to c
void Vadd(vector* a, vector* b, vector* c){
    c->x = a->x + b->x;
    c->y = a->y + b->y;
    c->z = a->z + b->z;
}

// Subtracts vector b from a together and saves it to c
void Vsub(vector* a, vector* b, vector* c){
    c->x = a->x - b->x;
    c->y = a->y - b->y;
    c->z = a->z - b->z;
}

// Multiplies every value in vector a by scale and saves it to b
void Scaler(vector* a, vector* b, double scale){
    b->x = scale * a->x;
    b->y = scale * a->y;
    b->z = scale * a->z;
}

// Finds and returns the dot product of vectors a and b
double Dot(vector* a, vector* b){
    double value = a->x * b->x;
    value += a->y * b->y;
    value += a->z * b->z;
    return value;
}

// Finds a vector with name and returns it's index
int find(char name, vector* list){
    for(int i = 0; i < 10; i++){
        if(list[i].name == name){
            return i;
        }
    }
    return -1;
}

// clears every value in a list of vectors
void clear(vector* list){
    for(int i = 0; i < 11; i++){
        list[i].name = ' ';
        list[i].x = 0.0;
        list[i].y = 0.0;
        list[i].z = 0.0;
    }
}

// prints out the name and values of every vector in the list
void display(vector* list){
    for(int i = 0; i < 10; i++){
        printf("    %c: %.2f %.2f %.2f\n", list[i].name, list[i].x, list[i].y, list[i].z);
    }
}
