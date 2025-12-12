#include <stdio.h>
#include <stdlib.h>

typedef struct N { int v; struct N *sig; } N;

void add(N **l, int x)
{
    N *n = malloc(sizeof(N));
    n->v = x;
    n->sig= *l;
    *l = n;
}

void print(N *l)
{
    for(; l; l = l->sig)
    printf("%d", l->v);
}

int main()
{
    N *lista = NULL;
    add(&lista, 10);
    add(&lista, 20);
    add(&lista, 30);
    print(lista);
}
