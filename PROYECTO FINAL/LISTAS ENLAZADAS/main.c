#include "Listas.h"
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
    TipoLista *MatrizPrincipal = CrearMatriz1(m, n);
    TipoLista *MatrizSecundaria = CrearMatriz1(m, n);
    printf("\n");
    printf("MATRIZ PRINCIPAL\n");
    ImprimirMatrizListas(MatrizPrincipal, m, n);
    int **MatrizPrincipalA = ConvertirMatrizDeListasAArreglos(MatrizPrincipal, m, n);
    printf("\n");
    //ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    ///--------------------------------------------------///
    printf("\n");
    printf("OBTENER ELEMENTO;\n");
    printf("Ingrese una fila: ");
    scanf("%d", &fila);
    printf("Ingrese una columna: ");
    scanf("%d", &col);
    printf("Su elemento es: %d ",ObtenerElemento(MatrizPrincipal, fila, col));
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    ///--------------------------------------------------///
    system("clear");
    printf("Matriz Principal\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("OBTENER NÚMERO DE ELEMENTOS: %d ",ObtenerNumElento(MatrizPrincipal, m));
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
    TipoLista tmp;
    tmp = ObtenerFilaSinCeros(MatrizPrincipal, fila, m);
    imprimirlist1(tmp);
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    ///--------------------------------------------------///
    system("clear");
    printf("\n");
    printf("Matriz Principal\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("OBTERNER FILA CON CEROS\n");
    printf("Ingrese una fila: ");
    scanf("%d", &fila);
    printf("Su fila es: ");
    int *mk = ObtenerFilaconCeros(MatrizPrincipal, fila, m, n);
        for(int i=0;i<n;i++){
            printf("%d ",mk[i]);
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
    TipoLista tmp2;
    tmp2 = ObtenercolSinCeros(MatrizPrincipal, col, m, n);
    imprimirlist1(tmp2);
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
    mk = ObtenercolconCeros(MatrizPrincipal, col,m,n);
        for(int i=0;i<m;i++){
            printf("%d ",mk[i]);
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
    int **vectorr= (int **)malloc((n) * sizeof(int*));
        for(int i=0;i<n;i++){
            vectorr[i]=(int*)malloc(sizeof(int));
            vectorr[i][0]=i;
        }
    TipoLista *Vector = ConvertirMatrizDeArregloAListas(vectorr,n,1);    
    ImprimirMatrizListas(Vector, n, 1);
    printf("\n");
    printf("EL RESULTADO ES:\n");
    TipoLista *VectorNuevo = CrearMatrizNula(m);
    VectorNuevo = ProductoVector(MatrizPrincipal, Vector, &m, &n);
    ImprimirMatrizListas(VectorNuevo, m, 1);
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    printf("\n");
    ///--------------------------------------------------///
    system("clear");
    printf("MATRIZ PRINCIPAL\n");
    ImprimirMatrizListas(MatrizPrincipal, m, n);
    printf("\n");
    printf("MODIFICAR ELEMENTO\n");
    printf("Ingrese una fila: ");
    scanf("%d", &fila);
    printf("Ingrese una columna: ");
    scanf("%d", &col);
    printf("Ingrese un elemento: ");
    scanf("%d", &newelem);
    printf("\n");
    MatrizPrincipal = ModificarElemento(MatrizPrincipal, m, n, fila, col, newelem);
    printf("SU MATRIZ PRINCIPAL NUEVA ES:");
    MatrizPrincipalA = ConvertirMatrizDeListasAArreglos(MatrizPrincipal, m, n);
    printf("\n");
    ImprimirMatrizArreglos(MatrizPrincipalA, m, n);
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    ///--------------------------------------------------///
    system("clear");
    printf("Matriz Principal\n");
    ImprimirMatrizListas(MatrizPrincipal, m, n);
    printf("\n");
    printf("MATRIZ SECUNDARIA\n");
    ImprimirMatrizListas(MatrizSecundaria, m, n);
    printf("\n");
    printf("SU MATRIZ SUMADA ES: \n");
    MatrizPrincipal = SumarMatrices(MatrizPrincipal, MatrizSecundaria, m, n);
    ImprimirMatrizListas(MatrizPrincipal, m, n);
    printf("\n");
    printf("Presione 1 para continuar... ");
    scanf("%d",&enter);
    printf("\n");
    ///--------------------------------------------------///   
    system("clear");
    printf("TRANSPUESTA DE UNA MATRIZ\n");
    printf("Matriz Principal\n");
    printf("\n");
    ImprimirMatrizListas(MatrizPrincipal, m, n);
    printf("\n");
    printf("Matriz Transpuesta\n");
    printf("\n");
    MatrizPrincipal = Transponer(MatrizPrincipal, &m, &n);
    ImprimirMatrizListas(MatrizPrincipal, m, n);
    printf("\n");
    printf("Presione 1 para finalizar programa... ");
    scanf("%d",&enter);
    system("clear");
    ///--------------------------------------------------///

}