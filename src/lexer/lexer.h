#ifndef LEXER_H
#define LEXER_H

// Token types
typedef enum {
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_STRING,
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATION,
    TOKEN_END,
    TOKEN_ERROR
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char *value;
} Token;

// Function declarations
Token* lexer_init(const char* source);
Token* lexer_next_token();
void lexer_free();

#endif