#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../include/arithmetic.h"
#include "../include/interpreter.h"
int perform_arithmetic(int x, char *op, int y)
{
  if(strcmp(op,"+")==0)
  {
    return x+y;
  }
  else if(strcmp(op,"-")==0)
    return x-y;
  else if(strcmp(op,"*")==0)
    return x*y;
  else if(strcmp(op,"/")==0)
    return x/y;
  else if(strcmp(op,"%")==0)
    return x%y;
  else
    return 0;
}