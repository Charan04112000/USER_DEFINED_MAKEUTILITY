#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "parser.h"

int needs_build(Rule *rule);
void run_command(const char *command);

#endif
