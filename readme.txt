# Custom `make` Utility Project

## Overview
This is a simple implementation of a custom `make` utility that mimics the behavior of `make` used for compiling programs. It reads a `Makefile`, checks the timestamps of the target and its dependencies, and runs the necessary commands to build the target if needed.

---

## Project Structure

```
sample_project/
├── Makefile          # The Makefile for building the target
├── main.c            # Source code of the main program
├── main.o            # Object file created by compilation
├── mymake            # The custom make utility
├── parser.c/.h       # Logic to parse the Makefile
└── executor.c/.h     # Logic to execute commands in the Makefile
```

---

## Requirements

1. **C Compiler** (e.g., GCC)
2. **Unix-like Environment** (Linux/macOS) to run commands like `gcc`, `make`
3. **Makefile** should be properly formatted with a target, dependencies, and command(s).

---

## Setup Instructions

1. **Clone the repository** (or create your own directory with the provided structure)
   - Navigate to your project folder.
   
2. **Create your Makefile**:
   - In the project folder, create a `Makefile` with the following content:
     ```
     main.o: main.c
         gcc -c main.c -o main.o
     ```
     > **Note**: Make sure to use a **tab** (not spaces) before the `gcc` command.

3. **Create the source code**:
   - In the `main.c` file, put the following C code:
     ```c
     #include <stdio.h>
     
     int main() {
         printf("Hello from sample project!
");
         return 0;
     }
     ```

4. **Create the custom make utility**:
   - The main logic of the custom `make` utility is in `mymake.c`, along with the `parser.c` and `executor.c` files for parsing and executing the commands.
   
5. **Compile the custom make utility**:
   - Open your terminal and run the following command:
     ```bash
     gcc -o mymake mymake.c parser.c executor.c
     ```
     This will compile the custom `make` utility into an executable named `mymake`.

6. **Run the custom `make` utility**:
   - Once compiled, you can run the utility using:
     ```bash
     ./mymake
     ```

---

## How It Works

1. The custom `make` utility reads the `Makefile` for rules (targets and dependencies).
2. It checks the timestamps of the target and its dependencies.
3. If the dependency is newer than the target, it runs the specified command (e.g., `gcc` to compile the source file).
4. If the target is up-to-date (i.e., the dependency has not changed), it will print a message indicating that the target is up-to-date.

---

## Example Usage

1. **Initial Run**:
   - When you first run `./mymake`, the target (`main.o`) will be built since it does not exist yet.
   ```bash
   ./mymake
   ```
   Output:
   ```
   gcc -c main.c -o main.o
   ```

2. **Re-run After Compilation**:
   - If you run `./mymake` again after the target has been built, it will check that the target is up-to-date.
   ```bash
   ./mymake
   ```
   Output:
   ```
   main.o is up to date.
   ```

---

## Troubleshooting

1. **Make sure the Makefile is named correctly**:
   - The Makefile **must** be named `Makefile` (uppercase M), and it should be in the same directory as the `mymake` utility.

2. **Ensure the `gcc` command in the Makefile starts with a tab**:
   - In `vi` or any text editor, ensure that the line with the `gcc` command starts with a **tab** (not spaces).

3. **Check if the `mymake` executable was created correctly**:
   - Ensure that `mymake` exists in your project folder:
     ```bash
     ls -l mymake
     ```

---

## License
This project is open-source and free to use. Enjoy building your custom make utility!
