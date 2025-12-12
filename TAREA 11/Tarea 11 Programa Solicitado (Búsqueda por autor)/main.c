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
} Libro;

Libro* CrearLibro();
void agregarLibro(Libro **inicio);
void imprimirLista(Libro *inicio);
void buscarPorTitulo(Libro *inicio, char *clave);
void buscarPorAutor(Libro *inicio, char *autor);
void bubbleSortPrecio(Libro **inicio);
void guardarArchivo(Libro *inicio, char *nombre);
void leerArchivo(Libro **inicio, char *nombre);


int main()
{
    Libro *lista = NULL;
    int opcion;
    char texto[100];

    /*Leer los datos guardados en el disco*/
    leerArchivo(&lista, "libros.txt");

    do
    {
        printf("\n----------MENU----------\n");
        printf("1. Agregar libro\n");
        printf("2. Mostrar lista de libros\n");
        printf("3. Buscar por titullo\n");
        printf("4. Buscar por autor\n");
        printf("5. Ordenar lista por precio\n");
        printf("6. Guardar y salir\n");
        printf("Seleccione una Opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpieza del Buffer

        switch(opcion)
        {
        case 1:
            agregarLibro(&lista);
            break;

        case 2:
            imprimirLista(lista);
            break;

        case 3:
            printf("Ingrese titulo o parte del titulo: ");
            fgets(texto, 100, stdin);
            texto[strcspn(texto, "\n")] = 0;
            buscarPorTitulo(lista, texto);
            break;

        case 4:
            printf("Ingrese el autor a buscar: ");
            fgets(texto, 100, stdin);
            texto[strcspn(texto, "\n")] = 0;
            buscarPorAutor(lista, texto);
            break;

        case 5:
            bubbleSortPrecio(&lista);
            printf("Lista ordenada por precio. \n");
            break;

        case 6:
            guardarArchivo(lista, "libros.txt");
            printf("Datos guardados. Cerrando...\n");
            break;

        default:
            printf("Opcion no valida.\n");
        }
        } while (opcion != 6 );
        return 0;
}

//Para crear un libro nuevo y devolverlo
Libro* crearLibro()
{
    Libro *nuevo = (Libro*)malloc(sizeof(Libro));
    if(!nuevo)
    {
        printf("ERROR: Memoria insuficiente. \n");
        exit(1);
    }
    printf("Ano: ");
    scanf("%d", &nuevo->ano);
    getchar();

    printf("Autor: ");
    fgets(nuevo->autor, 100, stdin);

    printf("Titulo: ");
    fgets(nuevo->titulo, 100,stdin);

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

//Agregar al inicio de la lista

void agregarLibro(Libro **inicio)
{
    Libro *nuevo = crearLibro();
    nuevo->sig = *inicio;
    *inicio = nuevo;
}


//Imprimir todo el listado

void imprimirLista(Libro *inicio)
{
    if (!inicio)
    {
        printf("\nLa lista esta vacia.\n");
        return;
    }

    int i = 1;
    Libro *aux = inicio;

    while (aux)
    {
        printf("\n-------LIBRO-------\n");
        printf("Ano: %d\n", aux->ano);
        printf("Autor: %s\n", aux->autor);
        printf("Titulo: %s\n", aux->titulo);
        printf("Descripcion: %s\n", aux->descripcion);
        printf("Precio: %.2f\n", aux->precio);
        printf("Codigo: %d\n", aux->codigo);

        aux = aux->sig;
    }
}

//Buscar por titulo
void buscarPorTitulo(Libro *inicio, char *clave)
{
    Libro *aux = inicio;
    int encontrado = 0;

    while(aux)
    {
        if (strstr(aux->titulo,clave))
        {
            printf("\n--- ENCONTRADO ---\n");
            printf("Titulo: %s\n", aux->titulo);
            printf("Autor: %s\n", aux->autor);
            printf("Precio: %.2f\n", aux->precio);
            encontrado = 1;
        }
        aux = aux->sig;
        }

    if (!encontrado)
        printf("No hay coincidencias.\n");
}

//Buscar por Autor
void buscarPorAutor(Libro *inicio, char *autor)
{
    Libro *aux = inicio;
    int encontrado = 0;

    while (aux)
    {
        if (strcasecmp(aux->autor, autor) == 0)
        {
            printf("--- LIBRO DEL AUTOR ENCONTRADO ---");
            printf("Autor: %s\n", aux->autor);
            printf("Titulo: %s\n", aux->titulo);
            printf("Precio: %.2f\n", aux->precio);
            printf("Ano: %d\n", aux->ano);
            printf("Codigo: %d\n", aux->codigo);
            printf("Descripcion: %s\n", aux->descripcion);
            encontrado =  1;
        }
        aux = aux->sig;
    }
   if (!encontrado)
    printf("No hay libros de ese autor.\n");
}


//Ordenar por precio con Bubblesort
void bubbleSortPrecio(Libro **inicio)
{
    if (*inicio == NULL)
        return;

    int cambiado;
    Libro *actual;
    Libro *ultimo = NULL;

    do
    {
        cambiado = 0;
        actual = *inicio;

        while (actual->sig !=ultimo)
        {
            if (actual->precio > actual ->sig->precio)
            {

            //Intercambio de los datos
            float precioTemp = actual->precio;
            actual->precio = actual ->sig->precio;
            actual->sig->precio = precioTemp;

            int anoTemp = actual->ano;
            actual->ano = actual->sig->ano;
            actual->sig->ano = anoTemp;

            int codigoTemp = actual->codigo;
            actual->codigo= actual->sig->codigo;
            actual->sig->codigo =codigoTemp;

            char autorTemp[100], tituloTemp[100], descTemp[200];

            strcpy(autorTemp, actual->autor);
            strcpy(actual->autor, actual->sig->autor);
            strcpy(actual->sig->autor, autorTemp);

            strcpy(tituloTemp, actual->titulo);
            strcpy(actual->titulo, actual->sig->titulo);
            strcpy(actual->sig->titulo, tituloTemp);

            strcpy(descTemp, actual->descripcion);
            strcpy(actual->descripcion, actual->sig->descripcion);
            strcpy(actual->sig->descripcion, descTemp);

            cambiado = 1;
        }
        actual = actual->sig;
    }
    ultimo = actual;

  }while (cambiado);
}

//Guardar la lista en un archivo
void guardarArchivo(Libro *inicio, char *nombre)
{
    FILE *f = fopen(nombre, "w");
    if (!f)
    {
        printf("Error al guardar archivo.\n");
        return;
    }

    Libro *aux = inicio;
    while (aux)
    {
        fprintf(f, "%d|%s|%s|%s|%.2f|%d\n",
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

//Leer archivo a la memoria
void leerArchivo(Libro **inicio, char *nombre)
{
    FILE *f = fopen(nombre, "r");
    if (!f) return;

    char linea[400];

    while (fgets(linea, sizeof(linea), f))
    {
        Libro *nuevo = (Libro*)malloc(sizeof(Libro));

        sscanf(linea, "%d|%[^|]|%[^|]|%[^|]|%f|%d",
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
