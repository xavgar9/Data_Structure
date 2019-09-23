/*
 * Autor: Jhoan Lozano, Xavier Garzón, Cristian Osorio
 * Fecha de creación: 12 de mayo de 2017
 * Fecha última modificación: 25 de mayo de 2017
 * Versión: 1.0
 * 
 * Archivo encabezado libreria TAD Matrizz Dispersa
 * Representación mediante Formato Comprimido
 */

#ifndef __VECTORES_H
#define __VECTORES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
/************************
* ESTRUCTURAS DE DATOS *
************************/
typedef int TipoElemento;

struct lista{
   TipoElemento datos[MAX];
   TipoElemento filas[MAX];
   TipoElemento cols[MAX];
};

typedef struct lista TipoLista;

/************************
* OPERACIONES DEL TAD *
************************/

/* Constructoras */
TipoLista CrearLista();
TipoLista CrearMatriz1(int m, int n);
TipoLista CreardeMatrizCompleta(int **Mtz, int m, int n);
int **ConvertirMatrizDeListasAArreglos(TipoLista Matriz,int m,int n);
TipoLista ProductoVector(TipoLista Matriz, TipoLista Vector, int m, int n);
TipoLista Transponer(TipoLista Matriz);
TipoLista sumar(TipoLista Matriz,TipoLista Matriz1);

/* Modificadoras */
TipoLista organice(TipoLista Matriz1,int range);
TipoLista organicebyrows(TipoLista Matriz1);
TipoLista OrganizarCols(TipoLista Lista);
TipoLista modificarelemento(TipoLista matriz, int fil,int col,int value);

/* Analizadoras */
int LongLista(TipoLista lst);
int obtenerele(TipoLista matriz,int fil,int col);
TipoLista obtenerfilasinceros(TipoLista matriz, int fil);
TipoLista obtenercolsinceros(TipoLista matriz, int col);
int * obtenerfilaconceros(TipoLista matriz,int fil,int n);
int * obtenercolconceros(TipoLista matriz,int col,int m);
void ImprimirMatrizLista(TipoLista Matriz);
void ImprimirMatrizArreglos(int **Mtz, int m, int n);
#endif
