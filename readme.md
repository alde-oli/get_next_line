# Get_Next_Line Project Overview

## Project Description

`get_next_line` is a highly efficient function that reads from a file descriptor, line by line, until the end of the file. It is designed to be reusable, optimized, and secure, following the strict coding standards of the 42 Norm. This function is robust, capable of handling multiple file descriptors, and works with different buffer sizes that can be set at compile time.

The project is composed of several files:
- `get_next_line.h`: The header file with the function prototype.
- `get_next_line.c`: The main function implementation.
- `get_next_line_utils.c`: Helper functions that support the main `get_next_line` function.

## Enhanced Features

The `get_next_line` function includes bonus features that go beyond the mandatory project requirements. These enhancements are integrated into the main files to simplify the structure and reduce redundancy:
- Use of a single static variable to maintain the reading state between function calls.
- Ability to manage multiple file descriptors without losing track of their reading positions, enabling reading from multiple files in an interleaved manner.

## Usage

To use the `get_next_line` function in your project, include the header and source files in your project directory. Compile them along with your main program using the following command:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -o gnl get_next_line.c get_next_line_utils.c your_program_files.c
