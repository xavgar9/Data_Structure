#include "compresas.h"
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
    printf("\n");
    printf("MATRIZ PRINCIPAL\n");
    ImprimirMatrizLista(MatrizPrincipal, m);

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
    printf("Su elemento es:%d ",ObtenerElemento(MatrizPrincipal, fila, col));
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
    ObtenerFilaSinCeros(MatrizPrincipal, fila);
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
    ObtenerFilaConCeros(MatrizPrincipal, n, fila);
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
    ObtenerColSinCeros(MatrizPrincipal, col);
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
    ObtenerColConCeros(MatrizPrincipal, m, n, col);
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
    int Rusia[] = {1,2,0,0,3};
    for (int B=0; B<n; B++){
        printf("%d\n", Rusia[B]);
    }
    printf("\n");

    printf("EL RESULTADO ES:\n");
    int *Bandu = ProductoVector(MatrizPrincipal, Rusia, m, n);
    for (int B=0; B<m; B++){
        printf("%d\n", Bandu[B]);
    }
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    printf("\n");
    ///--------------------------------------------------///
    system("clear");
    printf("Matriz Principal\n");
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
    printf("SU MATRIZ PRINCIPAL NUEVA ES:\n");
    MatrizPrincipal = modificarelemento(MatrizPrincipal, fila, col, newelem, m);
    ImprimirMatrizLista(MatrizPrincipal, m);
    MatrizPrincipalA = ConvertirMatrizDeListasAArreglos(MatrizPrincipal, m, n);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    printf("\n");
    ///--------------------------------------------------///
    system("clear");
    printf("Matriz Principal\n");
    ImprimirMatrizLista(MatrizPrincipal, m);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);  
    printf("\n");
    printf("MATRIZ SECUNDARIA\n");
    ImprimirMatrizLista(MatrizSecundaria, m);
    int **MatrizPrincipalB = ConvertirMatrizDeListasAArreglos(MatrizSecundaria, m, n);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalB, m, n);
    printf("\n");
    printf("SU MATRIZ SUMADA ES: \n");
    MatrizPrincipal = SumaMatrices(MatrizPrincipal, MatrizSecundaria, m, n);
    ImprimirMatrizLista(MatrizPrincipal, m);
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
    ImprimirMatrizLista(MatrizPrincipal, m);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("Matriz Transpuesta\n");
    MatrizPrincipal = Transpuesta(MatrizPrincipal, m, n);
    ImprimirMatrizLista(MatrizPrincipal, n);
    MatrizPrincipalA = ConvertirMatrizDeListasAArreglos(MatrizPrincipal, n, m);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, n, m);
    printf("\n");
    printf("Presione 1 para finalizar programa... ");
    scanf("%d",&enter);
    system("clear");
    ///--------------------------------------------------///

}