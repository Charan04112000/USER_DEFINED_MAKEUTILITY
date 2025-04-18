#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "executor.h"

int needs_build(Rule *rule) {
    struct stat target_stat, dep_stat;

    if (stat(rule->target, &target_stat) == -1)
        return 1; // target doesn't exist

    if (stat(rule->dependency, &dep_stat) == -1)
        return 0; // dependency doesn't exist

    return dep_stat.st_mtime > target_stat.st_mtime;
}

void run_command(const char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        char *args[10];
        char cmd[256];
        strcpy(cmd, command);
        int i = 0;
        char *token = strtok(cmd, " \n");
        while (token != NULL && i < 9) {
            args[i++] = token;
            token = strtok(NULL, " \n");
        }
        args[i] = NULL;
        execvp(args[0], args);
        perror("execvp failed");
        exit(1);
    } else {
        wait(NULL);
    }
}
