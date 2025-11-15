#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define ARCH_VEH "Lista del costo de vehiculos.txt"
#define ARCH_COMB "Lista de combustibles.txt"

typedef struct
{
int ID;
char Marca[MAX_NOMBRE];
char Modelo[MAX_NOMBRE];
int Ano;
char Placa[20];
float ConsumoCiudad;
float ConsumoCarretera;
float CostoSeguroAnual;
float CostoCambioPorKm;
int TiempDeprecicion;
float CostodelVehiculo;
float CostoDepreciacion;
float kmPromedioAnual;
float CostoLimpieza;
}
Vehiculo;

typedef struct
{
int ID;
char nombre[30];
float PrecioLitro;
}

Combustible;

void LimpiarBuffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF) {}
}

Vehiculo* CargarVehiculos(int *n)
{
    *n = 0;
    FILE *f = fopen(ARCH_VEH, "r");
    if (!f) return NULL;
        Vehiculo *arr = NULL;

    while(1)
    {
        Vehiculo v;
        if (fscanf(f, "%d|%49[^|]|%49[^|]|%d|%19[^|]|%f|%f|%f|%f|%d|%f|%f|%f\n",
                   &v.ID,v.Marca,v.Modelo, &v.Ano,v.Placa, &v.ConsumoCiudad,
                   &v.ConsumoCarretera, &v.CostodelVehiculo, &v.kmPromedioAnual, &v.CostoLimpieza,
                   &v.CostoSeguroAnual, &v.CostoCambioPorKm, &v.TiempDeprecicion) != 13)
                break;

    arr = realloc(arr, sizeof(Vehiculo) * (*n + 1));
    arr[*n] = v;
    (*n)++;
    }
    fclose(f);
    return arr;
}

void guardarVehiculos(Vehiculo *arr, int n)
{
    FILE *f = fopen(ARCH_VEH, "w");
    if (!f) return;
    for (int i = 0; i < n; ++i)
    {
        Vehiculo *v = &arr[i];
        fprintf(f,"%d|%s|%s|%d|%s|%.3f|%.3f|%.2f|%.5f|%d|%.2f|%.2f|%.2f\n",
                v->ID,v->Marca,v->Modelo,v->Ano,v->Placa,v->ConsumoCiudad,
                v->ConsumoCarretera,v->CostoSeguroAnual,v->CostoCambioPorKm,
                v->TiempDeprecicion,v->CostodelVehiculo,v->kmPromedioAnual,
                v->CostoLimpieza);
    }
    fclose(f);
}
Combustible* CargarCombustibles(int *n)
{
    *n = 0;
    FILE *f = fopen(ARCH_COMB, "r");
    if (!f) return NULL;
    Combustible *arr = NULL;

    while (1)
    {
    Combustible c;
    if(fscanf(f,"%d|%29[^|]|%f\n", &c.ID, c.nombre, &c.PrecioLitro) != 3)
            break;
    arr = realloc(arr, sizeof(Combustible) * (*n + 1));
    arr[*n] = c; (*n)++;
    }
    fclose(f);
    return arr;
}

void GuardarCombustible (Combustible *arr, int n)
{
    FILE *f = fopen(ARCH_COMB, "w");
    if (!f)
    return;
    for (int i = 0; i < n; ++i)
    {
     fprintf(f, "%d|%s|%.3f\n", arr[i].ID, arr[i].nombre,arr[i].PrecioLitro);
    }
    fclose(f);
}
int SiguienteIDVehiculo(Vehiculo *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; ++i) if (arr[i].ID > max) max = arr[i].ID;
    return max + 1;
}

int siguientIDcombustible(Combustible *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
    if (arr[i].ID > max) max = arr[i].ID;
    }
    return max + 1;
}


/*Opraciones para los vehiculos*/

void ListadeVechiculos(Vehiculo *arr, int n)
{
    if(!arr || n==0) {printf("No hay vehiculos cargados.\n"); return; }
    printf("\nID | Marca - Modelo - Ano - Placa\n");
    for (int i = 0; i < n; ++i)
    {
        Vehiculo *v = &arr[i];
        printf("%3d | %s - %s - %d - %s\n",v->ID,v->Marca,v->Modelo,
               v->Ano,v->Placa);
    }
}

