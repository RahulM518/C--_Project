#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"../include/condition.h"
#include "../include/interpreter.h"

bool evaluate_condition(int x, char *op, int y)
{
  if(strcmp(op, "==") == 0)
    return x == y;
  else if(strcmp(op, "!=") == 0)
    return x != y;
  else if(strcmp(op, "<") == 0)
    return x < y;
  else if(strcmp(op, "<=") == 0)
    return x <= y;
  else if(strcmp(op, ">") == 0)
    return x > y;
  else if(strcmp(op, ">=") == 0)
    return x >= y;
  else
    return false;
}
