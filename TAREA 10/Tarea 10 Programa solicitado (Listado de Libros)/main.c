#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Libro
{
    int ano;
    char autor[100];
    char titulo[100];
    char descripcion[200];
    float precio;
    int codigo;
    struct Libro *sig;
}
Libro;

//Prototipos
Libro* crearLibro();
void agregarLibro(Libro **inicio);
void mostrarLibros(Libro *inicio);
void buscar(Libro *inicio, char *clave);
void guardarArchivo(Libro *inicio, char *nombre);
void leerArchivo(Libro **inicio, char *nombre);

int main()
{
    Libro *lista = NULL;
    int opcion;
    char clave[100];

    leerArchivo(&lista, "libros.txt");

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Agregar Libro\n");
        printf("2. Mostrar lista completa\n");
        printf("3. Buscar por titulo o autor\n");
        printf("4 guardar y salir\n");
        printf("Seleccione: \n");
        scanf("%d", &opcion);
        getchar();

        switch(opcion)
        {
        case 1: agregarLibro(&lista); break;

        case 2: mostrarLibros(lista); break;

        case 3:
            printf("Introduzca textos a busca: ");
            fgets(clave, 100, stdin);
            clave[strcspn(clave, "\n")] = 0;
            buscar(lista, clave);
            break;

        case 4:
            guardarArchivo(lista, "libros.txt");
            printf("Datos guardados.\n");
            break;
        default: printf("Opcion no valida.\n");
    }
}
while(opcion != 4);
return 0;
}

Libro* crearLibro()
{
    Libro *nuevo = (Libro*)malloc(sizeof(Libro));
    if (!nuevo)
    {
        printf("Error de memoria.\n");
        exit(1);
    }
    printf("Ano: ");
    scanf("%d", &nuevo->ano);
    getchar();

    printf("Autor:  ");
    fgets(nuevo->autor, 100, stdin);

    printf("Titulo: ");
    fgets(nuevo->titulo, 100, stdin);

    printf("Descripcion: ");
    fgets(nuevo->descripcion, 200, stdin);

    printf("Precio: ");
    scanf("%f", &nuevo->precio);

    printf("Codigo: ");
    scanf("%d", &nuevo->codigo);
    getchar();

    nuevo->autor[strcspn(nuevo->autor, "\n")] = 0;
    nuevo->titulo[strcspn(nuevo->titulo, "\n")] = 0;
    nuevo->descripcion[strcspn(nuevo->descripcion, "\n")] = 0;

    nuevo->sig = NULL;
    return nuevo;
}

void agregarLibro(Libro **inicio)
 {
     Libro *nuevo = crearLibro();
     nuevo->sig = *inicio;
     *inicio = nuevo;
}
void mostrarLibros(Libro *inicio)
{
    if(!inicio)
    {
        printf("Lista Vacia.\n");
        return;
    }
    Libro *aux = inicio;
    while (aux)
    {
        printf("\n----LIBRO----\n");
        printf("Ano: %d\n", aux->ano);
        printf("Autor: \n", aux->autor);
        printf("Titulo: \n", aux->titulo);
        printf("Descripcion: \n", aux->descripcion);
        printf("Precio: \n", aux->precio);
        printf("Codigo: \n", aux->codigo);
        aux = aux->sig;
    }
}

void buscar(Libro *inicio, char *clave)
{
    Libro *aux = inicio;
    int encontrado = 0;

    while (aux)
    {

        if(strstr(aux->titulo, clave) || strstr(aux->autor, clave))
        {
            printf("\n-----RESULTADOS-----\n");
            printf("Titulo: %s\n", aux->titulo);
            printf("Autor: %s\n", aux->autor);
            printf("Precio: %.2f\n", aux->precio);
            encontrado = 1;
        }
        aux = aux->sig;
    }
if (!encontrado)
    printf("No se encontraron coincidencias.\n");
}

void guardarArchivo(Libro *inicio, char *nombre)
{
    FILE *f = fopen(nombre, "w");
    if(!f)
    {
        printf("Error al guardar archivo\n");
    }
    Libro *aux = inicio;
    while (aux)
    {
        fprintf(f, "%d|%s|%s|%s|%f|%d\n",
                aux->ano,
                aux->autor,
                aux->titulo,
                aux->descripcion,
                aux->precio,
                aux->codigo);
                aux = aux->sig;
    }
    fclose(f);
}
void leerArchivo(Libro **inicio, char *nombre)
{
    FILE *f = fopen(nombre, "r");
    if(!f) return;

    char linea[400];
    while (fgets(linea, sizeof(linea), f))
    {
        Libro *nuevo = (Libro*)malloc(sizeof(Libro));
        scanf(linea, "%d|%[^|]|%[^|]|%[^|]|%f|%d",
              &nuevo->ano,
              nuevo->autor,
               nuevo->titulo,
               nuevo->descripcion,
               &nuevo->precio,
               &nuevo->codigo);

            nuevo->sig = *inicio;
            *inicio = nuevo;
    }
    fclose(f);
}
