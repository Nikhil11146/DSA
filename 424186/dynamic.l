%{

#include <stdio.h>

typedef enum {
    DEC_MODE,   
    BIN_MODE,   
    HEX_MODE    
} Modes;

Modes MODE = DEC_MODE;
%}

%%

"mode1"         {
    MODE = BIN_MODE;
    printf("[Mode switched to Binary]\n");
}

"mode2"         {
    MODE = HEX_MODE;
    printf("[Mode switched to Hexadecimal]\n");
}

[0-9A-Za-z]*    {
    if (MODE == DEC_MODE) {
        int valid = 1;
        for (int i = 0; yytext[i]; i++) {
            char c = yytext[i];
            if (!(c >= '0' && c <= '9')) {
                valid = 0;
                break;
            }
        }
        if (valid)
            printf("NUMBER -> %s\n", yytext);
        else
            printf("ERROR -> Invalid number: %s\n", yytext);
    } else if (MODE == BIN_MODE) {
        if (yytext[0] == '0' || yytext[0] == '1') {
            int valid = 1;
            for (int i = 0; yytext[i]; i++) {
                if (yytext[i] != '0' && yytext[i] != '1') {
                    valid = 0;
                    break;
                }
            }

            if (valid)
                printf("BIN_NUMBER -> %s\n", yytext);
            else
                printf("ERROR -> Invalid binary number: %s\n", yytext);
        } else {
            printf("ERROR -> Invalid binary number: %s\n", yytext);
        }
    } else if (MODE == HEX_MODE) {
        int valid = 1;
        for (int i = 0; yytext[i]; i++) {
            char c = yytext[i];
            if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
                valid = 0;
                break;
            }
        }
        if (valid)
            printf("HEX_NUMBER -> %s\n", yytext);
        else
            printf("ERROR -> Invalid hexadecimal number: %s\n", yytext);
    }
}

.|\n            ;   /* Ignore other input */

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}