void AgregarVehiculo(Vehiculo **arr, int *n)
{
    Vehiculo v;
    Vehiculo *a = *arr;
    int next = SiguienteIDVehiculo(a, *n);
    v.ID = next;
    printf("\nAgregando Vehiculo (ID=%d)\n", v.ID);

    printf("Marca: ");
    fgets(v.Marca, MAX_NOMBRE, stdin);
    v.Marca[strcspn(v.Marca, "\n")] = 0;

    printf("Modelo: ");
    fgets(v.Modelo, MAX_NOMBRE, stdin);
    v.Modelo[strcspn(v.Modelo, "\n")] = 0;

    printf("Ano: ");
    scanf("%d", &v.Ano);
    LimpiarBuffer();

    printf("Placa: ");
    fgets(v.Placa, 20, stdin);
    v.Placa[strcspn(v.Placa, "\n")] = 0;

    printf("Consumo ciudad (L/kM): ");
    scanf("%f", &v.ConsumoCiudad);
    LimpiarBuffer();

    printf("Consumo Carretera (L/KM): ");
    scanf("%f", &v.ConsumoCarretera);
    LimpiarBuffer();

    printf("Costo Seguro Anual: ");
    scanf("%f", &v.CostoSeguroAnual);
    LimpiarBuffer();

    printf("Costo cambio por Km: ");
    scanf("%f",&v.CostoCambioPorKm);
    LimpiarBuffer();

    printf("Tiempo depreciacion (Anos): ");
    scanf("%d", &v.TiempDeprecicion); \
    LimpiarBuffer();

    printf("Costo vehiculo: ");
    scanf("%f", &v.CostodelVehiculo);
    LimpiarBuffer();

    printf("Km promedio anual: ");
    scanf("%f", &v.kmPromedioAnual);
    LimpiarBuffer();

    printf("Costo Limpieza por viaje: ");
    scanf("%f", &v.CostoLimpieza);
    LimpiarBuffer();

    *arr = realloc(*arr, sizeof(Vehiculo) * (*n + 1));
    if (!*arr)
        {
        printf("Error de memoria.\n");
       return;
        }
    (*arr)[*n] = v;
    (*n)++;
    guardarVehiculos(*arr, *n);
    printf("Vehiculo agregado correctamente.\n");

}

int BuscarIndiceVehiculo(Vehiculo *arr, int n, int ID)
{
    for (int i = 0; i < n; ++i)
    if(arr[i].ID == ID) return i;
    return -1;
}


void modificarVehiculo (Vehiculo *arr, int n)
{
    if (!arr || n==0)
        {
        printf("No hay vehiculos para modificar.\n");
        return;
        }
    int ID;
    printf("ID del vehiculo a modifacr:  ");
    scanf("%d", &ID); LimpiarBuffer();
    int IDx = BuscarIndiceVehiculo(arr, n, ID);
    if (IDx == -1)
        {
        printf("ID no encontrado.\n");
    return;
        }
    Vehiculo *v = &arr[IDx];
    printf("Modificando vehiculo %d (%s - %s)\n", v->ID, v->Marca, v->Modelo);
    char temp[MAX_NOMBRE];

    printf("Marca (actual: %s) - Enter para mantener: ", v->Marca);
    fgets(temp, MAX_NOMBRE, stdin);
    if (temp[0] != '\n')
    {
        temp[strcspn(temp, "\n")] = 0;
        strcpy(v->Marca, temp);
    }
    printf("Modelo (actual: %s - Enter para mantener: ", v->Modelo);
    fgets(temp, MAX_NOMBRE, stdin);
    if(temp[0] != '\n')
    {
        temp[strcspn(temp, "\n")] = 0;
        strcpy(v->Modelo, temp);
    }
    printf("Ano (Actual: %d) - 0 para mantener: ", v->Ano);
    int x;
    scanf("%d", &x);
    if (x!=0) v->Ano = x;
    LimpiarBuffer();
    printf("Placa (Actual: %s) - enter para manntener: ", v->Placa);
    fgets(temp, 20, stdin); if(temp[0] != '\n')
    {
        temp[strcspn(temp, "\n")] = 0;
        strcpy(v->Placa, temp);
    }
    printf("Consumo ciudad (Actual: %.3f) - negativo para mantener: ", v->ConsumoCiudad);
    float f;
    scanf("%f", &f);
    if (f>=0) v->ConsumoCiudad = f; LimpiarBuffer();

    printf("Consumo carretera (Actual: %.3f) - negativo para mantener: ", v->ConsumoCarretera);
    scanf("%f", &f);
    if (f>=0) v->ConsumoCarretera = f; LimpiarBuffer();

    printf("Costo seguro anual (Actual: %.2f) - negativo para mantener: ", v->CostoSeguroAnual);
    scanf("%f", &f);
    if (f>=0) v->CostoSeguroAnual = f; LimpiarBuffer();

    printf("Costo cambio por km (Actual: %.5f) - negativo para mantener: ", v->CostoCambioPorKm);
    scanf("%f", &f);
    if (f>=0) v->CostoCambioPorKm = f; LimpiarBuffer();

    printf("Tiempodepreciacion anos (Actual: %d) - 0 para mantener: ", v->TiempDeprecicion);
    int xi; scanf("%d", &xi);
    if (xi>0) v->TiempDeprecicion = xi; LimpiarBuffer();

    printf("Costo Vehiculo (Actual: %.2f) - negativo para mantener: ", v->CostodelVehiculo);
    scanf("%f", &f);
    if (f>=0) v->CostodelVehiculo = f; LimpiarBuffer();

    printf("Km promedio anual (Actual: %.2f) - negativo para mantener: ", v->kmPromedioAnual);
    scanf("%f", &f);
    if (f>=0) v->kmPromedioAnual = f; LimpiarBuffer();

    printf("Costo limpieza (Actual: %.2f) - negativo para mantener: ", v->CostoLimpieza);
    scanf("%f", &f);
    if (f>=0) v->CostoLimpieza = f; LimpiarBuffer();

    guardarVehiculos(arr, n);
    printf("Vehiculo modificado.\n");
}

