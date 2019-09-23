#include "Vectores.h"

TipoLista CrearLista(){
    TipoLista lst;
   for(int i=0; i<MAX; i++){
      lst.datos[i] = 0;
      lst.filas[i] = -1;
      lst.cols[i] = -1;
   }
   return lst;
}
//check
int LongLista(TipoLista lst){
    int n=0;
    while(lst.filas[n]!=-1){
        n++;
    }
    return n;
}
//check
TipoLista CrearMatriz1(int m, int n){
    int x,y, n1=0;
    TipoLista Matriz = CrearLista();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            x = rand() % 5;
            y = rand() % 2;
            if(!y){
                if(x!=0){
                    Matriz.datos[n1] = x;
                    Matriz.filas[n1] = i;
                    Matriz.cols[n1] = j;
                    n1++;
                }
            }
        }
    }
    return Matriz;
}
//check
void ImprimirMatrizLista(TipoLista Matriz){
    int n = LongLista(Matriz),i;
    printf("Valores= ");
    for( i=0; i<n; i++){
        printf("%d ",Matriz.datos[i]);
    }
    printf("\n");
    printf("Filas= ");
    for( i=0; i<n; i++){
        printf("%d ",Matriz.filas[i]);
    }
    printf("\n");
    printf("Columnas= ");
    for( i=0; i<n; i++){
        printf("%d ",Matriz.cols[i]);
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
//check
TipoLista organice(TipoLista Matriz1,int range){
    for(int i=1;i<range;i++){
        for(int j=0;j<range-1;j++){
            if(Matriz1.filas[j]<Matriz1.filas[j+1]){
                int d=Matriz1.datos[j],f=Matriz1.filas[j],c=Matriz1.cols[j],e=Matriz1.datos[j+1],h=Matriz1.filas[j+1],m=Matriz1.cols[j+1];
                Matriz1.datos[j]=e;
                Matriz1.filas[j]=h;
                Matriz1.cols[j]=m;
                Matriz1.datos[j+1]=d;
                Matriz1.filas[j+1]=f;
                Matriz1.cols[j+1]=c;
            }
        }
    }
    return Matriz1;
}
//check
TipoLista organicebyrows(TipoLista Matriz1){
    int n=LongLista(Matriz1);
    for(int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(Matriz1.filas[j]>Matriz1.filas[j+1]){
                int d=Matriz1.datos[j],f=Matriz1.filas[j],c=Matriz1.cols[j],e=Matriz1.datos[j+1],h=Matriz1.filas[j+1],m=Matriz1.cols[j+1];
                Matriz1.datos[j]=e;
                Matriz1.filas[j]=h;
                Matriz1.cols[j]=m;
                Matriz1.datos[j+1]=d;
                Matriz1.filas[j+1]=f;
                Matriz1.cols[j+1]=c;
            }
            if(Matriz1.filas[j]==Matriz1.filas[j+1]){
                if(Matriz1.cols[j]>Matriz1.cols[j+1]){
                    int d=Matriz1.datos[j],f=Matriz1.filas[j],c=Matriz1.cols[j],e=Matriz1.datos[j+1],h=Matriz1.filas[j+1],m=Matriz1.cols[j+1];
                    Matriz1.datos[j]=e;
                    Matriz1.filas[j]=h;
                    Matriz1.cols[j]=m;
                    Matriz1.datos[j+1]=d;
                    Matriz1.filas[j+1]=f;
                    Matriz1.cols[j+1]=c;
                }
        }
    }}
    return Matriz1;
}
//check
TipoLista OrganizarCols(TipoLista Lista){
    int n = LongLista(Lista), i;
    TipoLista tmp = CrearLista();

    for(i=0; i<n; i++){                   
        for(int j=0; j<n-1; j++){               
            if(Lista.cols[j]>Lista.cols[j+1]){   
                tmp.cols[0] = Lista.cols[j];
                tmp.filas[0] = Lista.filas[j];
                tmp.datos[0] = Lista.datos[j];

                Lista.cols[j] = Lista.cols[j+1];
                Lista.filas[j] = Lista.filas[j+1];
                Lista.datos[j] = Lista.datos[j+1];

                Lista.cols[j+1] = tmp.cols[0];
                Lista.filas[j+1] = tmp.filas[0];
                Lista.datos[j+1] = tmp.datos[0]; 
            }   
        }   
    }
    printf("\n ");
    return Lista;
}
//check
TipoLista CreardeMatrizCompleta(int **Mtz, int m, int n){
    TipoLista Matriz;
    Matriz = CrearLista();
    int n1=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(Mtz[i][j]!=0){
                Matriz.datos[n1] = Mtz[i][j];
                Matriz.filas[n1] = i;
                Matriz.cols[n1] = j;
                n1++;
            }
        }
    }
    return Matriz;
}
//check
int **ConvertirMatrizDeListasAArreglos(TipoLista Matriz,int m,int n){//OBTENER MATRIZ COMPLETA
    int**Mtz = (int**)malloc(m*sizeof(int*));
    int n1 = LongLista(Matriz), i;
    for(i=0; i<m; i++)
        Mtz[i] = (int *)calloc(n, sizeof(int));
    for(i=0;i<n1;i++)
        Mtz[Matriz.filas[i]][Matriz.cols[i]]=Matriz.datos[i];
    return Mtz;
}
//check
int obtenerele(TipoLista matriz,int fil,int col){
    if (LongLista(matriz)==0){
        return -1;
    }
    for(int i=0;i<LongLista(matriz);i++){
        if((matriz.cols[i]==col)&&(matriz.filas[i]==fil)){
            return matriz.datos[i];
        }
    }
    return 0;
}
//check
TipoLista obtenerfilasinceros(TipoLista matriz, int fil){
    TipoLista fila1=CrearLista();
    int c=0;
    if (LongLista(matriz)==0){
        return fila1;
    }
    for(int i=0;i<LongLista(matriz);i++){
        if(matriz.filas[i]==fil){
            fila1.datos[c]=matriz.datos[i];
            fila1.filas[c]=matriz.filas[i];
            fila1.cols[c]=matriz.cols[i];
            printf("%d ", fila1.datos[c]);
            c++;
        }
    }
    return fila1;
}
//check
TipoLista obtenercolsinceros(TipoLista matriz, int col){
    TipoLista coll=CrearLista();
    int c=0;
    if (LongLista(matriz)==0){
        return coll;
    }
    for(int i=0;i<LongLista(matriz);i++){
        if(matriz.cols[i]==col){
            coll.datos[c]=matriz.datos[i];
            coll.filas[c]=matriz.filas[i];
            coll.cols[c]=matriz.cols[i];
            printf("%d ", coll.datos[c]);
            c++;
        }
    }
    coll=organicebyrows(coll);
    return coll;
}
//check
int * obtenerfilaconceros(TipoLista matriz,int fil,int n){
    int *fill=(int*)calloc(n,sizeof(int));
    if (LongLista(matriz)==0){
        return fill;
    }
    for(int i=0;i<LongLista(matriz);i++){
        if(matriz.filas[i]==fil){
            fill[matriz.cols[i]]=matriz.datos[i];
        }
    }
    return fill;
}
//check
int * obtenercolconceros(TipoLista matriz,int col,int n){
    int *coll=(int*)calloc(n,sizeof(int));
    if (LongLista(matriz)==0){
        return coll;
    }
    for(int i=0;i<LongLista(matriz);i++){
        if(matriz.cols[i]==col){
            coll[matriz.filas[i]]=matriz.datos[i];
        }
    }
    return coll;
}
//check
TipoLista ProductoVector(TipoLista Matriz, TipoLista Vector, int m, int n){
    //CADA FILA DE LA ORIGINAL POR TODO EL VECTOR, SE SUMA CADA 
    int n1=LongLista(Matriz);
    int n2=LongLista(Vector);
    int SumaPorFila = 0;
    int *Pepsi, *CocaCola;
    TipoLista VectorFinal = CrearMatriz1(m, 1);
    for(int i=0;i<m;i++){
        SumaPorFila = 0; 
        Pepsi = obtenerfilaconceros(Matriz,i,n);
        CocaCola = obtenercolconceros(Vector,0,n);
        for (int j = 0; j < n; ++j){
            SumaPorFila += (Pepsi[j] * CocaCola[j]);
        }    
        VectorFinal.datos[i] = SumaPorFila;
        VectorFinal.filas[i] = i;
        VectorFinal.cols[i] = 0;
    }
    return VectorFinal;
}
//check
TipoLista Transponer(TipoLista Matriz){
    Matriz = OrganizarCols(Matriz);
    int n = LongLista(Matriz);
    TipoElemento Guardado;
   
    for(int i=0; i<n; i++){                   
        Guardado = Matriz.cols[i];
        Matriz.cols[i] = Matriz.filas[i];
        Matriz.filas[i] = Guardado;
    }
    return Matriz;
}
TipoLista sumar(TipoLista Matriz,TipoLista Matriz1){
    int n1=LongLista(Matriz),n2=LongLista(Matriz1),c=0,c1;
    TipoLista sumada=CrearLista();
    for(int i=0;i<n1;i++){
        for (int j = 0; j < n2; ++j){
            if((Matriz.cols[i]==Matriz1.cols[j])&&(Matriz.filas[i]==Matriz1.filas[j])){
                sumada.datos[c]=Matriz.datos[i]+Matriz1.datos[j];
                sumada.filas[c]=Matriz.filas[i];
                sumada.cols[c]=Matriz.cols[i];
                Matriz.filas[i]=-1;
                Matriz1.filas[j]=-1;
                c++;
                break;
            }
        }
    }
    Matriz=organice(Matriz,n1);
    ImprimirMatrizLista(Matriz);
    printf("\n");
    Matriz1=organice(Matriz1,n2);
    printf("\n");
    ImprimirMatrizLista(Matriz1);
    for(int i=0;i<LongLista(Matriz);i++){
        sumada.datos[c]=Matriz.datos[i];
        sumada.filas[c]=Matriz.filas[i];
        sumada.cols[c]=Matriz.cols[i];
        c++;
    }
    for(int i=0;i<LongLista(Matriz1);i++){
        sumada.datos[c]=Matriz1.datos[i];
        sumada.filas[c]=Matriz1.filas[i];
        sumada.cols[c]=Matriz1.cols[i];
        c++;
    }
    sumada=organice(sumada,n1+n2);
    sumada=organicebyrows(sumada);
    return sumada;
}
//check
TipoLista modificarelemento(TipoLista matriz, int fil,int col,int value){
    ////continuar haciendo
    int m=LongLista(matriz);
    for(int i =0;i<m;i++){
        if(matriz.filas[i]==fil&&matriz.cols[i]==col){
            if(value==0){
                int n1;
                for(n1=i;n1<m;n1++){
                    matriz.datos[n1]=matriz.datos[n1+1];
                    matriz.filas[n1]=matriz.filas[n1+1];
                    matriz.cols[n1]=matriz.cols[n1+1];
                }
            }else{
                matriz.datos[i]=value;
            }
            return matriz;
        }
    }
    if (value!=0){
        matriz.datos[m]=value;
        matriz.filas[m]=fil;
        matriz.cols[m]=col;
        organice(matriz,m+1);
        organicebyrows(matriz);
        return matriz;
    }
}
