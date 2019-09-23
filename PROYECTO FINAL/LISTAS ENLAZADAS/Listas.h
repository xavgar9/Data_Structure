/*
 * Autor: Jhoan Lozano, Xavier Garzón, Cristian Osorio
 * Fecha de creación: 12 de mayo de 2017
 * Fecha última modificación: 25 de mayo de 2017
 * Versión: 1.0
 * 
 * Archivo encabezado libreria TAD Matrizz Dispersa
 * Representación mediante Formato Comprimido
 */

#ifndef __LISTAS_H
#define __LISTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/************************
* ESTRUCTURAS DE DATOS *
************************/
struct NumeroMat{
	//El valor especifico de cada nodo 
	int Valor;
	int Cols;
};
typedef struct NumeroMat TipoElemento;

struct Nodo{
	//Este recibe el valor de NumeroMat
	TipoElemento Numero;
	struct Nodo *sig;
	struct Nodo *ant;
};
typedef struct Nodo* TipoLista;

/************************
* OPERACIONES DEL TAD *
************************/

/* Constructoras */
TipoLista CrearLista();
TipoLista CrearNodo(TipoElemento Num);
TipoLista AnxNodo(TipoLista Lst, TipoElemento Num);
TipoLista *CrearMatrizNula(int m);
TipoLista *CrearMatriz1(int m, int n);

TipoLista *ConvertirMatrizDeArregloAListas(int **Mtz, int m, int n);
int **ConvertirMatrizDeListasAArreglos(TipoLista *Matriz, int m, int n);

TipoLista *SumarMatrices(TipoLista *Matriz1, TipoLista *Matriz2, int m, int n);
TipoLista *ProductoVector(TipoLista *Matriz1, TipoLista *Vector, int *m, int *n);

/* Modificadoras */
TipoLista *Transponer(TipoLista *Matriz1, int *m, int *n);
TipoLista* ModificarElemento(TipoLista *Matriz, int i, int j, int fil, int col, int valor);

/* Analizadoras */
TipoElemento buscarelelist(TipoLista list,int col);
void imprimirlist1(TipoLista list);
void ImprimirLista(TipoLista Lst, int n);
void ImprimirMatrizListas(TipoLista *Matriz, int m, int n);
void ImprimirMatrizArreglos(int **Mtz, int m, int n);
int LongLista(TipoLista Lst);
int ObtenerElemento(TipoLista *Matriz, int i, int j);
TipoLista ObtenerFilaSinCeros(TipoLista *Matriz, int i,int n);
TipoLista ObtenercolSinCeros(TipoLista *Matriz,int col,int m,int n);
int* ObtenerFilaconCeros(TipoLista *Matriz, int i,int n,int m);
int* ObtenercolconCeros(TipoLista *Matriz,int col,int m,int n);
int ObtenerNumElento(TipoLista*lista,int m);
#endif