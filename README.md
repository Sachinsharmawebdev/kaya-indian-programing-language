# Kaya Programming Language

Kaya is a fast, secure, and simple programming language designed for both backend and frontend web development. It focuses on efficiency, simplicity, and modern features to help developers write clean, high-performance code.

## Features

- **Speed**: Kaya is optimized for high performance, designed with simplicity in mind to reduce runtime overhead.
- **Simplicity**: Kaya’s minimalistic syntax s it easy to learn and use.
- **Functional Programming**: Kaya emphasizes functional programming paradigms, avoiding complexity introduced by object-oriented structures.
- **Strong Type System**: Kaya supports a strong, static type system for better compile-time error checking and efficient memory management.
- **Cross-Platform**: Kaya is designed to run seamlessly on various platforms with robust tooling support.
- **Security**: Kaya incorporates modern security features to ensure safe and secure development.
- **Concurrency**: Built-in support for concurrent programming, allowing efficient handling of parallel tasks.

## Goals

- **Simplification of Web Development**: Kaya aims to replace JavaScript with a simpler, faster, and more secure language for modern web development.
- **Backend and Frontend**: Kaya supports both backend (Node.js) and frontend development, offering versatility.
- **Clean Syntax**: Kaya’s syntax is minimalistic and easy to understand, making it ideal for both novice and experienced developers.
- **Secure Development**: Kaya ensures a safe environment for developers by incorporating modern security practices.

## Directory Structure

Here is the project structure for Kaya:

/kaya
  └── src
      ├── lexer
      │   ├── lexer.c
      │   └── lexer.h
      ├── parser
      │   ├── parser.c
      │   └── parser.h
      ├── ast
      │   ├── ast.c
      │   └── ast.h
      ├── compiler
      │   ├── compiler.c
      │   └── compiler.h
      ├── runtime
      │   ├── runtime.c
      │   └── runtime.h
      ├── test
      │   ├── lexer_test.c
      │   ├── parser_test.c
      │   ├── ast_test.c
      │   ├── compiler_test.c
      │   └── runtime_test.c
      ├── main.c
      └── Makefile
  ├── doc
  │   └── README.md
  └── examples
      └── hello_world.ky




## Current Progress

The Kaya language development is ongoing. Here's what has been implemented so far:

- **Lexer**: Handles tokenization of Kaya source code, including keywords, identifiers, numbers, strings, operators, and punctuation.
- **Parser**: Generates the abstract syntax tree (AST) from tokenized code.
- **Interpreter**: Executes Kaya programs based on the generated AST.
- **Basic Syntax**: Implemented core features such as variable declaration, function definitions, conditional statements, loops, and expressions.

## How to Build

To build the Kaya language, you can use the following commands:

### 1. Clone the repository:

```
git clone https://github.com/yourusername/kaya.git
cd kaya
2. Build the project:




This will compile the source files and generate the Kaya executable.

3. Run Kaya:
Once built, you can run Kaya with the following command:




./kaya <your_program.kaya>
Contributing
We welcome contributions to Kaya! Whether you’re interested in improving the language features, enhancing performance, or fixing bugs, your help is appreciated.

Here’s how you can contribute:

Fork the repository.
Create a new branch for your feature or bugfix.
Write tests for your changes.
Submit a pull request with a clear description of the changes.
License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
Special thanks to all contributors and resources that helped shape the Kaya programming language.

Feel free to adjust the content based on the latest updates or changes to the project!




