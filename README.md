# C-- Interpreter
An interpreter which runs C-- code, via translation of various commands written in C

## Code Execution

C-- code consists of a concise set of instructions stored as an array of characters, which is passed to the 'execute_c_minus_minus' function in 'interpreter.h'. The code is executed line by line, where it checks for instruction and processes them accordingly. It can also handle basic if statements.

In addition, ensure that there are spaces between different terms as present in the 'main.c' file in the 'src' directory.

### Tokenization

The interpreter uses mainly `strtok()` and `strtok_r()` to tokenize the given array 'code.' These functions break the code into elements that can be interpreted.

### Cons

Please note that this project has some limitations:

- **Only If Statements**: The interpreter does not support nested if statements. 

- **Limited Scope**: There is no concept of scope. A variable once declared, can be used anywhere.

- **Two Operands**: You can only assign values that result from arithmetic operations involving at most two values. Providing more values will give errors.

- **Only int as a Datatypes**: The only datatype available is 'int'.

# Running Tests
clear out all the object files, run the following command in the root directory of the project.
```bash
  make clean
```
To compile all the '.c' files, run the following command inside the root directory. This will generate all the object files inside the 'obj' directory.

```bash
  make
```
After a successful compilation, you can execute your C-- interpreter by running
```bash
  ./C--
```
