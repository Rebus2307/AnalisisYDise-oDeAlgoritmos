/*
    PRACTICA 1
    INTEGRANTES: 
    -BERROSPE NEGRETE ANGELA ALESSANDRA
    -CRUZ MERLIN WILFRIDO   
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Para las funciones clock_t, clock(), CLOCKS_PER_SEC

void Insertion_Sort();

int main(){

    int *array, num;
    double time_spent = 0.0; //Para almacenar el tiempo de ejecucion del codigo

    printf("\n\n\t-PRACTICA 1-");
    printf("\n\tOrdenamiento por Insercion");
    printf("\n\n\tIngrese el numero de variables a trabajar: ");
    scanf("%d", &num);

    array = calloc(num, sizeof(int)); //Asignacion de memoria dinamica de tipo "entero"
    srand(time(NULL));      //Generación de numeros aleatorios

    printf("\n\n");

    int i;

    for(i=0; i<num; i++){   
        array[i] = rand()%100 +1;   //Definimos el rango de los numeros aleatorios (1-100)

       // printf("%d ", array[i]);
    }

    printf("\n\n\tEl arreglo ordenado queda asi: \n\n");

    clock_t begin = clock();

    Insertion_Sort(array, num); //Llamamos a la funcion Insertion_Sort

    clock_t end = clock();

    //Mostramos el arreglo ya ordenado
    if(num<50){                         //En caso que sean menos de 50 elementos, mostramos todos los elementos
        for(i=0; i<num; i++){           
            printf("%d ", array[i]);
        }
    }else{
        for(i=0; i<50; i++){            //En caso que sean mas de 50 elementos, solo imprimiremos los primeros 50
            printf("%d ", array[i]);
        }
    }

    free(array);

    /*Calculamos el tiempo transcurrido encontrando la diferencia (end - begin) y
    dividiendo la diferencia por CLOCKS_PER_SEC para convertir a segundos*/
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n\n\tEl tiempo transcurrido es de: %f segundos\n\n", time_spent);

    return 0;
}

void Insertion_Sort(int array[], int num){

    int i; 

    for(i=1; i<num; i++){
        int key = array[i];
        int j = i-1;

        while(j>=0 && array[j]>key){
            array[j+1] = array[j];
            j = j-1; 
        }
        array[j+1] = key; 
    }
}
