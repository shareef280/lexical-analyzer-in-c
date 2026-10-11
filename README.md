# 🔍 Lexical Analyzer in C

A **Lexical Analyzer implemented in C** that reads source code and identifies tokens such as keywords, identifiers, operators, constants, special characters, and preprocessor directives.

This project demonstrates the fundamentals of lexical analysis, the first phase of a compiler, through file handling, character processing, and token classification.

## 📌 Project Overview

A lexical analyzer, also known as a lexer or scanner, processes source code character by character and groups characters into meaningful units called **tokens**.

For example, consider the following C statement:

```c
int sum = 10 + 20;
```

The lexical analyzer identifies the following tokens:

| Lexeme | Token Type        |
| ------ | ----------------- |
| `int`  | Keyword           |
| `sum`  | Identifier        |
| `=`    | Operator          |
| `10`   | Constant          |
| `+`    | Operator          |
| `20`   | Constant          |
| `;`    | Special Character |

This project reads a source file and classifies recognized tokens according to their types.

## ✨ Features

* **Keyword Recognition:** Identifies supported C keywords such as `int`, `float`, `return`, and `if`.
* **Identifier Recognition:** Recognizes names used for variables and functions.
* **Operator Detection:** Identifies supported operators, including arithmetic, relational, and logical operators.
* **Constant Recognition:** Detects numeric constants, string literals, and character literals.
* **Special Character Detection:** Identifies punctuation and delimiters such as `;`, `{`, `}`, `(`, and `)`.
* **Preprocessor Directive Detection:** Recognizes supported preprocessor directives beginning with `#`.
* **Comment Handling:** Includes logic to skip single-line and multi-line comments.
* **Unknown Token Identification:** Classifies unrecognized characters as unknown tokens.
* **File-Based Input:** Reads source code from a file and displays the detected tokens.

## 🛠️ Technologies Used

* C Programming
* File Handling
* String Processing
* Character Classification
* GCC Compiler
* Linux

## 📂 Project Structure

```text
lexical-analyzer-in-c/
│
├── main.c
├── functions.c
├── lexical.h
├── README.md
└── .gitignore
```

### File Description

| File          | Description                                                                                       |
| ------------- | ------------------------------------------------------------------------------------------------- |
| `main.c`      | Main program that reads tokens and displays their classifications.                                |
| `functions.c` | Implements token recognition, keyword checking, operator detection, and character classification. |
| `lexical.h`   | Defines the token structure, token types, constants, and function declarations.                   |
| `README.md`   | Project documentation.                                                                            |
| `.gitignore`  | Specifies generated files that should not be tracked by Git.                                      |

## ⚙️ Prerequisites

Before running the project, ensure that you have:

* Linux or WSL Ubuntu.
* GCC compiler.
* A terminal or VS Code with a Linux development environment.

Check whether GCC is installed:

```bash
gcc --version
```

If GCC is unavailable on Ubuntu or WSL, install it using:

```bash
sudo apt update
sudo apt install build-essential
```

## 🚀 Compilation and Execution

### Step 1: Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/lexical-analyzer-in-c.git
```

Replace `YOUR_USERNAME` with your GitHub username.

### Step 2: Navigate to the Project Directory

```bash
cd lexical-analyzer-in-c
```

### Step 3: Compile the Source Files

```bash
gcc -Wall -Wextra main.c functions.c -o lexical_analyzer
```

### Step 4: Create a Sample Input File

Create a file named `input.c`:

```c
#include <stdio.h>

int main()
{
    int a = 10;
    float b = 20.5;

    if (a < b)
    {
        printf("A is smaller");
    }

    return 0;
}
```

### Step 5: Run the Lexical Analyzer

```bash
./lexical_analyzer input.c
```

The program reads the specified source file and prints the recognized tokens and their classifications.

## 📊 Expected Output

For the sample input, the output will contain classifications similar to the following:

```text
========== LEXICAL ANALYZER OUTPUT ==========

PREPROCESSOR_DIRECTIVE : #include <stdio.h>
Key word:            : int
IDENTIFIER:          : main
SPECIAL_CHARACTER:   : (
SPECIAL_CHARACTER:   : )
SPECIAL_CHARACTER:   : {
Key word:            : int
IDENTIFIER:          : a
OPERATOR:            : =
CONSTANT:            : 10
SPECIAL_CHARACTER:   : ;
Key word:            : float
IDENTIFIER:          : b
OPERATOR:            : =
CONSTANT:            : 20.5
SPECIAL_CHARACTER:   : ;

========== END OF TOKENS ==========
```

*Note: This is an illustrative excerpt. The exact output depends on the tokenization implemented in the source code.*

## 🔄 How It Works

The lexical analyzer follows these basic steps:

1. **Read Input:** Opens the specified source file.
2. **Skip Whitespace:** Skips whitespace characters between tokens.
3. **Identify Lexemes:** Reads sequences of characters that form potential tokens.
4. **Classify Tokens:** Determines whether each lexeme is a keyword, identifier, constant, operator, special character, preprocessor directive, or unknown token.
5. **Display Results:** Prints the recognized token and its classification.
6. **Terminate:** Continues until the end of the input file is reached.

### Processing Flow

```text
       Source Code File
               |
               v
        Read Characters
               |
               v
        Identify Lexemes
               |
               v
        Classify Tokens
               |
               v
      Display Token Types
               |
               v
          End of File
```

## 📚 Concepts Learned

Through this project, I explored:

* Fundamentals of compiler design.
* Lexical analysis and tokenization.
* Character and string processing in C.
* File handling using standard C library functions.
* Keyword, operator, and identifier recognition.
* Structures and enumerations in C.
* Modular programming using header and source files.

## ⚠️ Current Limitations

This is an educational lexical analyzer and does not implement the complete C language specification.

Some limitations include:

* Only a limited set of C keywords is recognized.
* Operator recognition supports only selected combinations.
* Numeric and character literal parsing is simplified.
* Preprocessor directive handling is basic.
* Advanced escape sequences and complex lexical rules are not fully supported.
* Comprehensive error handling and malformed-input detection can be improved.

## 🔮 Future Enhancements

Potential improvements include:

* Support for the complete set of C keywords and operators.
* Improved handling of numeric constants and escape sequences.
* More robust comment and preprocessor directive processing.
* Better handling of invalid tokens and malformed source files.
* Automated test cases for token classification.
* Integration with a parser to explore the next phase of compiler design.

## 👨‍💻 Author

**Shareef Sab**

Electronics and Communication Engineering Student

Interests: C Programming, Linux, Embedded Systems, and Compiler Design.



⭐ This project was developed to strengthen my understanding of C programming and the fundamentals of compiler design through practical implementation.
