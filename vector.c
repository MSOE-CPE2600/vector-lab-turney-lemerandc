/******************************
 * Filename: vector.c
 * Description: Handles the user side
 * Author: Charlie Lemerand
 * Date: 9/30/2025
 * Compile: gcc vector.c vectorMath.c -o vector
******************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "vectorMath.h"


int main(){
    vector list[11];
    int listPlace = 0;
    clear(list);
    int quit = 0;
    char input[100];


    while(quit == 0){
        printf("vectcalc>  ");
        fgets(input, 99, stdin);


        char commandcheck[100];
        strcpy(commandcheck, input);
        char* commandtoken = strtok(commandcheck, "\n");

        // Checks to see if you quit
        if(strcmp(commandtoken, "quit") == 0){
            quit = 1;
        // Checks to see if they run help
        } else if(strcmp(commandtoken, "-h") == 0){
            printf("This vector calculator utilizes the following commands:\n"
                "\tlist  -> Displays the memory of all the vectors\n"
                "\tclear  -> Clears the memory\n"
                "\tquit  -> Ends the Program\n"
                "\tvarname = VALx, VALy, VALz  ->Creates or replaces the vector varname in storage.\n"
                "\tvar1 + var2  ->Adds two vectors (can be done in vector assignment)\n"
                "\tvar1 - var2  ->Subtracts two vectors (can be done in vector assignment)\n"
                "\tvar * VAL  ->Performs Scaler multiplication (can be done in vector assignment)\n"
                "*Notes: The varname is limited to 1 character and cannot be a digit, The order can be flipped in \n"
                "scaler multiplication, There must be spaces in between each element in the equation, If a segmentation\n"
                "fault occurs, an invalid argument was entered*\n");
        // Checks to see if they list
        }else if(strcmp(commandtoken, "list") == 0){
            display(list);
        // Checks to see if they clear
        } else if(strcmp(commandtoken, "clear") == 0){
            clear(list);
            listPlace = 0;
        // Checks to see if they want to list a vectors value
        } else if(strlen(commandtoken) == 1){
            int i = find(commandtoken[0], list);
            if(i == -1){
                printf("Error: vector needs to be initialized\n");
            } else {
                printf("%c = %.2f    %.2f    %.2f\n", list[i].name, list[i].x, list[i].y, list[i].z);
            }
        // They want something else
        } else {
            char* Firstoken= strtok(input, ", ");
            char* EqOPtoken= strtok(NULL, ", ");
            
            // Checks for an initilization
            if(strcmp(EqOPtoken, "=") == 0){
                char name = Firstoken[0];
                if(isdigit(name) != 0){
                    printf("Error: vector name cannot be a digit\n");
                    continue;
                }

                char* xtoken = strtok(NULL, ", ");
                char* ytoken = strtok(NULL, ", ");
                char* ztoken = strtok(NULL, ", ");

                // initilizing a vector with vector addition
                if(strcmp(ytoken, "+") == 0){
                    int a = find(xtoken[0], list);
                    int b = find(ztoken[0], list);
                    if(a != -1 && b != -1){
                        int place = find(name, list);
                        vector c;
                        c.name = name;
                        Vadd(&list[a], &list[b], &c);
                        if(place != -1){
                            list[place] = c;
                            printf("%c = %.2f    %.2f    %.2f\n", list[place].name, list[place].x, list[place].y, list[place].z);              
                        } else if (listPlace < 10){
                            list[listPlace] = c;
                            printf("%c = %.2f    %.2f    %.2f\n", list[listPlace].name, list[listPlace].x, list[listPlace].y, list[listPlace].z);
                            listPlace++;
                        } else {
                            printf("Error: The number of vectors cannot exceed 10\n");
                        }
                    } else {
                        printf("Error: vectors must be created before being used\n");
                    }
                    continue;
                // initilizing a vector with vector subtraction
                } else if(strcmp(ytoken, "-") == 0){
                    int a = find(xtoken[0], list);
                    int b = find(ztoken[0], list);
                    if(a != -1 && b != -1){
                        int place = find(name, list);
                        vector c;
                        c.name = name;
                        Vsub(&list[a], &list[b], &c);
                        if(place != -1){
                            list[place] = c;
                            printf("%c = %.2f    %.2f    %.2f\n", list[place].name, list[place].x, list[place].y, list[place].z);              
                        } else if (listPlace < 10){
                            list[listPlace] = c;
                            printf("%c = %.2f    %.2f    %.2f\n", list[listPlace].name, list[listPlace].x, list[listPlace].y, list[listPlace].z);
                            listPlace++;
                        } else {
                            printf("Error: The number of vectors cannot exceed 10\n");
                        }
                    } else {
                        printf("Error: vectors must be created before being used\n");
                    }
                    continue;
                // initilizing a vector with scaler multiplication
                } else if (strcmp(ytoken, "*") == 0){
                    int a = find(xtoken[0], list);
                    int b = find(ztoken[0], list);
                    if(a == -1 && b == -1){
                        printf("Error: vector must be created before being used\n");
                    } else if(a == -1) {
                        float a;
                        sscanf(xtoken, "%f", &a);
                        
                        int place = find(name, list);
                        vector c;
                        c.name = name;

                        Scaler(&list[b], &c, a);

                        if(place != -1){
                            list[place] = c;
                            printf("%c = %.2f    %.2f    %.2f\n", list[place].name, list[place].x, list[place].y, list[place].z);              
                        } else if (listPlace < 10){
                            list[listPlace] = c;
                            printf("%c = %.2f    %.2f    %.2f\n", list[listPlace].name, list[listPlace].x, list[listPlace].y, list[listPlace].z);
                            listPlace++;
                        } else {
                            printf("Error: The number of vectors cannot exceed 10\n");
                        }
                    } else if (b == -1){
                        float b;
                        sscanf(ztoken, "%f", &b);
                        
                        int place = find(name, list);
                        vector c;
                        c.name = name;

                        Scaler(&list[a], &c, b);

                        if(place != -1){
                            list[place] = c;
                            printf("%c = %.2f    %.2f    %.2f\n", list[place].name, list[place].x, list[place].y, list[place].z);              
                        } else if (listPlace < 10){
                            list[listPlace] = c;
                            printf("%c = %.2f    %.2f    %.2f\n", list[listPlace].name, list[listPlace].x, list[listPlace].y, list[listPlace].z);
                            listPlace++;
                        } else {
                            printf("Error: The number of vectors cannot exceed 10\n");
                        }
                    } else {
                        printf("Error: Invalid Argument\n");
                    }
                    continue;
                }

                float x;
                float y;
                float z;
                sscanf(xtoken, "%f", &x);
                sscanf(ytoken, "%f", &y);
                sscanf(ztoken, "%f", &z);


                int place = find(name, list);
                if(place != -1){
                    list[place].x = x;
                    list[place].y = y;
                    list[place].z = z;
                    printf("%c = %.2f    %.2f    %.2f\n", list[place].name, list[place].x, list[place].y, list[place].z);            
                } else if (listPlace < 10){
                    list[listPlace].name = name;
                    list[listPlace].x = x;
                    list[listPlace].y = y;
                    list[listPlace].z = z;
                    printf("%c = %.2f    %.2f    %.2f\n", list[listPlace].name, list[listPlace].x, list[listPlace].y, list[listPlace].z);
                    listPlace++;
                } else {
                    printf("Error: The number of vectors cannot exceed 10\n");
                }
            // Finding the value of vector addition
            } else if (strcmp(EqOPtoken, "+") == 0){

                char* atoken = Firstoken;
                int a = find(atoken[0], list);
                char* btoken = strtok(NULL, ", ");
                int b = find(btoken[0], list);
                if(a != -1 && b != -1){
                    Vadd(&list[a], &list[b], &list[10]);
                    printf("ans = %.2f    %.2f    %.2f\n", list[10].x, list[10].y, list[10].z);
                } else {
                    printf("Error: vectors must be created before being used\n");
                }
            // Finding the value of two vector subtraction
            } else if (strcmp(EqOPtoken, "-") == 0){
                char* atoken = Firstoken;
                int a = find(atoken[0], list);
                char* btoken = strtok(NULL, ", ");
                int b = find(btoken[0], list);
                if(a != -1 && b != -1){
                    Vsub(&list[a], &list[b], &list[10]);
                    printf("ans = %.2f    %.2f    %.2f\n", list[10].x, list[10].y, list[10].z);
                } else {
                    printf("Error: vectors must be created before being used\n");
                }
            // Finding the value of either scaler multiplication or dot product
            } else if (strcmp(EqOPtoken, "*") == 0){
                char* atoken = Firstoken;
                int a = find(atoken[0], list);
                char* btoken = strtok(NULL, ", ");
                int b = find(btoken[0], list);
                // Dot product
                if(a != -1 && b != -1){
                    double val = Dot(&list[a], &list[b]);
                    printf("ans = %.2f * %.2f + %.2f * %.2f + %.2f * %.2f = %.2f\n", list[a].x, list[b].x, list[a].y, 
                        list[b].y, list[a].z, list[b].z, val);
                // Scalar multiplication
                } else if(b != -1 && isdigit(atoken[0]) != 0){
                    float a;
                    sscanf(atoken, "%f", &a);
                    Scaler(&list[b], &list[10], a);
                    printf("ans = %.2f    %.2f    %.2f\n", list[10].x, list[10].y, list[10].z);
                // Scalar multiplication
                } else if (a != -1 && isdigit(btoken[0]) != 0){
                    float b;
                    sscanf(btoken, "%f", &b);
                    Scaler(&list[a], &list[10], b);
                    printf("ans = %.2f    %.2f    %.2f\n", list[10].x, list[10].y, list[10].z);
                } else {
                    printf("Error: vector must be created before being used\n");
                }
            }
        }
    }
    return 0;
}