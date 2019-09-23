#include "compresas.h"

TipoLista CrearLista(){
    TipoLista lst;
    for(int i=0; i<MAX; i++){
        lst.datos[i] = 0;
        lst.cols[i] = -1;
        lst.cfilas[i] = 0;
       }
   return lst;
}
int LongLista(TipoLista lst){
    int n=0;
    while(lst.cols[n]!=-1){
        n++;
    }
    return n;
}
TipoLista CrearMatriz1(int m, int n){
    //Crea la matriz
    int x,y, n1=0, n2;
    TipoLista Matriz = CrearLista();
    for(int i=0; i<m; i++){
        n2=0;
        for(int j=0; j<n; j++){
            x = rand() % 5;
            y = rand() % 2;
            //x++;
            if(!y){
                if(x!=0){
                    Matriz.datos[n1] = x;
                    Matriz.cols[n1] = j;
                    n1++;
                    n2++;
                }
            }
        }
        Matriz.cfilas[i+1] = n2 + Matriz.cfilas[i];
    }
    return Matriz;
}
TipoLista CreardeMatrizCompleta(int **Mtz, int m, int n){
    TipoLista Matriz;
    Matriz = CrearLista();
    int n1=0, n2;
    for(int i=0; i<m; i++){
        n2=0;
        for(int j=0; j<n; j++){
            if(Mtz[i][j]!=0){
                Matriz.datos[n1] = Mtz[i][j];
                Matriz.cols[n1] = j;
                n1++;
                n2++;
            }
        }
        Matriz.cfilas[i+1] = n2 + Matriz.cfilas[i];   
    }
    return Matriz;
}
int **ConvertirMatrizDeListasAArreglos(TipoLista Matriz,int m,int n){
    int**Mtz = (int**)malloc(m*sizeof(int*));
    int n1 = LongLista(Matriz), i, j, c, k=0;
    for(i=0; i<m; i++){
        Mtz[i] = (int *)calloc(n, sizeof(int));
        c = Matriz.cfilas[i+1] - Matriz.cfilas[i];
        for(j=0; j<c; j++){
            Mtz[i][Matriz.cols[k]] = Matriz.datos[k];
            k++;
        }
    }
    return Mtz;
}
void ImprimirMatrizLista(TipoLista Matriz, int filas){
    int n = LongLista(Matriz),i;
    printf("Valores= ");
    for( i=0; i<n; i++){
        printf("%d ",Matriz.datos[i]);
    }
    printf("\n");
    printf("Columna= ");
    for( i=0; i<n; i++){
        printf("%d ",Matriz.cols[i]);
    }
    printf("\n");
    printf("cfilas= ");
    for( i=0; i<=filas; i++){
        printf("%d ",Matriz.cfilas[i]);
    }
    printf("\n");
}

void ImprimirMatrizArreglos(int **Mtz, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", Mtz[i][j]);  
        }
        printf("\n");
    }
}

int ObtenerElemento(TipoLista Lista, int i, int j){
    if(Lista.cfilas[i] == Lista.cfilas[i+1])
        return 0;
    else{ 
        for(int k=Lista.cfilas[i]; k<Lista.cfilas[i+1]; k++){
            if(Lista.cols[k] == j)
                return Lista.datos[k];
        }
        return 0;
    } 
}

int *ObtenerFilaSinCeros(TipoLista Lista, int i){
    int c = Lista.cfilas[i+1] - Lista.cfilas[i];
    int *fila;
    if(Lista.cfilas[i] == Lista.cfilas[i+1])
        return fila;
    else{ 
        fila = (int *)malloc(c * sizeof(int));
        c=0;
        for(int k=Lista.cfilas[i]; k<Lista.cfilas[i+1]; k++){
            fila[c]=Lista.datos[k];
            c++;   
            printf("%d ", fila[c-1]);
        }
        return fila;
    } 
}

