/******************************
 * Filename: vectorMath.h
 * Description: Holds the math and helper functions
 * Author: Charlie Lemerand
 * Date: 9/30/2025
 * Compile: gcc vector.c vectorMath.c -o vector
******************************/

// The main structure for vectors
typedef struct {
    char name;
    double x;
    double y;
    double z;
} vector;

// Adds vectors a and b together and saves it to c
void Vadd(vector* a, vector* b, vector* c);

// Subtracts vector b from a together and saves it to c
void Vsub(vector* a, vector* b, vector* c);

// Multiplies every value in vector a by scale and saves it to b
void Scaler(vector* a, vector* b, double scale);

// Finds and returns the dot product of vectors a and b
double Dot(vector* a, vector* b);

// Finds a vector with name and returns it's index
int find(char name, vector* list);

// clears every value in a list of vectors
void clear(vector* list);

// prints out the name and values of every vector in the list
void display(vector* list);