/*
 * Autor: Jhoan Lozano, Xavier Garzón, Cristian Osorio
 * Fecha de creación: 12 de mayo de 2017
 * Fecha última modificación: 25 de mayo de 2017
 * Versión: 1.0
 * 
 * Archivo encabezado libreria TAD Matrizz Dispersa
 * Representación mediante Formato Comprimido
 */

#ifndef __COMPRESAS_H
#define __COMPRESAS_H

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
   TipoElemento cols[MAX];
   TipoElemento cfilas[MAX];
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
int *ProductoVector(TipoLista Matriz, int *Vector, int fil, int col);
TipoLista SumaMatrices(TipoLista Matriz1, TipoLista Matriz2, int fil, int cols);


/* Modificadoras */
TipoLista modificarelemento(TipoLista matriz,int i,int j,int value, int m);
TipoLista Transpuesta(TipoLista Matriz, int fil, int cols);


/* Analizadoras */
int LongLista(TipoLista lst);
void ImprimirMatrizLista(TipoLista Matriz, int filas);
void ImprimirMatrizArreglos(int **Mtz, int m, int n);
int ObtenerElemento(TipoLista Lista, int i, int j);
int *ObtenerFilaSinCeros(TipoLista Lista, int i);
int *ObtenerFilaConCeros(TipoLista Lista, int fil, int i);
int *ObtenerColSinCeros(TipoLista Lista, int i);
int *ObtenerColConCeros(TipoLista Lista, int fil,int col, int i);


#endif
