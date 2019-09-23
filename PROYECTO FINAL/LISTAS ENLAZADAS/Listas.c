#include "Listas.h"

TipoLista CrearLista(){
	//Crea una lista vacia
	TipoLista Lst = NULL;
	return Lst;
}
//check
TipoLista CrearNodo(TipoElemento Num){
	//Crea un Nodo un los elementos ingresados como parametros
	TipoLista NuevoNodo = (TipoLista)malloc(sizeof(struct Nodo));
	NuevoNodo->Numero = Num;
	NuevoNodo->sig = NULL;
	NuevoNodo->ant = NULL;
	return NuevoNodo;
}
//check
TipoLista AnxNodo(TipoLista Lst, TipoElemento Num){
	//Agrega el nodo en la lista especifica ingresada
	TipoLista NuevoNodo, Tmp;
	if(Num.Valor != 0){
		NuevoNodo = CrearNodo(Num);
		if(Lst == NULL)
			Lst = NuevoNodo;
		else{
			Tmp = Lst;
			while(Tmp->sig != NULL)	
				Tmp = Tmp->sig;
			Tmp->sig = NuevoNodo;
			NuevoNodo->ant = Tmp;
		}
	}
	return Lst;
}
//check
TipoElemento buscarelelist(TipoLista list,int col){
	TipoLista tmp=list;
	while(tmp!=NULL){
		if(tmp->Numero.Cols==col){
			return tmp->Numero;
		}
		tmp=tmp->sig;
	}
	if(tmp==NULL){
		TipoElemento num;
		num.Valor = 0;
		num.Cols = col;
		return num;
	}
}
//check
TipoLista *CrearMatrizNula(int m){
    TipoLista *Matriz = (TipoLista *)malloc(m *sizeof(TipoLista));
    for(int i=0; i<m; i++)
        Matriz[i] = CrearLista();
    return Matriz;
}
//check
TipoLista *CrearMatriz1(int m, int n){
	//Crea la matriz 
	int x,y;
	TipoElemento Elemento;
	TipoLista *Matriz = CrearMatrizNula(m);
	for(int i=0; i<m; i++){
		Matriz[i] = CrearLista();
		for(int j=0; j<n; j++){
			x = rand() % 5;
			y = rand() % 5;
			if(!y){
				Elemento.Valor = x;
				Elemento.Cols = j;
			}
			else{
				Elemento.Valor = 0;
				Elemento.Cols = j;
			}
			Matriz[i] = AnxNodo(Matriz[i], Elemento);	//Matriz = Fila
		}
	}
	return Matriz;
}
//check
TipoLista *ConvertirMatrizDeArregloAListas(int **Mtz, int m, int n){
	//Convierte  una matriz de arreglos a una matriz de listas
	int x,y;
	TipoElemento Elemento;
	TipoLista *Matriz = (TipoLista *)malloc(m *sizeof(TipoLista));
	for(int i=0; i<m; i++){
		Matriz[i] = CrearLista();
		for(int j=0; j<n; j++){
			
			Elemento.Valor = Mtz[i][j];
			Elemento.Cols = j;

			Matriz[i] = AnxNodo(Matriz[i], Elemento);	//Matriz = Fila
		}
	}
	return Matriz;
}
//check
int **ConvertirMatrizDeListasAArreglos(TipoLista *Matriz, int m, int n){
	//Pasa de una matriz de listas a una matriz de arreglos
	int **Mtz = (int **)malloc(m * sizeof(int*));
	TipoLista tmp;

	for(int i=0; i<m; i++){
		Mtz[i] = (int *)calloc(n, sizeof(int));
		if(Matriz[i] != NULL){
			tmp = Matriz[i];	
			while(tmp != NULL){
				Mtz[i][tmp->Numero.Cols] = tmp->Numero.Valor;
				//printf("Fila <%i> Columna <%i> Valor <%i> \n", i,tmp->Numero.Cols, tmp->Numero.Valor);
				tmp = tmp->sig; 
			}
		}
	}
	return Mtz;
}
//check
void imprimirlist1(TipoLista list){
	TipoLista tmp=list;
	while(tmp!=NULL){
		printf("%d ",tmp->Numero.Valor);
		tmp=tmp->sig;
	}
	printf("\n");
}
//check
void ImprimirLista(TipoLista Lst, int n){
	//Imprime las filas (Las listas especificas de cada fila)
	TipoLista Tmp;
	int i;
	if(Lst == NULL){
		for(i=0; i<n; i++)
			printf("0 ");
	}else{
		Tmp = Lst;
 		for(i=0; i<n; i++){
 			if(Tmp->Numero.Cols == i){
 				printf("%d ", Tmp->Numero.Valor);
 				if(Tmp->sig!=NULL)
 					Tmp = Tmp->sig;
 			}
 			else{
 				printf("0 ");
 			}		
 		}
	}
}
//check
void ImprimirMatrizListas(TipoLista *Matriz, int m, int n){
	//Imprime toda la matriz
	for(int i=0; i<m; i++){
		ImprimirLista(Matriz[i], n);
		printf("\n");
	}
}
//check
void ImprimirMatrizArreglos(int **Mtz, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", Mtz[i][j]);  
        }
    	printf("\n");
    }
}
//check
int LongLista(TipoLista Lst){
	//Nos da la longitud de las filas (listas especificas de cada fila)
	TipoLista Tmp;
	int cont = 0;
	if(Lst == NULL)
		return 0;
	else{
		Tmp = Lst;
		while(Tmp != NULL){	
			cont++;
			Tmp = Tmp->sig;
		}
	}
	return cont;
}
//check
int ObtenerElemento(TipoLista *Matriz, int i, int j){
	TipoLista tmp = Matriz[i];
	while(tmp != NULL){ 
		if(tmp->Numero.Cols == j)
		 	return tmp->Numero.Valor;
		 tmp = tmp->sig;
	}
	return 0;
}
//check
TipoLista ObtenerFilaSinCeros(TipoLista *Matriz, int i,int n){
	if(i>=0&&i<n){
		return Matriz[i];
	}
}
//check
TipoLista ObtenercolSinCeros(TipoLista *Matriz,int col,int m,int n){
	TipoLista columna=CrearLista();
	if(col>=0&&col<m){
		for (int i=0; i<m; i++){
			//printf("%d\n",i);
			TipoLista tmp=Matriz[i];
			TipoElemento num=buscarelelist(tmp,col);
			columna=AnxNodo(columna,num);
		}
	}
	return columna;
}
//check
int* ObtenerFilaconCeros(TipoLista *Matriz, int i,int n,int m){
	if(i>=0&&i<m){
		TipoLista tmp=Matriz[i];
		int *Mtz = (int *)malloc(n*sizeof(int));
		for(int i=0;i<m;i++){
			Mtz[i]=0;
		}
		if (tmp==NULL){
			return Mtz;
		}
		while(tmp != NULL){
			Mtz[tmp->Numero.Cols] = tmp->Numero.Valor;
			tmp = tmp->sig; 
		}
		return Mtz;
	}
}
//check
int* ObtenercolconCeros(TipoLista *Matriz,int col,int m,int n){
	if(col>=0&&col<m){
		TipoLista columna=CrearLista();
		int *Mtz = (int *)calloc(m,sizeof(int));
		if(col>=0&&col<m){
			for (int i=0; i<m; i++){
				TipoLista tmp=Matriz[i];
				TipoElemento num=buscarelelist(tmp,col);
				Mtz[i]=num.Valor;
			}
		}
		return Mtz;
	}
}
//check
TipoLista *SumarMatrices(TipoLista *Matriz1, TipoLista *Matriz2, int m, int n){
	TipoLista *SumarMatricesListas(TipoLista *Matriz1, TipoLista *Matriz2, int m, int n);
	TipoLista *MatrizSumada = CrearMatrizNula(m);
	TipoLista tmp, tmp2;
	TipoElemento elem;

	for(int i=0; i<m; i++){
		tmp = Matriz1[i];
		tmp2 = Matriz2[i];
		while(tmp != NULL || tmp2 != NULL){
			if(tmp == NULL && tmp2 != NULL){
				MatrizSumada[i] = AnxNodo(MatrizSumada[i], tmp2->Numero);
				tmp2 = tmp2->sig;

			}else if(tmp != NULL && tmp2 == NULL){
				MatrizSumada[i] = AnxNodo(MatrizSumada[i], tmp->Numero);
				tmp = tmp->sig;

			}else if(tmp->Numero.Cols == tmp2->Numero.Cols){
				elem.Cols = tmp->Numero.Cols;
				elem.Valor = tmp->Numero.Valor + tmp2->Numero.Valor;
				MatrizSumada[i] = AnxNodo(MatrizSumada[i], elem);
				tmp = tmp->sig;
				tmp2 = tmp2->sig;

			}else if(tmp->Numero.Cols < tmp2->Numero.Cols){
				MatrizSumada[i] = AnxNodo(MatrizSumada[i], tmp->Numero);
				tmp = tmp->sig;

			}else if(tmp->Numero.Cols > tmp2->Numero.Cols){
				MatrizSumada[i] = AnxNodo(MatrizSumada[i], tmp2->Numero);
				tmp2 = tmp2->sig;
			}

		}
	}
	return MatrizSumada;
}
//check
TipoLista *Transponer(TipoLista *Matriz1, int *m, int *n){
	TipoLista *nueva=CrearMatrizNula(*n);
	TipoLista tmp;
	for (int i = 0; i < *n; ++i){
		nueva[i] = CrearLista();
	}
	for(int j=0; j<(*m); j++){
		tmp=Matriz1[j];
		if(LongLista(tmp)!=0){
			while(tmp->sig!=NULL){
				tmp=tmp->sig;
			}
			while(tmp!=NULL){
				TipoElemento agreg;
				agreg.Valor=tmp->Numero.Valor;
				agreg.Cols=j;
				nueva[tmp->Numero.Cols]=AnxNodo(nueva[tmp->Numero.Cols],agreg);
				tmp=tmp->ant;
			}
		}
	}
	int tmp2 = *n;
	*n = *m;
	*m = tmp2;
	return nueva; 
}
//check
TipoLista *ProductoVector(TipoLista *Matriz1, TipoLista *Vector, int *m, int *n){
	TipoLista *nueva=CrearMatrizNula(*m);
	int PepeAcu;
	for(int i=0;i<(*m);i++){
		PepeAcu=0;
		int c=0;
		TipoLista tmp=Matriz1[i];
		if(tmp!=NULL){
			while(tmp!=NULL){
				if(Vector[tmp->Numero.Cols]!=NULL){
					PepeAcu+=tmp->Numero.Valor*Vector[tmp->Numero.Cols]->Numero.Valor;
					
				}
				tmp=tmp->sig;
			}
		}
		TipoElemento anex;
		if(PepeAcu != 0){
			anex.Valor=PepeAcu;
			anex.Cols=0;
			nueva[i]=AnxNodo(nueva[i],anex);
		}

	}
	return nueva;
}
//re-doing GUI and continue
TipoLista* ModificarElemento(TipoLista *Matriz, int i, int j, int fil, int col, int valor){
	TipoLista tmp=Matriz[fil];
	if(tmp==NULL){
		TipoElemento numero;
		numero.Valor=valor;
		numero.Cols=col;
		Matriz[fil] = AnxNodo(Matriz[fil], numero);
		return Matriz;
	}
	if(tmp->Numero.Cols>col&&valor!=0){
		TipoElemento numero;
		numero.Valor=valor;
		numero.Cols=col;
		TipoLista agregar=CrearNodo(numero);
		agregar->sig=tmp;
		tmp->ant=agregar;
		Matriz[fil]=agregar;
		return Matriz;
	}
	if(tmp->Numero.Cols==col){
		if(valor!=0){
			tmp->Numero.Valor=valor;
		}else{
			if(tmp->sig==NULL){
				Matriz[fil] = NULL;
			}else{
				tmp->sig->ant=NULL;
				Matriz[fil]=tmp->sig;
			}
		}
		return Matriz;
	}
	while(tmp->sig!=NULL&&(tmp->Numero.Cols<=col)){
		tmp=tmp->sig;
	}
	if(tmp->Numero.Cols==col){
		if(valor!=0){
			tmp->sig->Numero.Valor=valor;
			return Matriz;
		}else{
			tmp->sig=tmp->sig->sig;
			tmp->sig->ant->sig=NULL;
			tmp->sig->ant->ant=NULL;
			tmp->sig->ant=tmp;
			return Matriz;
		}
	}else{
		if(tmp->Numero.Cols>col){
			TipoElemento numero;
			numero.Valor=valor;
			numero.Cols=col;
			tmp=tmp->ant;
			TipoLista agregar=CrearNodo(numero);
			agregar->sig=tmp->sig;
			agregar->ant=tmp;
			tmp->sig=agregar;
			agregar->sig->ant=agregar;
			return Matriz;
		}else{
			if(tmp->sig==NULL){
				if(tmp->Numero.Cols==col){
					tmp->Numero.Valor=valor;
					return Matriz;
				}
				TipoElemento numero;
				numero.Valor=valor;
				numero.Cols=col;
				Matriz[fil] = AnxNodo(Matriz[fil], numero);
				return Matriz;
			}
		}
	}
	return Matriz;	
}
//check
int ObtenerNumElento(TipoLista*lista,int m){
	int acum=0;
	for(int i=0;i<m;i++){
		if(lista[i]!=NULL){
			acum+=LongLista(lista[i]);	
		}
	}
	return acum;
}