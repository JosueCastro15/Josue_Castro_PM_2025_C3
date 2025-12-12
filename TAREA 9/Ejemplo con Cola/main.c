#include <stdio.h>
#define MAX 5

int cola[MAX];
int frente = 0, fin = -1, size = 0;

void enqueue(int x)
{
    if(size < MAX)
    {
        fin = (fin + 1) % MAX;
        cola[fin] = x;
        size++;
    }
}

int dequeue()
{
    if(size > 0)
    {
        int v = cola[frente];
        frente = (frente + 1)% MAX;
        size--;
        return v;
    }
    return -1;
}

int main()
   {
       enqueue(1);
       enqueue(2);
       printf("%d\n", dequeue);
       printf("%d\n", dequeue);
   }
