#ifndef PARSER_H
#define PARSER_H

typedef struct {
    char target[128];
    char dependency[128];
    char command[256];
} Rule;

int parse_makefile(const char *filename, Rule *rule);

#endif
