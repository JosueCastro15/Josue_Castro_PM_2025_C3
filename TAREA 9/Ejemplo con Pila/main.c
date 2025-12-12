#include <stdio.h>
#define MAX

int pila[MAX];
int tope = -1;

void push(int x)
{
    if (tope < MAX -1) pila[++tope] = x;
}

int pop()
{
    if(tope >= 0) return pila[tope--];
    return -1;
}

int main()
{
    push(10);
    push(20);
    printf("%d\n", pop());
    printf("%d\n", pop());
}
