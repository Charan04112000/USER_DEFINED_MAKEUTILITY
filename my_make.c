#include <stdio.h>
#include "parser.h"
#include "executor.h"

int main(int argc, char *argv[]) {
    Rule rule;
    if (parse_makefile("Makefile", &rule) == -1) {
        fprintf(stderr, "Error parsing Makefile\n");
        return 1;
    }

    if (needs_build(&rule)) {
        run_command(rule.command);
    } else {
        printf("%s is up to date.\n", rule.target);
    }
    return 0;
}
