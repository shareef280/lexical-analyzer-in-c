#include <stdio.h>
#include "lexical.h"

int main(int argc, char *argv[])
{
    initializeLexer(argv[1]);

    Token token;
    printf(CYAN "========== LEXICAL ANALYZER OUTPUT ==========\n" RESET);
    while ((token = getNextToken()).type != EOF_TOKEN)
    {
        switch (token.type)
        {
           case KEYWORD:
            printf("%-20s : %s\n","Key word: ",token.lexeme);
            break;
           case OPERATOR:
            printf("%-20s : %s\n","OPERATOR: ",token.lexeme);
            break;
           case SPECIAL_CHARACTER:
            printf("%-20s : %s\n","SPECIAL_CHARACTER: ",token.lexeme);
            break;
           case CONSTANT:
            printf("%-20s : %s\n","CONSTANT: ",token.lexeme);
            break;
           case IDENTIFIER:
            printf("%-20s : %s\n","IDENTIFIER: ",token.lexeme);
            break;
            case PREPROCESSOR_DIRECTIVE:
             printf("%-20s : %s\n","PREPROCESSOR_DIRECTIVE",token.lexeme);
            break;
           case UNKNOWN:
            printf("%-20s : %s\n","UNKNOWN: ",token.lexeme);
            break;
           default:
            printf("Token: %s, Type: %d\n", token.lexeme, token.type);
            break;
        }

    }
printf(CYAN "========== END OF TOKENS ==========\n" RESET);
    return 0;
}