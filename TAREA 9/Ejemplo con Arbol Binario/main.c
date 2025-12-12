#include <stdio.h>
#include <stdlib.h>

typedef struct A
{
    int v; struct A *l, *r;
}
A;

A* nuevo(int x)
{
    A *n = malloc(sizeof(A));
    n->v = x; n->l = n->r =NULL;
    return n;
}

void ins(A **t, int x)
{
    if (!*t) *t = nuevo(x);
    else if (x < (*t)->v) ins(&(*t)->l, x);
    else ins(&(*t)->r, x);
}

void inorder(A *t)
{
    if (!t) return;
    inorder(t->l);
    printf("%d",t->v);
    inorder(t->r);
}

int main()
{
    A *raiz = NULL;
    ins(&raiz, 8);
    ins(&raiz, 3);
    ins(&raiz, 10);
    inorder(raiz);
}
