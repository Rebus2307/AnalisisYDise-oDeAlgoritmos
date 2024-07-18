#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Find_Max_Crossing_subarray(int A[], int low, int mid, int high, int *max_left, int *max_right){
	
	int left_sum = -100000; 
	int right_sum = -100000;
	int sum = 0;

	int i;
	for(i = mid; i >= low; i--){
		sum += A[i];

		if(sum > left_sum){
			left_sum = sum;
			*max_left = i;
		}
	}
	
	sum = 0; 

	int j;
	for(j = mid + 1; j <= high; j++){
		sum += A[i];
		if(sum > right_sum){
			right_sum = sum; 
			*max_right = j;
		}
	}

	return left_sum + right_sum;
}
int Find_Max_Subarray(int A[], int low, int high, int *max_left, int *max_right){
	if(low == high){
		*max_left = *max_right = low;
		return A[low];	//Caso base: Solo un elemento
	}

	int mid = (low + high) / 2;
	int left_low, left_high;
	int right_low, right_high;
	int cross_low, cross_high;

	int left_sum = Find_Max_Subarray(A, low, mid, &left_low, &left_high);
	int right_sum = Find_Max_Subarray(A, mid + 1, high, &right_low, &right_high);
	int cross_sum = Find_Max_Crossing_subarray(A, low, mid, high, &cross_low, &cross_high);

	if(left_sum >= right_sum && left_sum >= cross_sum){
		*max_left = left_low;
		*max_right = left_high;
		return left_sum;
	}else if(right_sum >= left_sum && right_sum >= cross_sum){
		*max_left = right_low;
		*max_right = right_high;
		return right_sum;
	}else{
		*max_left = cross_low;
		*max_right = cross_high;
		return cross_sum;
	}
}


int main(){
	
	int ini, fin;
	int n;
	
	system("cls");
	printf("\n-MAXIMO SUBARREGLO-");
	printf("\n\nIngrese el tamanio del arreglo: ");
	scanf("%d", &n);

	int array[n];		//Arreglo de tamanio 'n'
	srand(time(NULL));

	printf("\nPrecio:		");	//Imprimimos los precios de manera aleatoria
	
	int i;
	for (i = 0; i < n; i++) {
    	array[i] = rand() % 99 + 1;  	//Llena el arreglo con numeros aleatorios del 1 al 99
        printf("%d  ", array[i]);
    }

	printf("\nDiferencia:	");
	int w = n-1;
    int dif[w]; 			//Arreglo de diferencias entre elementos

    for(i = 0; i < w; i++){
    	dif[i] = array[i+1] - array[i];
    	printf("%d  ", dif[i]);			//Imprimimos la diferencia entre los elementos
    }

    printf("\n");

    int max_sum = Find_Max_Subarray(dif, 0, w - 1, &ini, &fin);	//Llamamos a la función "Find_Max_Subarray"

	printf("\nEl subarreglo con la suma maxima es: ");
	for(i = ini; i <= fin; i++){
		printf("%d ", dif[i]);
	}

    printf("\n\nLa suma maxima del subarreglo es : %d\n", max_sum);	   

	return 0;
}
