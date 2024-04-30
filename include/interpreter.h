#ifndef INTERPRETER_H
#define INTERPRETER_H
struct variable{
  int val;
  char *name;
};
extern struct variable vars[];
extern int num_vars;
void execute_c_minus_minus(char *code);

#endif /* INTERPRETER_H */
