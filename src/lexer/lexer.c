#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

// Source code to tokenize
static char *source_code;
static size_t current_pos = 0;

// List of keywords for Kaya syntax
const char* keywords[] = {
    "let", "const", "fn", "if", "else", "return", "print", "for", "while", "in", 
    "break", "continue", "switch", "case", "default", "try", "catch", "throw", 
    "new", "import", "export", "extends", "implements", "class", "interface", 
    "struct", "enum", "namespace", "async", "await", "true", "false", "null", 
    "void", "this", "super", "is", "as", "type", "typeof", "instanceof"
};
#define KEYWORDS_COUNT (sizeof(keywords) / sizeof(keywords[0]))

// Function to initialize lexer
Token* lexer_init(const char* source) {
    source_code = strdup(source);
    current_pos = 0;
    return lexer_next_token();
}

// strndup implementation for Windows
char* strndup(const char* str, size_t n) {
    char* dup = (char*)malloc(n + 1);
    if (dup) {
        strncpy(dup, str, n);
        dup[n] = '\0';
    }
    return dup;
}

// Function to get the next token
Token* lexer_next_token() {
    Token* token = malloc(sizeof(Token));
    char current_char = source_code[current_pos];

    // Skip whitespace
    while (current_char == ' ' || current_char == '\n' || current_char == '\t') {
        current_pos++;
        current_char = source_code[current_pos];
    }

    // End of input
    if (current_char == '\0') {
        token->type = TOKEN_END;
        token->value = NULL;
        return token;
    }

    // Handle single-line comments (//)
    if (current_char == '/') {
        // single-line comment
        if (source_code[current_pos + 1] == '/') { // Single-line comment
            while (source_code[current_pos] != '\n' && source_code[current_pos] != '\0') {
                current_pos++;
            }
            return lexer_next_token(); // Skip to the next token
        }
        
        // multi-line comment
        if (source_code[current_pos + 1] == '*') { // Multi-line comment
            current_pos += 2; // Skip '/*'
            while (!(source_code[current_pos] == '*' && source_code[current_pos + 1] == '/')) {
                if (source_code[current_pos] == '\0') {
                    token->type = TOKEN_ERROR;
                    token->value = "Unterminated multi-line comment";
                    return token;
                }
                current_pos++;
            }
            current_pos += 2; // Skip '*/'
            return lexer_next_token(); // Continue tokenizing after the comment
        }
    }

    // Handle numbers (int and float)
    if (current_char >= '0' && current_char <= '9') {
        size_t start_pos = current_pos;
        while ((source_code[current_pos] >= '0' && source_code[current_pos] <= '9') || source_code[current_pos] == '.') {
            current_pos++;
        }
        size_t length = current_pos - start_pos;
        token->value = strndup(&source_code[start_pos], length);
        token->type = (strchr(token->value, '.') ? TOKEN_FLOAT : TOKEN_INT);
        return token;
    }

    // Handle strings (enclosed in double quotes)
    if (current_char == '"') {
        size_t start_pos = ++current_pos;
        while (source_code[current_pos] != '"' && source_code[current_pos] != '\0') {
            current_pos++;
        }
        if (source_code[current_pos] == '"') {
            size_t length = current_pos - start_pos;
            token->value = strndup(&source_code[start_pos], length);
            token->type = TOKEN_STRING;
            current_pos++; // Skip closing quote
            return token;
        } else {
            token->type = TOKEN_ERROR;
            token->value = "Unterminated string literal";
            return token;
        }
    }

    // Handle identifiers and keywords
    if ((current_char >= 'a' && current_char <= 'z') || (current_char >= 'A' && current_char <= 'Z') || current_char == '_') {
        size_t start_pos = current_pos;
        while ((source_code[current_pos] >= 'a' && source_code[current_pos] <= 'z') || 
               (source_code[current_pos] >= 'A' && source_code[current_pos] <= 'Z') ||
               (source_code[current_pos] >= '0' && source_code[current_pos] <= '9') || 
               source_code[current_pos] == '_') {
            current_pos++;
        }
        size_t length = current_pos - start_pos;
        token->value = strndup(&source_code[start_pos], length);
        
        // Check if the identifier is a keyword
        for (int i = 0; i < KEYWORDS_COUNT; i++) {
            if (strcmp(token->value, keywords[i]) == 0) {
                token->type = TOKEN_KEYWORD;
                return token; // Return immediately when it's a keyword
            }
        }
        
        // If not a keyword, treat it as an identifier
        token->type = TOKEN_IDENTIFIER;
        return token;
    }

    // Handle operators and punctuation
    switch (current_char) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '=':
        case '<':
        case '>':
            token->type = TOKEN_OPERATOR;
            token->value = strndup(&source_code[current_pos], 1);
            current_pos++;
            return token;
        case ';':
        case ',':
        case ':':
        case '(':
        case ')':
        case '{':
        case '}':
            token->type = TOKEN_PUNCTUATION;
            token->value = strndup(&source_code[current_pos], 1);
            current_pos++;
            return token;
        default:
            token->type = TOKEN_ERROR;
            token->value = "Unknown character";
            return token;
    }
}

// Function to free lexer resources
void lexer_free() {
    free(source_code);
}
