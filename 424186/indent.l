%{
#include <stdio.h>
#include <stdlib.h>
int stack[100], top = 0;
int prev_indent = 0;
%}

%%
\n {
    printf("NEWLINE\n");
}

^[ \t]+ {
    int count = 0;
    for(int i=0; yytext[i]; i++) {
        if(yytext[i]==' ') count++;
        else if(yytext[i]=='\t') count+=4;
    }

    if(count > prev_indent) {
        stack[top++] = count;
        printf("INDENT\n");
    }
    else {
        while(top>0 && stack[top-1] > count) {
            top--;
            printf("DEDENT\n");
        }
    }
    prev_indent = count;
}

[a-zA-Z]+   printf("STATEMENT\n");
. ;
%%

int main() {
    yylex();
    return 0;
}