#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int FILAS = 10;
const int COLUMNAS = 4;


struct Pasajero{
    char nombre[30];
    char apellido[30];
    int dni;
    int numAsiento;
};

void iniciarAsientos(struct Pasajero asientos[FILAS][COLUMNAS]){
    int contador = 1;
    for(int f = 0; f< FILAS; f++){
        for(int c=0; c<COLUMNAS; c++){
            strcpy(asientos[f][c].nombre,"-vacio-");
            strcpy(asientos[f][c].apellido, " ");
            asientos[f][c].dni = 0;
            asientos[f][c].numAsiento = contador++;
        }
    } 
}

void menu(){
    printf("\n*******************MENU************************\n");
    printf("\n1-Tomar reserva.");
    printf("\n2-Cancelar reserva.");
    printf("\n3-Listar de asientos.");
    printf("\n4-Consultar reserva por DNI.");
    printf("\n5-Consultar disponibilidad de asiento.");
    printf("\n6-Salir.\n");
}

void reservarAsiento(struct Pasajero asientos[FILAS][COLUMNAS]){
    printf("\n1-Tomar reserva.\n\n");

    for(int f = 0; f< FILAS; f++){
        for(int c=0; c<COLUMNAS; c++){
            if(strcmp(asientos[f][c].nombre,"-vacio-")==0){
                fflush(stdin);
                printf("Escriba el nombre del pasajero: ");
                gets(asientos[f][c].nombre);
                fflush(stdin);
                printf("Escriba el apellido del pasajero: ");
                gets(asientos[f][c].apellido);
                printf("Escriba el DNI del pasajero: ");
                scanf("%i",&asientos[f][c].dni);
                return;
            }
        }
    } 
}

void cancelarAsiento(struct Pasajero asientos[FILAS][COLUMNAS]){

    int dniCancelacion;
    int contador=0;
    int existe=0;

    printf("\n2-Cancelar reserva.\n");
    printf("Ingrese el DNI para cancelar la reserva: ");
    scanf("%i",&dniCancelacion);

    for(int f = 0; f< FILAS; f++){
        for(int c=0; c<COLUMNAS; c++){
            contador++;
            if(asientos[f][c].dni==dniCancelacion){
                strcpy(asientos[f][c].nombre,"-vacio-");
                strcpy(asientos[f][c].apellido, " ");
                asientos[f][c].dni = 0;
                asientos[f][c].numAsiento = contador;
                existe=1;
            }
        }
    } 

    (existe)?printf("\nLa reserva ha sido cancelada exitosamente."):printf("\nNo existe reserva para ese DNI"); 
}

void listarAsientos(struct Pasajero asientos[FILAS][COLUMNAS]){
    printf("\n3-Estado de asientos.\n\n");
    for(int f = 0; f< FILAS; f++){
        printf("(v) ") ; 
        for(int c=0; c<COLUMNAS; c++){
            if(asientos[f][c].numAsiento<=9){
                printf("   %i (%s/",asientos[f][c].numAsiento,asientos[f][c].nombre);
                (asientos[f][c].dni == 0)?printf("000000)"):printf("%i)",asientos[f][c].dni);
            }else{
                printf("  %i (%s/",asientos[f][c].numAsiento, asientos[f][c].nombre);
                (asientos[f][c].dni == 0)?printf("000000)"):printf("%i)",asientos[f][c].dni);
            }
        }
        printf("  (v)");
        printf("\n");
    } 
}

void consultarReserva(struct Pasajero asientos[FILAS][COLUMNAS]){
    printf("\n4-Consultar reserva por DNI.\n");
    int dniConsulta;
    int existe=0;
    printf("\nIngrese el DNI para consultar la reserva: ");
    scanf("%i",&dniConsulta);

    for(int f = 0; f< FILAS; f++){
        for(int c=0; c<COLUMNAS; c++){
            if(asientos[f][c].dni==dniConsulta){
                printf("El/la pasajero/a %s %s, segun DNI %i. Posee la reserva en el asiento %i\n",asientos[f][c].nombre,asientos[f][c].apellido,asientos[f][c].dni,asientos[f][c].numAsiento);
                existe=1;
            }
        }
    } 

    (!existe)?printf("\nNo existe reserva para ese DNI"):printf("\n"); 
}

void consultarAsiento(struct Pasajero asientos[FILAS][COLUMNAS]){
    printf("\n5-Consultar disponibilidad de asiento.\n");
    int asientoConsulta;
    printf("\nIngrese el numero de asiento del 1 al 40, para saber su estado.");
    scanf("%i",&asientoConsulta);
    
    for(int f = 0; f< FILAS; f++){
        for(int c=0; c<COLUMNAS; c++){
            if(asientos[f][c].numAsiento==asientoConsulta && strcmp(asientos[f][c].nombre,"-vacio-")==0){
                printf("\nEste asiento no esta ocupado.");
                if(c==0 || c==COLUMNAS-1){
                    printf("Ubicacion lado ventanilla");
                }else{
                    printf("Ubicacion central");
                }
            }

            if(asientos[f][c].numAsiento==asientoConsulta && strcmp(asientos[f][c].nombre,"-vacio-")!=0){
                printf("\nEste asiento esta ocupado.");
                if(c==0 || c==COLUMNAS-1){
                    printf("Ubicacion lado ventanilla");
                }else{
                    printf("Ubicacion central");
                }
            }
        }
    } 
}

int main(){


    //d --> disponible 
    //o --> ocupado {
    //      char nombre[30]
    //      char apellido[30]
    //      int dni
    //      int numAsiento = posición en la matriz ejemplo 0f - 0c
    //}

    //estados de reserva

    // 0 (v)  d -- d -- d -- d  (v) //
    // 1 (v)  d -- d -- d -- d  (v) //
    // 2 (v)  d -- d -- d -- d  (v) //
    // 3 (v)  d -- d -- d -- d  (v) //
    // 4 (v)  d -- d -- d -- d  (v) //
    // 5 (v)  d -- d -- d -- d  (v) //
    // 6 (v)  d -- d -- d -- d  (v) //
    // 7 (v)  d -- d -- d -- d  (v) //
    // 8 (v)  d -- d -- d -- d  (v) //
    // 9 (v)  d -- d -- d -- d  (v) //

    //-->Tomar reserva -->OK
    //-->Cancelar reserva -->OK
    //-->Listar los asientos si están o no ocupado, si están ocupados que muestre el nombre y dni -->OK
    //-->Consultar sobre una reserva a través del DNI, si está mostrar: nombre , apellido, y numero de asiento. De lo contrario indicar que no ha reservado ningún asiento. -->OK
    //-->Segun un numero de asiento, indicar si está desocupado y si está dispuesto del lado de la ventana.-->OK
    int opcion;
    struct Pasajero asientos[FILAS][COLUMNAS];
    iniciarAsientos(asientos);

    printf("\nBienvenidos al programa de reserva de asientos.\nSeleccione una opcion:\n");

    do
    {
        menu();
        scanf("%i",&opcion);
        switch (opcion)
        {
            case 1:
                reservarAsiento(asientos);
                break;
            case 2:
                cancelarAsiento(asientos);
                break;
            case 3:
                listarAsientos(asientos);
                break;
            case 4:
                consultarReserva(asientos);
                break;
            case 5: 
                consultarAsiento(asientos);
                break;
            default:
                if(opcion!=6) printf("No es un opcion correcta, pruebe con otra..");
        }
    } while (opcion != 6);
    

    printf("\n*****************SALIENDO**********************\n");
    printf("\nGracias por utilizar el sistema, adios!");

    return 0;
}