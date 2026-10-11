#ifndef LEXICAL_H
#define LEXICAL_H

#define MAX_KEYWORDS 20
#define MAX_TOKEN_SIZE 100
#define CYAN    "\033[36m"
#define RESET "\033[0m"

typedef enum {
    KEYWORD,
    OPERATOR,
    SPECIAL_CHARACTER,
    CONSTANT,
    IDENTIFIER,
    PREPROCESSOR_DIRECTIVE,
    UNKNOWN,
    EOF_TOKEN
} TokenType;

typedef struct {
    char lexeme[MAX_TOKEN_SIZE];
    TokenType type;
} Token;

void initializeLexer(const char* filename);
Token getNextToken();
void categorizeToken(Token* token);
int isKeyword(const char* str);
int isOperator(char str);
int isSpecialCharacter(char ch);
int isConstant(const char* str);
int isIdentifier(const char* str);

#endif