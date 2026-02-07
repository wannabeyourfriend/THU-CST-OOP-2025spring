# THU-CST-OOP-2025spring

Object-Oriented Programming (Spring 2025)

Tsinghua University - Department of Computer Science and Technology

## Overview

This repository contains coursework and assignments for the Object-Oriented Programming course, including 6 programming assignments (PAs) and a final project.

## Course Structure

### Assignments
- **PA0**: Introduction and Setup
- **PA1**: Basic OOP Concepts
- **PA2**: Inheritance and Polymorphism
- **PA3**: Advanced OOP Features
- **PA4**: Design Patterns
- **PA5**: STL and Generic Programming
- **PA6**: Final Project Preparation

### Assessments
- **Exercise Problems**: Practice exercises throughout the semester
- **Final Project**: Comprehensive OOP application
- **Report**: Course documentation and analysis

## Academic Integrity Policy

### Implementation Rules for Student Disciplinary Measures

#### Chapter 6: Academic Misconduct and Violations of Learning Discipline

**Article 21**: Students who commit any of the following serious violations of course learning discipline shall receive a punishment ranging from warning to probation:

1. Serious plagiarism in course assignments
2. Serious plagiarism in laboratory reports or falsification of experimental data
3. Serious plagiarism in mid-term or final course papers
4. Other serious acts of falsification during the course learning process

## Course Materials

### Lecture Notes

#### Lecture 1: Command Line Basics

Basic command line operations for file management:

```bash
# Windows vs Linux/Mac commands
cd <-> pwd                    # Change directory vs Print working directory
mkdir <-> mkdir               # Create directory (same)
type nul>a.cpp <-> touch a.cpp    # Create file
dir <-> ls                   # List directory contents
cd ..                        # Move to parent directory
cd <mydir>                   # Move to specific directory
del a.cpp <-> rm a.cpp       # Delete file
rmdir /s OOP2020 <-> rm -r OOP2020  # Remove directory recursively
```

File operations:

```bash
# Move a.cpp to OOP2020 directory
move a.cpp OOP2020\      # Windows
mv a.cpp OOP2020/        # Linux/Mac

# Copy a.cpp to OOP2020 directory
copy a.cpp OOP2020\      # Windows
cp a.cpp OOP2020/        # Linux/Mac

# Copy all files from directory a to OOP2020
xcopy /e a OOP2020       # Windows
cp -r a OOP2020          # Linux/Mac
```

**SSH Operations**: [SSH Tutorial](https://wangdoc.com/ssh/basic)

**Self-Study Materials**:
- [Object-Oriented Programming in C++](https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/)

#### Lecture 2: C++ Compilation and Build Tools

**C++ Program Generation Process**:
Source Code → Compiler (Syntax Analysis + Static Type Checking → AST Construction → Target Code Generation) → Object Files (.o/.obj) → Linker (Link object modules and handle references) → Executable Program

**Multi-file Compilation Example**:

```bash
# Assume ex5_main.cpp and func.cpp exist
g++ -c ex5_main.cpp -o main.o    # Compile ex5_main.cpp to main.o
g++ -c func.cpp -o func.o        # Compile func.cpp to func.o
g++ main.o func.o -o test2       # Link main.o and func.o to executable test2
```

**Function and Variable Declarations vs Definitions**:

- **Function Declaration**: Informs compiler of function name, parameter types, and return type. Example: `int ADD(int a, int b);` (parameter names optional)
- **Function Definition**: Implementation of function functionality. Example: `int ADD(int a, int b) { return a + b; }`
- **Variable Definition**: Allocates memory. Example: `int x = 0;`, `int arr[100];`, or `int x;`
- **Variable Declaration**: Uses `extern` keyword, doesn't allocate memory. Example: `extern int x;`, `extern int arr[100];`

**Macro Definitions**:

1. **Simple Macro Replacement**: `#define PI 3.1415926535` (often replaced by `const` in C++)
2. **Parameterized Macros**: `#define sqr(x) ((x) * (x))` (generally replaced by inline functions in C++)
3. **Header Guards**: Prevent duplicate inclusion
   ```cpp
   #ifndef __BODYDEF_H__
   #define __BODYDEF_H__
   // Header content
   #endif
   ```
   Or use `#pragma once` (simpler and faster)
4. **Debug Output**: Control debug information with `#ifdef DEBUG`

**Make Tool**:

Automates large compilation tasks, reduces compilation time, ensures correct options, and simplifies repetitive tasks.

**Makefile Rules**:
```makefile
# Comments start with #
# Format: <target> : <prerequisites>
#    [tab] <command>

all: main test

main: main.cpp student.cpp
    g++ -o main main.cpp student.cpp

test: student.cpp student_test.cpp
    g++ -o test student_test.cpp student.cpp

clean:
    rm main test
```

**Advanced Syntax**:
- Automatic variables: `$@` (target file), `$^` (all prerequisites), `$<` (first prerequisite)
- Wildcards: `%`
- Conditionals and loops (using Bash syntax)

**Command Line Arguments**: `main(int argc, char** argv)`
- `argc`: Number of command line arguments
- `argv`: Array of character pointers storing arguments
- Always check `argc` to avoid out-of-bounds access

**GDB Debugger**:

Compile with debug information: `g++ -g a.cpp -o a.out`

Common commands:
- `gdb a.out` - Start debugging
- `run` - Run program
- `break <line>` - Set breakpoint
- `watch x` - Monitor variable changes
- `continue` - Continue to next breakpoint
- `step` - Single step (enter functions)
- `next` - Single step (skip functions)
- `print x` - Print variable value
- `display x` - Continuously display variable
- `list` - List source code
- `quit` - Exit debugger

**Practice Exercises**:

**Basic**: Write a small program with multiple `.h` and `.cpp` files, design global functions and variables referenced across multiple `.cpp` files, and write a Makefile for automated compilation.

**Advanced**: Study the Makefile from an open-source project like [GIZA++](https://github.com/moses-smt/giza-pp/) to learn complex build rules and variable usage.

```makefile
.PHONY: gizapp mkcls-v2
all: gizapp mkcls-v2
gizapp:
    $(MAKE) -C GIZA++-v2
mkcls-v2:
    $(MAKE) -C mkcls-v2
clean:
    $(MAKE) -C GIZA++-v2 clean
    $(MAKE) -C mkcls-v2 clean
```

## Repository Structure

```
THU-CST-OOP-2025spring/
├── PA0/           # Programming Assignment 0
├── PA1/           # Programming Assignment 1
├── PA2/           # Programming Assignment 2
├── PA3/           # Programming Assignment 3
├── PA4/           # Programming Assignment 4
├── PA5/           # Programming Assignment 5
├── PA6/           # Programming Assignment 6
├── exercise/      # Exercise problems
├── final/         # Final project
├── Report/        # Course reports and documentation
└── README.md      # This file
```

## Building and Running

Each assignment directory contains specific build instructions. Generally:

```bash
# For C++ assignments
g++ -o output source.cpp
./output

# Using Makefile (if available)
make
./executable
```

## Requirements

- C++ Compiler (g++ or clang++)
- Python 3.x (for any Python-based components)
- Make utility
- GDB debugger (optional but recommended)

## License

This repository is for educational purposes as part of Tsinghua University's OOP course.

## Contact

For course-related inquiries, please contact the course instructor or teaching assistants.
