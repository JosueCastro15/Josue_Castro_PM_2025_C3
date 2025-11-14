#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define ARCHIVO "inventario.txt"

typedef struct {

char nombre[MAX_NOMBRE];
float precio;
int cantidad;

} Producto;

Producto* CargarInventario(int *n);
void imprimirInventario(Producto *inv, int n);
void agregarProducto(Producto **inv, int *n);
void guardarInventario(Producto *inv, int n);

int main()
{
int nProductos = 0;
Producto *inventario = CargarInventario(&nProductos);

int opciones;

printf("Le gustaria agreagar algun nuevo producto? (1=si, 0=N):  ");
scanf("%d", &opciones);
getchar();

if (opciones == 1)
{
    agregarProducto(&inventario, &nProductos);
    guardarInventario(inventario, nProductos);
 printf("Su Producto ha sido Agregado y actualizado en la lista.\n");
}

printf("Desea imprimir el inventario? (1=si, 0=N):  ");
 scanf("%d", &opciones);

 if (opciones == 1)
 {
     imprimirInventario(inventario, nProductos);
 }

 free(inventario);
 return 0;
 }

 Producto* CargarInventario(int *n)
 {
     FILE *fp = fopen(ARCHIVO, "r");
      if(!fp)
      {
        printf("Archivo no se pudo encontrar, se hara uno nuevo.\n");
        *n = 0;
        return NULL;
      }

    Producto temp;
    Producto *inv = NULL;
    *n =0;

  while (fscanf(fp, "%s %f %d", temp.nombre, &temp.precio, &temp.cantidad) == 3)
  {
    inv = realloc(inv, (*n + 1) * sizeof(Producto));
    inv[*n] = temp;
    (*n)++;
  }

  fclose(fp);
  return inv;
 }

 void imprimirInventario(Producto *inv, int n)
 {
 if (n == 0 || inv == NULL){
    printf("El inventario se encuentra vacio.\n");
    return;
 }

 printf("\n----INVENTARIO----\n");
 for (int i = 0; i < n; i++)
 {
     printf("%d) %s - Precio: %.2f - Cantidad: %d\n",
            i + 1, inv[i].nombre, inv[i]. precio, inv[i].cantidad);
 }
 }


 void agregarProducto(Producto **inv, int *n)
 {
     Producto nuevo;

   printf("Ingrese el nombre del producto: ");
   scanf("%s", nuevo.nombre);

   printf("Ingrese el precio: ");
   scanf("%f", &nuevo.precio);

   printf("Ingrese cantidad: ");
   scanf("%d", &nuevo.cantidad);

   *inv = (Producto*)realloc(*inv, (*n+1) * sizeof(Producto));
   (*inv)[*n] = nuevo;
   (*n)++;
 }

 void guardarInventario(Producto *inv, int n)
 {
     FILE *fp = fopen(ARCHIVO, "w");

     for (int i = 0; i < n; i++)
     {
         fprintf(fp, "%s %.2f %d\n", inv[i].nombre,
                 inv[i].precio, inv[i].cantidad);
     }

     fclose(fp);
 }
