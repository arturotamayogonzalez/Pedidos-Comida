#include<stdio.h>
#include<stdlib.h>
struct productos{
    int precio;
    char* nombre;
    int cantidad;
};
//Funcion para leer los productos disponibles
char** productos (int cantidad)
{
    struct productos uno;
    FILE* archivo;///////////////////
    char** disponibles;
    disponibles = (char**)malloc(sizeof(char)*30*cantidad);
    int i;
    archivo= fopen("/Users/arturotamayogonzalez/Documents/Xcode/Parcial 3/Parcial 3/Productos.txt", "a");////////
    for (i=0; i<cantidad; i++){
        printf("Nombre del Producto %d: ", i);
        disponibles[i] = (char*)malloc(30);
        fgets(disponibles[i], 30, stdin);
        uno.nombre = *disponibles;
        fprintf(archivo, "Producto: %s", disponibles[i]);/////////////////////
    }
    return disponibles;
}
//Funcion para leer los precios de los productos
int* precios(int cantidad)
{
    struct productos uno;
    FILE* archivo; ///////////////
    int* listadeprecios;
    int i, precio;
    listadeprecios = (int*)malloc(cantidad * sizeof(int));
    archivo= fopen("/Users/arturotamayogonzalez/Documents/Xcode/Parcial 3/Parcial 3/Precios.txt", "a");/////////
    for (i=0; i<cantidad; i++){
        printf("Precio del producto %d: ", i);
        scanf("%d", &precio);
        getchar();
        uno.precio= *listadeprecios;
        *(listadeprecios+i) = precio;
        fprintf(archivo, "Precio: %d\n", listadeprecios[i]);/////////////
    }
    return listadeprecios;
}
//Funcion para mostrar los productos dosponibles y sus precios
void imprimirmenu (char* productos[], int precios[], int cantidad){
        
        int i;
        printf("MENU GENERADO A PARTIR DE LOS PRODUCTOS Y LOS PRECIOS QUE INGRESASTE\n");
        for (i=0; i<cantidad; i++){
            printf("Producto:%s Precio:%d\n", productos[+i], precios[+i]);
        }
}

struct pedido{
    int cantidad;
    int precio;
    int preciototal;
};
//Funcion para crear un pedido
int* cantidad(char* productos[], int cantidad){
    int* pedido;
    int i, cantidades;
    struct pedido dos;
    pedido = (int*)malloc(cantidad * sizeof(int));
    printf("CREA UN PEDIDO, INGRESA LA CANTIDAD DE CADA PRODUCTOS QUE NECESITES\n");
    for (i=0; i<cantidad; i++){
        printf("Producto:%s Cantidad: ", productos[+i]);
        scanf("%d", &cantidades);
        getchar();
        dos.cantidad = cantidades;
        *(pedido+i) = cantidades;
    }
    return pedido;
}


//Funcion para calcular el precio total de un pedido
int* total(int pedido[], int precio[], int cantidad){
    struct pedido dos;
    int* totals;
    int i;
    totals = (int*)malloc(cantidad * sizeof(int));
    for(i=0; i<cantidad; i++){
        totals[+i] = (pedido[+i]) * (precio[+i]);
        dos.precio = *totals;
    }
    return totals;
}

//Funcion para calcular el precio total del pedido
int* sumatoria(int* total, int cantidad)
{
    struct pedido dos;
    int sumatoria, i;
    sumatoria =0;
    for (i=0; i<cantidad; i++){
        sumatoria = sumatoria + (*(total+i));
        dos.preciototal= sumatoria;
    }
    return sumatoria;
}
//Funcion para desplegar el pedido
void imprimirpedido (char* productos[], int precio[], int pedido[], int total[], int cantidad, int sumatoriatotal)
{
    FILE* archivo;
    int i;
    archivo = fopen("/Users/arturotamayogonzalez/Documents/Xcode/Parcial 3/Parcial 3/Pedidos.txt", "a");
    printf("TU PEDIDO ES:\n");
    for (i=0; i<cantidad; i++){
    printf("Producto:%s Precio:$%d Cantidad pedida:%d Costo:$%d\n", productos[+i], precio[+i], pedido[+i], total[+i]);
    fprintf(archivo, "Producto:%s Precio:$%d Cantidad pedida:%d Costo:$%d\n", productos[+i], precio[+i], pedido[+i], total[+i]);
    }
    printf("El costo total de este pedido es:$%d\n", sumatoriatotal);
    fprintf(archivo, "El costo total de este pedido es:$%d\n", sumatoriatotal);
}


int main ()
{
    FILE* archivo;

    char confirmacion, mas, contenido;
    int n;
    char** productoss;
    int* precioss;
    int* cantidads;
    int* totals;
    int* sumatorias;
    struct productos uno;
    struct pedido dos;
    //Pedir la cantidad de productos
    while (mas!='n'){
    printf("CANTIDAD DE PRODUCTOS A INGRESAR: ");
    scanf("%d", &n);
    getchar();
    uno.cantidad = n;
        
    //Leer los productos
    productoss = productos(n);
   
    //Leer los precios
    precioss = precios(n);
 
    //Imprimir los productos disponibles y sus precios
        
        printf("Productos ingresados anteriormente\n");
        archivo= fopen("/Users/arturotamayogonzalez/Documents/Xcode/Parcial 3/Parcial 3/Productos.txt", "r");
        do{
            contenido =getc(archivo);
            printf("%c", contenido);}
        while (contenido !=EOF) ;
archivo= fopen("/Users/arturotamayogonzalez/Documents/Xcode/Parcial 3/Parcial 3/Precios.txt", "r");
        do{
            contenido =getc(archivo);
            printf("%c", contenido);}
        while (contenido !=EOF) ;
    
        imprimirmenu(productoss, precioss, n);
        
       printf("¿Quieres agregar otro producto? responde con (s) de lo contrario (n):  ");
    scanf("%c", &mas);
    getchar();
}
    //Crear un pedido
    while (confirmacion!='n'){
        
        cantidads = cantidad(productoss, n);
        //Calcular el precio del pedido
        totals = total(cantidads, precioss, n);
        
        //Calcular el precio total del pedido
        sumatorias = sumatoria(totals, n);
        
        //Desplegar el pedido
        imprimirpedido(productoss, precioss, cantidads, totals, n, sumatorias);
        
        //Querer otro pedido
        printf("Si quieres generar otro pedido teclea (s) a la siguiente pregunta de lo contrario (n)\n");
        printf("Quieres generar otro pedido?: ");
        scanf("%c", &confirmacion);
        getchar();
    }
    //Imprimir los pedidos pasados
    printf("Este es el resumen de todos los pedidos realizados anteriormente\n");
    archivo = fopen("/Users/arturotamayogonzalez/Documents/Xcode/Parcial 3/Parcial 3/Pedidos.txt", "r");
    do{
        contenido =getc(archivo);
        printf("%c", contenido);}
    while (contenido !=EOF) ;
    
}