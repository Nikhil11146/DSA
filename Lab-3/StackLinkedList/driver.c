#include "header.h"

int main() {
    stack s1;
    stack *s = &s1;
    init(s);
    int a, n;

    printf("Enter No of Elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter Element %d: ", (i+1));
        scanf("%d", &a);
        push(s, a);
    }

    while(!isEmpty(s)) {
        pop(s, &a);
        printf("Element: %d\n", a);
    }
    
}