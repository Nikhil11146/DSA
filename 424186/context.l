%{
#include <stdio.h>
int begin_context = 0;
%}

%%
"begin" {
    if(begin_context)
        printf("KEYWORD(begin)\n");
    else
        printf("IDENTIFIER(begin)\n");
    begin_context = 1;
}

"end" {
    if(begin_context)
        printf("KEYWORD(end)\n");
    else
        printf("ERROR → end used incorrectly\n");
    begin_context = 0;
}

[a-zA-Z][a-zA-Z0-9]*   printf("IDENTIFIER(%s)\n", yytext);
. ;
%%

int main() {
    yylex();
    return 0;
}