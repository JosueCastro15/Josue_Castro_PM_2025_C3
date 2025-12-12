#include <stdio.h>
#include <stdlib.h>

typedef struct N
{
    int v; struct N *sig;
}
N;

void addEdge(N *g[], int u, int v)
{
    N *n = malloc(sizeof(N));
    n->v = v; n->sig = g[u];
    g[u] = n;
}

void printG(N *g[], int V)
{
    for (int i = 0; i < V; i++)
    {
        printf("%d: ", i);

        for(N *p = g[i]; p; p = p->sig)
            printf("%d", p->v);
        printf("\n");

    }
}


int main()
{
int V = 4;
N *g[4] = {NULL};

addEdge(g, 0, 1);
addEdge(g, 0, 2);
addEdge(g, 1, 3);

printG(g, V);
}
