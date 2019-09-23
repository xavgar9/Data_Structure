#include "Vectores.h"
void main(){
    int fila, col, enter, newelem;
    srand(time(NULL));
    int  m, n;
    system("clear");
    printf("INGRESE EL TAMANAÑO DE SU MATRIZ: \n");
    printf("Filas: ");
    scanf("%d",&m);
    printf("Columnas: ");
    scanf("%d",&n);
    system("clear");
    TipoLista MatrizPrincipal = CrearMatriz1(m, n);
    TipoLista MatrizSecundaria = CrearMatriz1(m, n);
    TipoLista Vector = CrearMatriz1(n, 1);
    printf("\n");
    printf("MATRIZ PRINCIPAL\n");
    ImprimirMatrizLista(MatrizPrincipal);
    int **MatrizPrincipalA = ConvertirMatrizDeListasAArreglos(MatrizPrincipal, m, n);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    ///--------------------------------------------------///
    printf("\n");
    printf("OBTENER ELEMENTO;\n");
    printf("Ingrese una fila: ");
    scanf("%d", &fila);
    printf("Ingrese una columna: ");
    scanf("%d", &col);
    printf("Su elemento es: %d ",obtenerele(MatrizPrincipal, fila, col));
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    ///--------------------------------------------------///
    system("clear");
    printf("Matriz Principal\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("OBTENER NÚMERO DE ELEMENTOS: %d ",LongLista(MatrizPrincipal));
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    ///--------------------------------------------------///
    system("clear");
    printf("\n");
    printf("Matriz Principal\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("OBTENER FILA SIN CEROS \n");
    printf("Ingrese una fila: ");
    scanf("%d", &fila);
    printf("Su fila es: ");
    obtenerfilasinceros(MatrizPrincipal, fila);
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    ///--------------------------------------------------///
    
    system("clear");
    printf("\n");
    printf("Matriz Principal\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("OBTENER FILA CON CEROS\n");
    printf("Ingrese una fila: ");
    scanf("%d", &fila);
    printf("Su fila es: ");
    int *fill = obtenerfilaconceros(MatrizPrincipal, fila, n);
    for (int i=0; i<n ;i++){
        printf("%d ", fill[i]);
    }
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    ///--------------------------------------------------///
    system("clear");
    printf("\n");
    printf("Matriz Principal\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("OBTENER COLUMNA SIN CEROS \n");
    printf("Ingrese una columna: ");
    scanf("%d", &col);
    printf("Su columna es: ");
    obtenercolsinceros(MatrizPrincipal, col);
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    ///--------------------------------------------------///
    system("clear");
    printf("\n");
    printf("Matriz Principal\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("OBTENER COLUMNA CON CEROS \n");
    printf("Ingrese una columna: ");
    scanf("%d", &col);
    printf("Su columna es: ");
    int *coll = obtenercolconceros(MatrizPrincipal, col, m);
    for (int i=0; i<m ;i++){
        printf("%d ", coll[i]);
    }
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    ///--------------------------------------------------///
    system("clear");
    printf("\n");
    printf("PRODUCTO MATRIZ POR VECTOR\n");
    printf("\n");
    printf("Matriz Principal\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("El Vector \n");
    int **Rusia = ConvertirMatrizDeListasAArreglos(Vector, n, 1);
    ImprimirMatrizArreglos(Rusia, n, 1);
    printf("\n");

    printf("EL RESULTADO ES:\n");
    TipoLista Bandu = ProductoVector(MatrizPrincipal, Vector, m, n);
    int **MtzVec = ConvertirMatrizDeListasAArreglos(Bandu, n, 1);
    ImprimirMatrizArreglos(MtzVec, m, 1);
    printf("\n");;
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    printf("\n");
    
    ///--------------------------------------------------///
    system("clear");
    printf("MATRIZ PRINCIPAL\n");
    ImprimirMatrizLista(MatrizPrincipal);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("MODIFICAR ELEMENTO\n");
    printf("Ingrese una fila: ");
    scanf("%d", &fila);
    printf("Ingrese una columna: ");
    scanf("%d", &col);
    printf("Ingrese un elemento: ");
    scanf("%d", &newelem);
    printf("\n");
    MatrizPrincipal = modificarelemento(MatrizPrincipal, fila, col, newelem);
    ImprimirMatrizLista(MatrizPrincipal);
    MatrizPrincipalA = ConvertirMatrizDeListasAArreglos(MatrizPrincipal, m, n);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    printf("\n");
    ///--------------------------------------------------///
    
    system("clear");
    printf("Matriz Principal\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("MATRIZ SECUNDARIA\n");
    ImprimirMatrizLista(MatrizSecundaria);
    int **MatrizPrincipalB = ConvertirMatrizDeListasAArreglos(MatrizSecundaria, m, n);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalB, m, n);
    printf("\n");
    printf("SU MATRIZ SUMADA ES: \n");
    MatrizPrincipal = sumar(MatrizPrincipal, MatrizSecundaria);
    ImprimirMatrizLista(MatrizPrincipal);
    printf("\n");
    MatrizPrincipalA = ConvertirMatrizDeListasAArreglos(MatrizPrincipal, m, n);
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    printf("\n");
    ///--------------------------------------------------///

    system("clear");
    printf("TRANSPUESTA DE UNA MATRIZ\n");
    printf("Matriz Principal\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("Matriz Transpuesta\n");
    MatrizPrincipal = Transponer(MatrizPrincipal);
    ImprimirMatrizLista(MatrizPrincipal);
    MatrizPrincipalA = ConvertirMatrizDeListasAArreglos(MatrizPrincipal, n, m);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, n, m);
    printf("\n");
    printf("Presione 1 para finalizar programa... ");
    scanf("%d",&enter);
    system("clear");
    ///--------------------------------------------------///

}