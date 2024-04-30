#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/interpreter.h"
#include"../include/print.h"
void print_variable(char *token)
{
  for(int i=0; i<num_vars+1; i++)
    {
      if(strcmp(token, vars[i].name)==0)
      {
        //  printf("%s = %d \n", vars[i].name,vars[i].val); , shows x and w
        printf("%d \n",vars[i].val);
        return;
      }
    }
}