# GFY-CPP

An interpreter for the GFY language written in C++.

> :warning: This project is discontinued beacuse the original GFY language is no longer maintained.

- [GFY-CPP](#gfy-cpp)
  - [Building](#building)
  - [Usage](#usage)
  - [Implemented features](#implemented-features)
    - [I/O](#io)
    - [Variables](#variables)
      - [Variable types](#variable-types)
    - [Arithmetic operations](#arithmetic-operations)
    - [Logical operations](#logical-operations)
    - [Operators](#operators)
  - [Documentation](#documentation)
  - [Notes](#notes)
  - [Aknowledgements](#aknowledgements)

## Building

To build the interpreter, run the following commands:

```bash
$ git clone https://github.com/LanaMirko04/gfy-cpp.git
$ cd gfy-cpp
$ make
```

## Usage

To run the interpreter, use the following command:

```bash
$ ./bin/gfy-cpp <file>
```

Where `<file>` is the path to the file containing the GFY code.

## Implemented features

The following is a list of the features that have been implemented in the interpreter.

**Legend:**
- :white_check_mark: - Implemented
- :warning: - Partially implemented
- :x: - Not implemented

### I/O

| Keyword | Description | Status |
| --- | --- | --- |
| `input` | Reads a value from the given input stream. | :x: |
| `output` | Prints a value to the given output stream. | :x: |

### Variables

| Keyword | Description | Status |
| --- | --- | --- |
| `print` | Prints a string to the console. | :warning: |
| `set` | Sets a variable to a value. | :warning: |

#### Variable types
| Type | Description | Status |
| --- | --- | --- |
| `int` | Integer number. | :white_check_mark: |
| `float` | Floating-point number. | :white_check_mark: |
| `string` | String. | :white_check_mark: |
| `bool` | Boolean value. | :white_check_mark: |
| `list` | List of values. | :x: |

### Arithmetic operations

| Keyword | Description | Status |
| --- | --- | --- |
| `add` | Adds two numbers. | :x: |
| `sub` | Subtracts two numbers. | :x: |
| `mul` | Multiplies two numbers. | :x: |
| `div` | Divides two numbers. | :x: |
| `mod` | Calculates the remainder of the division of two numbers. | :x: |

### Logical operations

| Keyword | Description | Status |
| --- | --- | --- |
| `equals` | Checks if two values are equal. | :x: |
| `greater` | Checks if the first value is greater than the second. | :x: |
| `less` | Checks if the first value is less than the second. | :x: |
| `define` | Defines a function. | :x: |


### Operators
| Operator | Description | Status |
| --- | --- | --- |
| `->` | Set explicit type. | :warning: |
| `@` | Get the value of a list at a specific index. | :x: |

## Documentation

_TODO_

## Notes

- `input`, `output`, `list` and `@` are not implemented in the lexer yet.
- The interpreter is still in development and some features may not work as expected.

## Aknowledgements

Special thanks to:
- [EtanoloYT](https://github.com/EtanoloYT) for creating the [GFY language](https://github.com/EtanoloYT/gfy);
- [jothepro](https://github.com/jothepro) for [`doxygen-awesome-css`](https://github.com/jothepro/doxygen-awesome-css).
