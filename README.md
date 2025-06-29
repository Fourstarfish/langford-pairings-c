# Langford Pairings CLI Tool

A command-line utility written in C for generating and validating Langford pairings. This tool implements efficient algorithms to construct Langford sequences of a given order _n_, and to verify whether a user-supplied sequence is a valid Langford pairing.  

## Table of Contents

- [Project Overview](#project-overview)  
- [Features](#features)  
- [Prerequisites](#prerequisites)  
- [Building & Installation](#building--installation)  
- [Usage](#usage)  
- [Testing](#testing)  
- [Code Structure](#code-structure)  
- [Contributing](#contributing)

## Project Overview

Langford pairings are arrangements of the numbers 1 through _n_ in a sequence of length 2_n_ + 2, such that each integer _k_ appears exactly twice, and the two occurrences of _k_ are separated by exactly _k_ other elements. This tool provides two primary modes:

1. **Generation**: Enumerate all valid Langford sequences for a specified order _n_.  
2. **Validation**: Check whether a given sequence is a correct Langford pairing.

## Features

- **Generate Pairings**: Efficient backtracking algorithm to list all solutions for order _n_.  
- **Validate Sequence**: Verify correctness of any user-provided sequence.  
- **Dynamic Memory**: Uses `malloc`/`free` for sequence storage.  
- **Error Handling**: Input validation and descriptive error messages.  
- **Zero Dependencies**: Single-file C implementation; no external libraries required.

## Prerequisites

- A C compiler (e.g. `gcc`, `clang`) supporting C99  
- POSIX-compatible shell (for build scripts)

## Building & Installation

1. **Clone the repository**  
   git clone https://github.com/your-username/langford-pairings-c.git
   cd langford-pairings-c

2. Compile
   gcc -std=c99 -O2 -o langford langford.c

3. (Optional) Install to system path
   sudo mv langford /usr/local/bin/

## Usage

Generate all Langford pairings of order n
   ./langford -g <n>

Validate a candidate sequence
   ./langford -v <sequence>

Help & Usage
   ./langford -h

## Testing

Include any test scripts or example inputs in the tests/ directory. To run a simple validation test:
   ./langford -v tests/sample_valid.txt

## Code Structure

langford.c
main() parses arguments (-g, -v, -h).
generate(n) implements backtracking to build sequences.
validate(arr, len) checks spacing rules for a given array.
Helper functions for memory management and I/O.
Makefile (if provided)
make all – compile
make clean – remove binaries

## Contributing

Contributions are welcome! Please:

Fork the repository.
Create a feature branch (git checkout -b feature/YourFeature).
Commit your changes and push to your fork.
Open a pull request describing your improvement.
Please adhere to the existing code style and include tests for new functionality.
