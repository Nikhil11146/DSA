#include <stdio.h>
#include <string.h>

#define MAX 100
#define ACCEPT 999
char input[MAX] = "**id=*id$";

int stack[MAX];
int top = 0, ip = 0;

int ACTION[8][4] = {
 { 5,  4,  0,  0 },    
 { 0,  0,  0, ACCEPT },
 { 0,  0,  6, -2 },    
 { 0,  0, -5, -5 },    
 { 5,  4,  0,  0 },   
 { 0,  0, -4, -4 },   
 { 5,  4,  0,  0 },   
 { 0,  0, -1, -1 }    
};
int GOTO[8][3] = {
 { 1, 2, 3 },
 { 0, 0, 0 },
 { 0, 0, 0 },
 { 0, 0, 0 },
 { 0, 7, 3 },
 { 0, 0, 0 },
 { 0, 7, 3 },
 { 0, 0, 0 }
}
int prod_len[] = {0, 3, 1, 2, 1, 1};
char prod_lhs[] = {' ', 'S', 'S', 'L', 'L', 'R'};

int term_col(char c) {
    if (c == 'i') return 0;   
    if (c == '*') return 1;
    if (c == '=') return 2;
    return 3;               
}

int goto_col(char c) {
    if (c == 'S') return 0;
    if (c == 'L') return 1;
    return 2;                
}

void print_stack() {
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
}

int main() {
    stack[top] = 0;

    printf("\nSTACK\t\tINPUT\t\tACTION\n");

    while (1) {
        int state = stack[top];
        int col = term_col(input[ip]);
        int act = ACTION[state][col];

        print_stack();
        printf("\t\t%s\t\t", &input[ip]);

        if (act > 0) {             
            printf("Shift %d\n", act);
            stack[++top] = act;
            ip += (input[ip] == 'i') ? 2 : 1; // skip "id"
        }
        else if (act < 0) {       
            int rule = -act;
            printf("Reduce by %c (rule %d)\n", prod_lhs[rule], rule);

            top -= prod_len[rule];
            int prev = stack[top];
            stack[++top] = GOTO[prev][goto_col(prod_lhs[rule])];
        }
        else if (act == ACCEPT) {
            printf("ACCEPT\n");
            break;
        }
        else {
            printf("ERROR\n");
            break;
        }
    }
    return 0;
}