void ListarCombustibles(Combustible *arr, int n)
{
    if (!arr || n==0)
    {
        printf("No hay combustibles cargados.\n");
        return;
    }
    printf("ID | Nombre - Precio/L\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%3d | %s - %.3f\n", arr[i].ID, arr[i].nombre, arr[i].PrecioLitro);
    }
}

void AgregarCombustible(Combustible **arr, int *n)
{
    Combustible c;
    Combustible *a = *arr;
    c.ID = siguientIDcombustible(a, *n);
    printf("\nAgregando combustible (ID=%d)\n", c.ID);
    printf("Nombre: ");
    fgets(c.nombre, 30, stdin);
    c.nombre[strcspn(c.nombre, "\n")] = 0;
    printf("Precio por litro: ");
    scanf("%f", &c.PrecioLitro); LimpiarBuffer();
    *arr = realloc(*arr, sizeof(Combustible) * (*n + 1));
    (*arr)[*n] = c; (*n)++;
    GuardarCombustible(*arr, *n);
    printf("Combustible agregado. \n");
}

int BuscarIndiceCombustible(Combustible *arr, int n, int ID)
{
    for(int i = 0; i < n; ++i)
        if (arr[i].ID == ID) return i;
    return -1;
}

void ModificarCombustible(Combustible *arr, int n)
{
    if (!arr || n==0)
    {
        printf("No hay combustibles para modificar.\n");
        return;
    }
    int ID;
     printf("ID dell combustible a modificar: ");
     scanf("%d", &ID); LimpiarBuffer();

    int IDx = BuscarIndiceCombustible(arr, n, ID);
    if (IDx == -1)
    {
        printf("ID no encontrado.\n");
        return;
    }
    Combustible *c = &arr[IDx];
    char temp[30];
    printf("Nombre (Actual: %s) - enter para mantener: ", c->nombre);
    fgets(temp, 30, stdin);
    if (temp[0] != '\n')
    {
        temp[strcspn(temp, "\n")] = 0;
        strcpy(c->nombre, temp);
    }
    printf("Precio por litro (Actual: %.3f) - negativo para mantener: ", c->PrecioLitro);
    float f; scanf("%f", &f);
    if (f>=0) c->PrecioLitro = f; LimpiarBuffer();
    GuardarCombustible(arr, n);
    printf("Combustible modificado.\n");
}

