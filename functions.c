#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexical.h"

static FILE *fp;

static const char *keywords[MAX_KEYWORDS] = {
    "int", "float", "return", "if", "else", "while", "for", "do", "break", "continue",
    "char", "double", "void", "switch", "case", "default", "const", "static", "sizeof", "struct"};

static const char *operators = "+-*/%=~^!<>|&.";
static const char *specialCharacters = ",;{}()[]:";
//checking the file 
void initializeLexer(const char *filename)
{
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("_____FILE NOT OPENED____\n");
        return;
    }
    printf("____FILE OPEND SUCCESSFULLY____\n");
}
// checking the token 
Token getNextToken()
{
    Token token;
    char ch;
    ch = fgetc(fp);
    // checking space
    while (isspace(ch))
    {
        ch = fgetc(fp);
    }
    //checking End of file
    if (ch == EOF)
    {
        token.type = EOF_TOKEN;
        return token;
    }
    //checking character
    if (isalpha(ch) || ch == '_')
    {
        int i = 0;
        while (isalnum(ch) || ch == '_')
        {
            token.lexeme[i] = ch;
            i++;
            ch = fgetc(fp);
        }
        token.lexeme[i] = '\0';
        ungetc(ch, fp);
        if (isKeyword(token.lexeme))
        {
            token.type = KEYWORD;
        }
        else
        {
            token.type = IDENTIFIER;
        }
    }
    //checking the char is digit or float
    else if (isdigit(ch))
    {
        int i = 0;

        while (isdigit(ch))
        {
            token.lexeme[i] = ch;
            i++;
            ch = fgetc(fp);
        }

        if (ch == '.')
        {

            token.lexeme[i] = ch;
            i++;

            ch = fgetc(fp);

            while (isdigit(ch))
            {
                token.lexeme[i] = ch;
                i++;
                ch = fgetc(fp);
            }
        }
        token.lexeme[i] = '\0';

        ungetc(ch, fp);

        token.type = CONSTANT;
    }
    //checking single and double comment line
    else if (ch == '/')
    {
        ch = fgetc(fp);
        if (ch == '/')
        {
            while (ch != '\n')
            {
                ch = fgetc(fp);
            }
            return getNextToken();
        }
        else if (ch == '*')
        {
            while (ch != EOF)
            {
                ch = fgetc(fp);
                if (ch == '*')
                {
                    ch = fgetc(fp);
                    if (ch == '/')
                    {
                        break;
                    }
                }
            }
            return getNextToken();
        }
        else 
        {
            ungetc(ch, fp);

            token.lexeme[0] = '/';
            token.lexeme[1] = '\0';

            token.type = OPERATOR;
        }
    }
    // check the string literal like "HELLO"
    else if (ch == '"')
    {
        int i = 0;
        token.lexeme[i++] = ch;
        ch = fgetc(fp);
        while (ch != '"' && ch != EOF)
        {
            token.lexeme[i++] = ch;
            ch = fgetc(fp);
        }
        if (ch == '"')
        {
            token.lexeme[i++] = ch;
        }
        token.lexeme[i] = '\0';
        token.type = CONSTANT;
    }
    //  check the char literals like 'A'
    else if (ch == '\'')
    {
        int i = 0;
        token.lexeme[i++] = ch;
        ch = fgetc(fp);
        token.lexeme[i++] = ch;
        ch = fgetc(fp);
        if (ch == '\'')
        {
            token.lexeme[i++] = ch;
        }
        token.lexeme[i] = '\0';
        token.type = CONSTANT;
    }
    // ckecking char is single & double operator
    else if (isOperator(ch))
    {
        int i = 0;
        token.lexeme[i++] = ch;
        ch = fgetc(fp);
        if (isOperator(ch))
        {
            if ((token.lexeme[0] == '+' && ch == '+') ||
                (token.lexeme[0] == '-' && ch == '-') ||
                (token.lexeme[0] == '=' && ch == '=') ||
                (token.lexeme[0] == '!' && ch == '=') ||
                (token.lexeme[0] == '<' && ch == '=') ||
                (token.lexeme[0] == '>' && ch == '=') ||
                (token.lexeme[0] == '&' && ch == '&') ||
                (token.lexeme[0] == '|' && ch == '|'))
            {
                token.lexeme[i++] = ch;
            }
            else
            {
                ungetc(ch, fp);
            }
        }
        else
        {
            ungetc(ch, fp);
        }

        token.lexeme[i] = '\0';
        token.type = OPERATOR;
    }
    //checking char is special character
    else if (isSpecialCharacter(ch))
    {
        token.lexeme[0] = ch;
        token.lexeme[1] = '\0';
        token.type = SPECIAL_CHARACTER;
    }
    else if(ch=='#')
    {   Token token;
        int i=0;
        token.lexeme[i++]=ch;
        ch=fgetc(fp);
        while(isalpha(ch)|| ch=='.'|| ch=='<' || ch=='>' ||ch==' '|| ch=='"' || ch=='"')
        {
            token.lexeme[i++]=ch;
            ch=fgetc(fp);
        }
        token.lexeme[i]='\0';
        token.type = PREPROCESSOR_DIRECTIVE;
    }
    else
    {
        int i = 0;
        token.lexeme[i++] = ch;
        token.lexeme[i] = '\0';
        token.type = UNKNOWN;
    }
    return token;
}
// checking the string is keyword or not
int isKeyword(const char *str)
{
    for (int i = 0; i < MAX_KEYWORDS; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
// checking the char operator or not
int isOperator(char str)
{
    if (strchr(operators, str) != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// checking the char is special character or not 
int isSpecialCharacter(char ch)
{
    if (strchr(specialCharacters, ch) != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// checking the string is identifier or not 
int isIdentifier(const char *str)
{
    int i = 0;
    if (!(isalpha(str[0]) || str[0] == '_'))
    {
        return 0;
    }
    for (i = 1; str[i] != '\0'; i++)
    {
        if (!(isalnum(str[i]) || str[i] == '_'))
        {
            return 0;
        }
    }
    if (isKeyword(str))
    {
        return 0;
    }
    return 1;
}