#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"../include/variable.h"
#include"../include/arithmetic.h"
#include"../include/condition.h"
#include"../include/print.h"
#include"../include/interpreter.h"
struct  variable vars[1000];
int num_vars = -1;
void execute_c_minus_minus(char *code)
{
  char* sp = NULL;
  char* op = NULL;
  char* od = ";" ;// outer deliminator, end of line with ;
  char* id = " " ;
  // inner deliminator, seperate code with a space
  char* token = strtok_r(code, od, &op);
  while(token != NULL)
    {
      char* inner_token = strtok_r(token, id, &sp); 
      // take a token from the inner deliminator
      if(!strcmp(inner_token, "int")|| !strcmp(inner_token,"  int"))
        // if the token is int, add a variable
      {
        char *l[10];
        int c = 0;
        while(inner_token != NULL)
          // add the variable name to the array
          {
            l[c] = inner_token;
            c++;
            inner_token = strtok_r(NULL, id, &sp); // get the next token
          }
        int i=1;
        num_vars++;
        create_variable(l[i]);
        int t1,r;
        if(!atoi(l[i+2])) 
          // if the 3rd token is not a number, but a arithmtic operation
        {
          t1 = get_variable_value(l[i+2]);
          char *op  = l[i+3];
          int t2 = get_variable_value(l[i+4]);
          r = perform_arithmetic(t1,op,t2);
        }
        else
          r = atoi(l[i+2]);
        char *res = malloc(sizeof(char)*20);
        sprintf(res,"%d",r); // convert the result to a string
        assign_variable(res);// assign the result to the variable
        free(res);
    }
      else if(!strcmp(inner_token, "print") || !strcmp(inner_token,"  print"))
        // if the token is print, print the variable
      {
        char *l[10];
        int c = 0;
        while(inner_token != NULL)
          // add the variable name to the array
          {
            l[c] = inner_token;
            c++;
            inner_token = strtok_r(NULL, id, &sp); // get the next token
          }
        print_variable(l[1]);
      }
      else if(!strcmp(inner_token, "if")|| !strcmp(inner_token,"  if"))
        {
          char *l[10];
          int c = 0;
        while(inner_token != NULL)
          {
            l[c] = inner_token;
            c++;
            inner_token = strtok_r(NULL, id, &sp); // get the next token
          }
        int o1,o2;
        char *op1 = l[1];
        op1++;
        o1 = get_variable_value(op1);
        char *cond = l[2];
        int s = strlen(l[3]);
        l[3][s-1] = '\0';
        o2 = atoi(l[3]);
        if(evaluate_condition(o1,cond,o2))
        {
          while(token != NULL && strcmp(token, "}"))
            token = strtok_r(NULL, id, &sp);
          continue;
        }
        else
        {
          if(strcmp(l[5],"  int"))
          {
            int num = 6;
            int i= num;
            num_vars++;
            create_variable(l[i]);
            int t1 = atoi(l[i+2]);
            char *result = malloc(sizeof(char)*20);
            sprintf(result,"%d",t1);
            assign_variable(result);
            free(result);
          }
        }
      }
      else
        break;
      token = strtok_r(NULL, od, &op);
  }
}