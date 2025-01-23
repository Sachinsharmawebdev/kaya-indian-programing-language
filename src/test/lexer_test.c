#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

void test_lexer(const char* source) {
    Token* token = lexer_init(source);
    while (token->type != TOKEN_END) {
        printf("Token Type: %d, Value: %s\n", token->type, token->value);
        free(token->value);
        free(token);
        token = lexer_next_token();
    }
    free(token);
}

int main() {
    const char* test_code = "// This is a single-line comment\n/*\n    This is a multi-line comment\n    that spans multiple lines.\n*/\n\nfn add(a, b) {\n    return a + b;  // Adding two numbers\n}\n\nfn main() {\n    int x = 10;\n    int y = 20;\n    \n    // Function call\n    int result = add(x, y);\n    \n    if (result > 0) {\n        print(\"The result is positive.\");\n    } else {\n        print(\"The result is non-positive.\");\n    }\n\n    // Example of a loop\n    for (int i = 0; i < 5; i++) {\n        print(i);\n    }\n    \n    // A complex expression\n    int z = (x * y) / (result + 1);\n    \n    // Typecast example\n    float f = (float) x;\n    \n    // Checking string literal\n    string message = \"Kaya is awesome!\";\n    print(message);\n    \n    // Using an operator and assigning value\n    x += 5;\n    y *= 2;\n    \n    // End of the program\n    return 0;\n}"
;
    test_lexer(test_code);
    lexer_free();
    return 0;
}
