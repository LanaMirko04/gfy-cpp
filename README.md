# GFY-CPP

An interpreter for the GFY language written in C++.

- [Building](#building)
- [Usage](#usage)
- [Implemented features](#implemented-features)
  - [Keywords](#keywords)
  - [Types](#types)
  - [Operators](#operators)
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

### Keywords
| Keyword | Description | Status |
| --- | --- | --- |
| `print` | Prints a string to the console. | :white_check_mark: |
| `set` | Sets a variable to a value. | :white_check_mark: |
| `add` | Adds two numbers. | :x: |
| `sub` | Subtracts two numbers. | :x: |
| `mul` | Multiplies two numbers. | :x: |
| `div` | Divides two numbers. | :x: |
| `mod` | Calculates the remainder of the division of two numbers. | :x: |
| `equals` | Checks if two values are equal. | :x: |
| `greater` | Checks if the first value is greater than the second. | :x: |
| `less` | Checks if the first value is less than the second. | :x: |
| `define` | Defines a function. | :x: |

### Types
| Type | Description | Status |
| --- | --- | --- |
| `int` | Integer number. | :white_check_mark: |
| `float` | Floating-point number. | :white_check_mark: |
| `string` | String. | :white_check_mark: |
| `bool` | Boolean value. | :white_check_mark: |

### Operators
| Operator | Description | Status |
| --- | --- | --- |
| `->` | Set explicit type. | :warning: |

## Documentation

_TODO_

## Aknowledgements

This project was inspired by the [GFY language](https://github.com/EtanoloYT/gfy) created by [EtanoloYT](https://github.com/EtanoloYT/) (:warning: _the original project is no longer maintained_ :warning:).