int *ObtenerFilaConCeros(TipoLista Lista, int fil, int i){
    int *fila = (int *)calloc(fil, sizeof(int));
    if(Lista.cfilas[i] == Lista.cfilas[i+1])
        return fila;
    else{ 
        for(int k=Lista.cfilas[i]; k<Lista.cfilas[i+1]; k++)
            fila[Lista.cols[k]]=Lista.datos[k];

        for(int j=0; j<fil; j++)
            printf("%d ", fila[j]);

        return fila;
    } 
}

int *ObtenerColSinCeros(TipoLista Lista, int i){
    int c = 0;
    for(int j=0; j<LongLista(Lista); j++){
        if(Lista.cols[j] == i)
            c++;   
    }
        
    int *colm = (int *)malloc(c * sizeof(int));
    c=0;
    for(int k=0; k<LongLista(Lista); k++){
        if(Lista.cols[k] == i){
            colm[c]=Lista.datos[k];
            c++;   
            printf("%d ", colm[c-1]);
        }
    }
    return colm;
}



int *ObtenerColConCeros(TipoLista Lista, int fil,int col, int i){      
    int *colm = (int *)calloc(fil, sizeof(int));
    int c=0;
    int NumDatosPorFila;
    int PosNDPF=0;
    int k=0;

    while(k<fil){
        NumDatosPorFila = Lista.cfilas[PosNDPF+1];
        while(c<NumDatosPorFila){
            if(Lista.cols[c] == i){
                colm[k] = Lista.datos[c];
            }
            c++;
        }
        k++;
        PosNDPF++;
    }
    for(int j=0; j<fil; j++)
        printf("%d ", colm[j]);

    return colm;
}    

int *ProductoVector(TipoLista Matriz, int *Vector, int fil, int col){
    int n=0, c=0,mm;
    int Sumaparcial;
    int *Vectorfinal = (int *)calloc(fil, sizeof(int));
    for(int i=0; i<=fil; i++){
        n = Matriz.cfilas[i+1];
        Sumaparcial = 0;
        if(Matriz.cfilas[i] != Matriz.cfilas[i+1]){ 
            while(c<n){
                mm=Matriz.cols[c];
                Sumaparcial += (Matriz.datos[c] * Vector[mm]);
                c++;
            }   
        }
        Vectorfinal[i] = Sumaparcial;
    }
    return Vectorfinal;
}

