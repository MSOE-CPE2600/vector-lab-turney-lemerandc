# Vector Calculator
**Author:** Charlie Lemerand  

---

## a. Brief Description of the Program and How It Works

The **Vector Calculator** (`vectcalc`) is a C program that performs basic operations on **vectors**  
It allows users to define, modify, and manipulate vectors. Each vector has a **single-character name** and three **double values** (x, y, z).

This vector calculator utilizes the following commands:
- list  -> Displays the memory of all the vectors
- clear  -> Clears the memory
- quit  -> Ends the Program
- varname = VALx, VALy, VALz  ->Creates or replaces the vector varname in storage.
- var1 + var2  ->Adds two vectors (can be done in vector assignment)
- var1 - var2  ->Subtracts two vectors (can be done in vector assignment)
- var * VAL  ->Performs Scaler multiplication (can be done in vector assignment)
- load filename.csv -> Loads vectors from a `.csv` file into memory
- save filename.csv -> Saves all stored vectors to a `.csv` file


Notes: 
- The varname is limited to **1 character** and cannot be a digit
- The order can be flipped in scaler multiplication There must be spaces in between each element in the equation
- If a segmentation fault occurs, an invalid argument was entered

Internally, vectors are stored in a **dynamically allocated array of struct vector**, which grows as needed.  
The program parses each user command, determines the operation, performs the calculation using functions from `vectorMath.c`, and prints results back to the console.

---

## b. How to Build the Program

Complie Instruction:
```bash
make
```

How to clean up directory:
```bash
make clean
```

---

## c. How to Run the Program – Command Line Options

### Basic Usage:
```bash
./vectcalc
```

Starts the program and displays an interactive prompt:
```bash
vectcalc>
```

You can then enter the commands from before

### Available Command-Line Options:

Shows all available commands
```bash
vectcalc> -h
```
---
