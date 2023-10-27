#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
    char materia[40];
    int idMateria;
} registroArchivo;

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
} notaAlumno;

typedef struct _nodo
{
    notaAlumno dato;
    struct _nodo *siguiente;
} nodo;

typedef struct celda
{
    int idMateria;
    char materia[40];
    nodo * listaDeNotas;
} celda;



/// PROTOTIPADO

nodo* inicLista();
int agregarMateria (celda arrayMat[], int validos, char materiaAgre[]);
int buscarPorMateria (celda arrayMat[], int validos, char materiaBus[]);
nodo* agregarPpio(nodo* arrayLista,nodo* nuevo);
int agregarNotas (celda arrayMat[], int dim);
notaAlumno cargarInfo();
int alta (celda arrayMat[], notaAlumno informacion, int validos, char materiaBus[]);
nodo* crearNodo (notaAlumno informacion);
void mostrarMateria (celda arrayMat [], char materiaMostrar[], int validos);

int main()
{


    celda arrayMaterias[10];




    return 0;
}

nodo* inicLista()
{
    return NULL;
}

int agregarMateria (celda arrayMat[], int validos, char materiaAgre[])
{
    strcpy(arrayMat[validos].materia, materiaAgre);

    arrayMat[validos].listaDeNotas= inicLista();

    validos++;

    return validos;
}

int buscarPorMateria (celda arrayMat[], int validos, char materiaBus[])
{
    int i=0;
    int rta=-1;

    while (i<validos && rta==-1)
    {
        if(strcmp(arrayMat[i].materia, materiaBus)==0)
            rta=i;
        i++;
    }

    return rta;
}

nodo* agregarPpio(nodo* arrayLista,nodo* nuevo)
{
    if(arrayLista ==NULL)
    {
        arrayLista= nuevo;
    }
    else
    {
        nuevo->siguiente= arrayLista;
        arrayLista = nuevo;
    }

    return arrayLista;
}


int agregarNotas (celda arrayMat[], int dim)
{
    notaAlumno informacion = cargarInfo();
    char op='s';
    int validos=0;
    char materiaAgre[20];

    while (op=='s' && validos<dim)
    {
        informacion = cargarInfo();
        printf("\nIngrese la materia: ");
        fflush(stdin);
        gets(materiaAgre);
        validos= alta(arrayMat,  informacion, validos,materiaAgre);
        printf("\nIngrese S si desea cont: ");
        fflush(stdin);
        scanf("%c", &op);

    }

    return validos;
}

notaAlumno cargarInfo()
{
    notaAlumno informacion;

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(informacion.nombreApe);
    printf("\nIngrese nota del alumno");
    scanf("%i", &informacion.nota);
    printf("\nIngrese legajo del alumno");
    scanf("%i", &informacion.legajo);

    return informacion;
}


int alta (celda arrayMat[], notaAlumno informacion, int validos, char materiaBus[])
{
    nodo* aux= crearNodo (informacion);
    int pos= buscarPorMateria(arrayMat,validos,materiaBus);

    if(pos==-1)
    {
        validos= agregarMateria(arrayMat,validos,materiaBus);
        pos=validos-1;
    }

    arrayMat[pos].listaDeNotas= agregarPpio(arrayMat[pos].listaDeNotas, aux);

    return validos;
}

nodo* crearNodo (notaAlumno informacion)
{
    nodo* aux= (nodo*)malloc(sizeof(nodo));
    strcpy(informacion.nombreApe, aux->dato.nombreApe);
    aux->dato.nota=informacion.nota;
    aux->dato.legajo=informacion.legajo;

    return aux;
}



void mostrarMateria (celda arrayMat [], char materiaMostrar[], int validos)
{
    int pos= buscarPorMateria(arrayMat,validos,materiaMostrar);
    nodo* seg= arrayMat[pos].listaDeNotas;

    while(seg->siguiente!= NULL && pos!=-1)
    {
        printf("\Nombre: %s", seg->dato.nombreApe);
        printf("\Legajo: %i", seg->dato.legajo);
        printf("\Nota: %i", seg->dato.nota);
        seg= seg->siguiente;
    }
}