TipoLista modificarelemento(TipoLista matriz,int i,int j,int value, int m){
    int n1;
    if(matriz.cfilas[i] == matriz.cfilas[i+1]){
        if(value!=0){
            for(n1=LongLista(matriz)-1;n1>=matriz.cfilas[i];n1--){
                matriz.datos[n1+1]=matriz.datos[n1];
                matriz.cols[n1+1]=matriz.cols[n1];
            }
            matriz.datos[n1+1]=value;
            matriz.cols[n1+1]=j;
            for(int h=i+1;h<=m;h++){
                matriz.cfilas[h]+=1;
            }
        }
        return matriz;
    }else{
        for(int k=matriz.cfilas[i]; k<matriz.cfilas[i+1]; k++){
            if(matriz.cols[k] == j){
                if(value!=0){
                    matriz.datos[k]= value;
                }else{
                    if(value==0){
                        int mm1=LongLista(matriz);
                        for(n1=matriz.cfilas[i];n1<mm1;n1++){
                            matriz.datos[n1]=matriz.datos[n1+1];
                            matriz.cols[n1]=matriz.cols[n1+1];
                        }
                        for(int h=i+1;h<=m;h++){
                            matriz.cfilas[h]-=1;
                        }
                        break;
                    }
                }
            }else{
                if(matriz.cols[k] > j&&k-1<matriz.cfilas[i]){
                    if(value != 0){
                        int mm1=LongLista(matriz);
                        for(n1=mm1-1;n1>matriz.cfilas[i];n1--){
                            matriz.datos[n1+1]=matriz.datos[n1];
                            matriz.cols[n1+1]=matriz.cols[n1];
                        }
                        matriz.datos[n1+1]=value;
                        matriz.cols[n1+1]=j;
                        for(int h=i+1;h<=m;h++){
                            matriz.cfilas[h]+=1;
                        }
                        break;  
                    }
                }else{
                    if((matriz.cols[k] <j&&matriz.cols[k+1]>j)&&k+1!=matriz.cfilas[i+1]){
                        if(value != 0){
                            int mm1=LongLista(matriz);
                            for(n1=mm1-1;n1>matriz.cfilas[i];n1--){
                                matriz.datos[n1+1]=matriz.datos[n1];
                                matriz.cols[n1+1]=matriz.cols[n1];
                            }
                            matriz.datos[n1+1]=value;
                            matriz.cols[n1+1]=j;
                            for(int h=i+1;h<=m;h++){
                                matriz.cfilas[h]+=1;
                            }
                            break; 
                        }
                    }else{
                        if(k+1==matriz.cfilas[i+1]){
                            int mm1=LongLista(matriz);
                            for(n1=mm1-1;n1>matriz.cfilas[i];n1--){
                                matriz.datos[n1+1]=matriz.datos[n1];
                                matriz.cols[n1+1]=matriz.cols[n1];
                            }
                            matriz.datos[n1+1]=value;
                            matriz.cols[n1+1]=j;
                            for(int h=i+1;h<=m;h++){
                                matriz.cfilas[h]+=1;
                            }
                            break;
                        }
                    }
                }
            }     
        }
        return matriz;
    } 
}

int **organice(int **arr, int *range){
    for(int i=1;i<(*range);i++){
        for(int j=0;j<(*range)-1;j++){
            if(arr[1][j]>arr[1][j+1]){
                int d=arr[0][j], c=arr[1][j], e=arr[0][j+1], m=arr[1][j+1];
                arr[0][j]=e;
                arr[1][j]=m;
                arr[0][j+1]=d;
                arr[1][j+1]=c;
            }else{
                if(arr[1][j]==arr[1][j+1]){
                    for(int k=j;k<(*range);k++){
                        arr[0][k]=arr[0][k+1];
                        arr[1][k]=arr[1][k+1];
                    }
                    *range = *range - 1;
                }
            }
        }
    }
    return arr;
}

