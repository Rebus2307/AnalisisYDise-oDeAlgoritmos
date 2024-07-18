/*
	PRACTICA 3
 	Integrantes:
	-Cruz Merlin Wilfrido
 	-Berrospe Negrete Angela Alessandra 
 */

#include "Ordenamientos.c"

int main(){

    int ban = 0, opc; 
    int *array, i;

    while (ban == 0){

        double time_spent = 0;
        int num = 0;

        system("cls");
        printf("\n\n\t-PRACTICA 3-");
        printf("\n\n\t1.Insertion");
        printf("\n\t2.Selection");
        printf("\n\t3.Merge");     
        printf("\n\t4.Burbuja");      
        printf("\n\t5.Salir");
        printf("\n\tSeleccione una opcion: ");
        scanf("%d", &opc);

        switch (opc){
        case 1:
            system("cls");
            printf("\nUsted selecciono Insertion\n");
            printf("\n\nIngrese la cantidad de variables: ");
            scanf("%d", &num);

            array = calloc(num, sizeof(int)); //Asignacion de memoria dinamica de tipo "entero"
            srand(time(NULL));      //Generación de numeros aleatorios

            printf("\nArreglo desordenado:\n");
            for(i=0; i<num; i++){   
                array[i] = rand()%99 +1;  
                //printf("%d ", array[i]);
            }

            printf("\n\n\tEl arreglo ordenado queda asi: \n\n");

            clock_t begin = clock();
            Insertion_Sort(array, num); //Llamamos a la funcion Insertion_Sort
            clock_t end = clock();

            //Mostramos el arreglo ya ordenado
            for(i=0; i<num; i++){
                //printf("%d ", array[i]);
            }

            free(array); //Liberamos el arreglo

            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\n\n\tEl tiempo transcurrido es de: %f segundos\n\n", time_spent);

            system("pause");
         break;
        
        case 2:
            system("cls");
            printf("\nUsted selecciono Selection\n");
            printf("\n\nIngrese la cantidad de variables: ");
            scanf("%d", &num);

            array = calloc(num, sizeof(int)); //Asignacion de memoria dinamica de tipo "entero"
            srand(time(NULL));      //Generación de numeros aleatorios

            printf("\nArreglo desordenado:\n");
            for(i=0; i<num; i++){   
                array[i] = rand()%99 +1;  
                //printf("%d ", array[i]);
            }

            printf("\n\n\tEl arreglo ordenado queda asi: \n\n");

            clock_t one = clock();
            Selection_Sort(array, num); //Llamamos a la funcion Selected
            clock_t two = clock();

            //Mostramos el arreglo ya ordenado
            for(i=0; i<num; i++){
                printf("%d ", array[i]);
            }

            free(array); //Liberamos el arreglo

            time_spent += (double)(two - one) / CLOCKS_PER_SEC;
            printf("\n\n\tEl tiempo transcurrido es de: %f segundos\n\n", time_spent);

            system("pause");
         break;

        case 3:
            system("cls");
            printf("\nUsted selecciono Merge\n");
            printf("\n\nIngrese la cantidad de variables: ");
            scanf("%d", &num);

            array = calloc(num, sizeof(int)); //Asignacion de memoria dinamica de tipo "entero"
            srand(time(NULL));

            printf("\nArreglo desordenado:\n");
            for (i = 0; i < num; i++) {
                array[i] = rand() % 99 + 1;  	//Llena el arreglo con numeros aleatorios del 1 al 99
                //printf("%d ", array[i]);
            }

            clock_t ini = clock();
            mergeSort(array, 0, num - 1); //Llamamos a la funcion Merge
            clock_t fin = clock();

            printf("\n\n\tArreglo ordenado:\n ");
            for (i = 0; i < num; i++) {
            	//printf("%d ", array[i]);
            }

            free(array); //Liberamos el arreglo

            time_spent += (double)(fin - ini) / CLOCKS_PER_SEC;
            printf("\n\n\tEl tiempo transcurrido es de: %f segundos\n\n", time_spent);

            system("pause");
         break;
        
        case 4:
            system("cls");
            printf("\nUsted selecciono Burbuja\n");
            printf("\n\nIngrese la cantidad de variables: ");
            scanf("%d", &num);

            array = calloc(num, sizeof(int)); //Asignacion de memoria dinamica de tipo "entero"
            srand(time(NULL));      //Generación de numeros aleatorios

            printf("\nArreglo desordenado:\n");
            for(i=0; i<num; i++){   
                array[i] = rand()%99 +1;  
                //printf("%d ", array[i]);
            }

            printf("\n\n\tEl arreglo ordenado queda asi: \n\n");

            clock_t uno = clock();
            bubble_sort(array, num); //Llamamos a la funcion bubble_sort
            clock_t dos = clock();

            //Mostramos el arreglo ya ordenado
            for(i=0; i<num; i++){
                //printf("%d ", array[i]);
            }

            free(array); //Liberamos el arreglo

            time_spent += (double)(dos - uno) / CLOCKS_PER_SEC;
            printf("\n\n\tEl tiempo transcurrido es de: %f segundos\n\n", time_spent);

            system("pause");
         break;
        
        case 5:
            ban = 1; 
         break;
        
        default:
            printf("\n\nERROR: Opcion equivocada\n");
            system("pause");
         break;
        }
    }

    return 0;
}