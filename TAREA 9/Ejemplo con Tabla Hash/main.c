#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct N
{
    char k[20];
    int v;
    struct N *sig;
}
N;
N *tabla[TAM] = {0};

int hash(char *s)
{
    int h = 0;
    while (*s) h += *s++;
    return h % TAM;
}

void put(char *k, int v)
{
    int h = hash(k);
    N *n = malloc(sizeof(N));
    strcpy(n->k, k);
    n->v = v;
    n->sig = tabla[h];
    tabla[h] = n;
}

int get(char *k)
{
    for (N *n = tabla[hash(k)]; n; n = n->sig)
        if (!strcmp(n->k, k))return n->v;
    return -1;
}
int main()
{
    put("Ana", 30);
    put("Luis", 25);
    printf("%d\n", get("Ana"));
}
