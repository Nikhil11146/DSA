#include "stack.c"

int main() {
    struct stack s;
    init(&s);
    int size;
    printf("Enter Size: ");
    scanf("%d", &size);

    int **board = (int**)calloc(size,sizeof(int*));
    int end;
    for( int i = 0; i < size; i++) {
        board[i] = (int)calloc(size, sizeof(int));
    }

    
}

int safe(int **board, int size, int row, int col) {
    for(int i = 0; i < size; i++){
        if(board[row][i] == 1 || board[i][col]) return 0;
    }
}

void n_queen(int **board, struct stack *s, int size, int r) {
    int row, col;
    for(int i = row; i < size; i++){
        if(safe(board, size, row, i));
    }   
}