#include "../include/interpreter.h"
#include "../include/variable.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create_variable(char* token)
{
  vars[num_vars].name = malloc(sizeof(char) * strlen(token));
  strcpy(vars[num_vars].name, token);
}
void assign_variable(char* token)
{
  vars[num_vars].val= atoi(token);
}
int get_variable_value(char* var_name)
{
  for(int i = 0; i < num_vars; i++)
    if(strcmp(var_name, vars[i].name) == 0)
      return vars[i].val;      
}