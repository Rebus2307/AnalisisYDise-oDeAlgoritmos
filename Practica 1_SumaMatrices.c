/*
    PRACTICA 2
    INTEGRANTES: 
    -BERROSPE NEGRETE ANGELA ALESSANDRA
    -CRUZ MERLIN WILFRIDO   
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Para las funciones clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> //Para la funcion sleep
#define M 200  //Definimos el numero maximo de filas y columnas
#define N 200

void Suma_Matrices();

int main(){

    double time_spent = 0.0; //Para almacenar el tiempo de ejecución del código

    printf("\n\n\t-PRACTICA 2-");
    printf("\n\tSuma de matrices");

    int tam;
    int A[M][N], B[M][N], R[M][N]; 

    printf("\n\n\tIngrese el tama%co de las matrices a trabajar: ", 164);
    scanf("%d", &tam);

    if(tam<2000){

        int i, j;

        srand(time(NULL));  //Generación de numeros aleatorios

        for(i=0; i<tam; i++){                 //Creamos matriz A
            for(j=0; j<tam; j++){
            A[i][j] = rand()%199 -99;          //LLenamos la matriz de numeros aleatorios de -99 a 99
            }
        }

        printf("\n\nLa matriz A: \n");

        /*for(i=0; i<tam; i++){                 //Mostramos la matriz A
            for(j=0; j<tam; j++){
            printf("%d\t", A[i][j]);
            }
            printf("\n");
        }*/


        for(i=0; i<tam; i++){                 //Creamos matriz B
            for(j=0; j<tam; j++){
            B[i][j] = rand()%199 -99;        //LLenamos la matriz de numeros aleatorios de -99 a 99
            }
        }

        printf("\n\nLa matriz B: \n");

       /* for(i=0; i<tam; i++){                 //Mostramos la matriz B
            for(j=0; j<tam; j++){
            printf("%d\t", B[i][j]);
            }
            printf("\n");
        }*/

        clock_t begin = clock();

        Suma_Matrices(A, B, R, tam);    //Llamamos a la funcion para realizar la suma de las matrices
        //sleep(1);                                   //Dejamos que el programa se detenga por 1 segundo

        clock_t end = clock();

       printf("\n\nEl resultado de la suma de matrices es: \n");
        
       /* for(i=0; i<tam; i++){                 //Mostramos la matriz resultado (R)
            for(j=0; j<tam; j++){
                printf("%d\t", R[i][j]);
            }
            printf("\n");
        }*/

        /*Calculamos el tiempo transcurrido encontrando la diferencia (end - begin) y
        dividiendo la diferencia por CLOCKS_PER_SEC para convertir a segundos*/
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

        printf("\n\n\tEl tiempo transcurrido es de: %f segundos\n\n", time_spent);

    }else{
        printf("\n\nError: Usted ingreso un numero mayor al rango permitido\n\n");
    }

    return 0; 
}

void Suma_Matrices(int A[M][N], int B[M][N], int R[M][N], int tam){

    int i, j;

    for(i=0; i<tam; i++){         //Sumamos las matrices 'A+B' y el resultado lo guardamos en la matriz R
        for(j=0; j<tam; j++){
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}