TipoLista SumaMatrices(TipoLista Matriz1, TipoLista Matriz2, int fil, int cols){
    TipoLista MatrizFinal = CrearLista();
    int conta1=0, conta2=0;
    int George = 0;//Uno es que encuentra un número y lo suma 
    int *ArregloDatos = (int *)malloc((fil * 2) * sizeof(int));
    int *ArregloCols = (int *)malloc((fil * 2) * sizeof(int));
    int *ArregloDatos2 = (int *)malloc((fil * 2) * sizeof(int));
    int *ArregloCols2 = (int *)malloc((fil * 2) * sizeof(int));
    int **pepesupremo=(int**)malloc(2*sizeof(int*));
    pepesupremo[0]=(int *)malloc((2*fil)*sizeof(int));
    pepesupremo[1]=(int *)malloc((2*fil)*sizeof(int));
    for(int i=0; i<=fil; i++){
        conta1=0;
        conta2=0;
        for(int j=Matriz1.cfilas[i]; j<Matriz1.cfilas[i+1]; j++){
            George = 0;
            for (int n=Matriz2.cfilas[i]; n<Matriz2.cfilas[i+1]; n++){
                if(Matriz1.cols[j] == Matriz2.cols[n]){
                    ArregloDatos[conta1] = Matriz1.datos[j] + Matriz2.datos[n];
                    ArregloCols[conta1] = Matriz1.cols[j];
                    conta1++;
                    George = 1;
                    break; 
                }       
                else if (Matriz1.cols[j] < Matriz2.cols[n]){
                    ArregloDatos[conta1] = Matriz1.datos[j];
                    ArregloCols[conta1] = Matriz1.cols[j];
                    conta1++;
                    George = 1;
                    break; 
                }
            }
            if (George == 0){
                    ArregloDatos[conta1] = Matriz1.datos[j];
                    ArregloCols[conta1] = Matriz1.cols[j];
                    conta1++;
            }
        }
        for(int j=Matriz2.cfilas[i]; j<Matriz2.cfilas[i+1]; j++){
            George = 0;
            for (int n=Matriz1.cfilas[i]; n<Matriz1.cfilas[i+1]; n++){
                if(Matriz2.cols[j] == Matriz1.cols[n]){
                    ArregloDatos2[conta2] = Matriz2.datos[j] + Matriz1.datos[n];
                    ArregloCols2[conta2] = Matriz2.cols[j];
                    conta2++;
                    George = 1;
                    break;
                }
                else if (Matriz2.cols[j] < Matriz1.cols[n]){
                    ArregloDatos2[conta2] = Matriz2.datos[j];
                    ArregloCols2[conta2] = Matriz2.cols[j];
                    conta2++;
                    George = 1;
                    break; 
                }        
            }
            if (George == 0){
                ArregloDatos2[conta2] = Matriz2.datos[j];
                ArregloCols2[conta2] = Matriz2.cols[j];
                conta2++;
            }
        }
        int l,p;
        for(l=0;l<conta1;l++){
            pepesupremo[0][l]=ArregloDatos[l];
            pepesupremo[1][l]=ArregloCols[l];
        }
        for(l,p=0;p<conta2;p++,l++){
            pepesupremo[0][l]=ArregloDatos2[p];
            pepesupremo[1][l]=ArregloCols2[p];
        }
        pepesupremo=organice(pepesupremo, &l);
    	for(int j=0; j<l; j++)
    		MatrizFinal = modificarelemento(MatrizFinal, i, pepesupremo[1][j], pepesupremo[0][j], fil);
    }
    return MatrizFinal;
}
TipoLista Transpuesta(TipoLista Matriz, int fil, int cols){
    int *ArregloValores = (int *)calloc(fil*10, sizeof(int));
    int *ArregloCols = (int *)calloc(fil*10, sizeof(int));
    int *ArregloCfilas = (int *)calloc(fil*10, sizeof(int));
    int *ArregloFila = (int *)calloc(fil*10, sizeof(int));
    
    int Contador = 0;
    int ContadorFinal = 0;

    for (int m=0; m<LongLista(Matriz); m++){
        for (int x=0; x<fil+1; x++){
            for (int i=Matriz.cfilas[x]; i<Matriz.cfilas[x+1]; i++){

                if (Matriz.cols[i] == Contador){
                    ArregloValores[ContadorFinal] = Matriz.datos[i];
                    ArregloCols[ContadorFinal] = x;
                    ArregloFila[ContadorFinal] = Matriz.cols[i];
                    ContadorFinal++;
                }
            }
        }
        Contador++;        
    }
    int r=0;
    int m=1;
    int Contador2=0;
    ArregloCfilas[0] = 0;
    for (int i=0; i < LongLista(Matriz); i++){
        Contador2 = 0;
        r=0;
        for (int k=0; k<LongLista(Matriz); k++){
            if (ArregloFila[k]==i){
                Contador2++;
            }
        }      
        ArregloCfilas[m] = ArregloCfilas[m-1] + Contador2; 
        m++;
    }
    TipoLista MatrizFinal = CrearLista();

    for (int i=0; i<LongLista(Matriz);i++){
        MatrizFinal.datos[i] = ArregloValores[i];
        MatrizFinal.cols[i] = ArregloCols[i];
    }

    for (int i=0; i<LongLista(Matriz)-1;i++){
        MatrizFinal.cfilas[i] = ArregloCfilas[i];
    }
        

    return MatrizFinal; 
}
