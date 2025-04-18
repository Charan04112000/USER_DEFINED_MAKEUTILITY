#include <stdio.h>
#include <string.h>
#include "parser.h"

int parse_makefile(const char *filename, Rule *rule) {
    FILE *file = fopen(filename, "r");
    if (!file) return -1;

    char line[512];
    fgets(line, sizeof(line), file);
    sscanf(line, "%[^:]: %s", rule->target, rule->dependency);

    fgets(line, sizeof(line), file);
    strcpy(rule->command, line + 1); // skip the tab

    fclose(file);
    return 0;
}
