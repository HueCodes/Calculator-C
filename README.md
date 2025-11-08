# Simple Calculator

A command-line calculator written in C that performs basic arithmetic operations.

## Features

- Addition, subtraction, multiplication, and division
- Input validation and error handling
- Division by zero protection

## Requirements

- GCC or any C compiler supporting C99
- Make (optional, for using Makefile)

## Building

### Using Make
```bash
make
```

### Manual Compilation
```bash
gcc -std=c99 -Wall -Wextra -o calculator calculator.c
```

## Usage

Run the calculator:
```bash
./calculator
```

Follow the prompts to:
1. Enter an operator (+, -, *, /)
2. Enter the first number
3. Enter the second number

### Example Session
```
Simple Calculator
=================
Enter an operation (+, -, *, /): +
Enter first number: 15.5
Enter second number: 4.5
15.50 + 4.50 = 20.00
```

## Error Handling

The calculator handles:
- Invalid operators
- Non-numeric input
- Division by zero

## License

MIT License - feel free to use and modify as needed.