void CalculoViaje(Vehiculo *veh, int nVeh, Combustible *comb, int nComb)
{
    if (!veh || nVeh==0)
    {
        printf("No hay vehiculos cargados.\n");
        return;
    }
    if (!comb || nComb==0)
    {
        printf("No hay combustibles cargados.\n");
        return;
    }
    ListadeVechiculos(veh, nVeh);
    int IDVeh;
    printf("\nSeleccione ID de vehiculos: ");
    scanf("%d", &IDVeh); LimpiarBuffer();
    int IDxV = BuscarIndiceVehiculo(veh, nVeh, IDVeh);
    if (IDxV == -1)
    {
        printf("Vehiculo no encontrado.\n");
        return;
    }
    ListarCombustibles(comb, nComb);
    int IDComb;
    printf("Seleccione ID de combustible: ");
    scanf("%d", &IDComb); LimpiarBuffer();
    int IDxC = BuscarIndiceCombustible(comb, nComb, IDComb);
    if (IDxC == -1)
    {
        printf("Combustible no encontrado. \n");
        return;
    }
   float km;
   printf("Km del viaje: ");
   scanf("%f", &km); LimpiarBuffer();
   if (km <= 0)
   {
       printf("Km Invalido.\n");
       return;
   }
   float porcCiudad;
   printf("%% de km en ciudad (0-100): ");
   scanf("%f", &porcCiudad); LimpiarBuffer();
   if (porcCiudad < 0) porcCiudad = 0;
   if (porcCiudad > 100) porcCiudad = 100;

   Vehiculo *v = &veh[IDxV];
   Combustible *c = &comb[IDxC];

   float KmCiudad = km * (porcCiudad / 100.0f);
   float KmCarretera = km - KmCiudad;
   float LitrosCiudad = (v->ConsumoCiudad / 100.0f) * KmCiudad;
   float LitrosCarretera = (v->ConsumoCarretera / 100.f) * KmCarretera;
   float LitrosTotales = LitrosCiudad + LitrosCarretera;
   float CostoCombustible = LitrosTotales * c->PrecioLitro;
   float DeperciacionAnual = 0.0f;
   float CostoDepreciacionViaje = 0.0f;

   if(v->TiempDeprecicion > 0 && v->kmPromedioAnual > 0)
   {
       DeperciacionAnual = v->CostodelVehiculo / (float)v->TiempDeprecicion;
       CostoDepreciacionViaje = (DeperciacionAnual / v->kmPromedioAnual) * km;
   }

float CostoSeguro = 0.0f;
if (v->kmPromedioAnual > 0) CostoSeguro = (v->CostoSeguroAnual / v->kmPromedioAnual) * km;

float CostoDesgaste = v->CostoCambioPorKm * km;
float CostoLimpieza = v->CostoLimpieza;
float CostoTotal = CostoCombustible + CostoDepreciacionViaje + CostoSeguro + CostoDesgaste + CostoLimpieza;
float CostoporKm = CostoTotal / km;

printf("\n------RESULTADO DE VIAJE------\n");
printf("Vehiculo: %s %s (ID %d)\n", v->Marca, v->Modelo, v->ID);
printf("Combustible: %s (%.3f por litro)\n", c->nombre, c->PrecioLitro);
printf("Km totales: %.2f (Ciudad: %.2f, Carretera: %.2f)\n", km, KmCiudad, KmCarretera);
printf("Litros consumidos: %.3f (Ciudad: %.3f, carretera: %.3f)\n", LitrosTotales, LitrosCiudad, LitrosCarretera);
printf("Costo Combustible:: %.2f\n", CostoCombustible);
printf("Costo depreciacion (por viaje): %.2f\n", CostoDepreciacionViaje);
printf("Costo seguro (por viaje): %.2f\n", CostoSeguro);
printf("Costo Desgaste (Cambio/uso): %.2f\n", CostoDesgaste);
printf("Costo Limpieza (Por vieje): %.2f\n", CostoLimpieza);
printf("--------------------------------\n");
printf("Costo total del viaje: %.2f\n", CostoTotal);
printf("Costo por Km: %.4f\n", CostoporKm);

}

void menu()
{
    printf("\n------SISTEMA DE COSTO DE VIAJE--------\n");
    printf("1. Agregar Vehiculo\n");
    printf("2. Lista de Vehiculos\n");
    printf("3. Modficar Vehiculo\n");
    printf("4. Agregar Combustible\n");
    printf("5. Modificar Combustible\n");
    printf("6. Lista Combustibles\n");
    printf("7. Calcular Viaje\n");
    printf("0. Salir\n");
    printf("Seleccion: ");
}

int main()
{
    Vehiculo *veh = NULL;
    int nVeh = 0 ;
    Combustible *Comb = NULL;
    int nComb = 0;

    veh = CargarVehiculos(&nVeh);
    Comb = CargarCombustibles(&nComb);

    int op = -1;
    while (op != 0)
    {
      menu();
      if (scanf("%d", &op) != 1)
      {
          LimpiarBuffer();
          continue;
      }
      LimpiarBuffer();

    switch (op)
    {
        case 1: AgregarVehiculo(&veh, &nVeh); break;
        case 2: ListadeVechiculos(veh, nVeh); break;
        case 3: modificarVehiculo(veh, nVeh); break;
        case 4: AgregarCombustible(&Comb, &nComb); break;
        case 5: ModificarCombustible(Comb, nComb); break;
        case 6: ListarCombustibles(Comb, nComb); break;
        case 7: CalculoViaje(veh, nVeh, Comb, nComb); break;
        case 0: printf("Saliendo....\n"); break;
        default: printf("Opcion invalida.\n");
    }
    }

    free(veh);
    free(Comb);
    return 0;
}
