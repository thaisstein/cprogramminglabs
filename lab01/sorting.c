#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* fills an array of a given length with random
numbers in the range 0-99 */
void rand_fill(int** array, unsigned int lenght) {
    int* temp = (int*)malloc(lenght * sizeof(unsigned int));
    if (temp == NULL) {
        exit(0);
    }
    time_t time_seed;
    srand((unsigned) time(&time_seed));
    for (int j = 0; j < lenght ;j++) {
        temp[j] = rand()%100;
    }
    *array = temp; 
}

/* fills an array of a given length in descending order */
void inverse_rand_fill(int** array, unsigned int lenght) {
    int* temp = (int*)malloc(lenght * sizeof(unsigned int));
    if (temp == NULL) {
        exit(0);
    }
    int aux = lenght;
    time_t time_seed;
    srand((unsigned) time(&time_seed));
    for (int j = 0; j < lenght ;j++) {
        temp[j] = aux;
        aux --;
    }
    *array = temp;
}

/*switches values of pointers */
void change(int *x, int *y) {
 int z; 
 z = *x; 
 *x = *y; 
 *y = z; 
}


 void bubble_sort(int* array, int n) {
    int temp, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                change(&array[j], &array[j+1]);
            }
        }
    }
}


void insertion_sort(int* array, int n) {
    int temp,  j;
    for (int i = 1; i < n; i++) {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
}

void selection_sort(int* array, int n) {
    int min, temp;
    for (int i = 0; i < n-1; i++) {
        min= i;
        for (int j = i+1; j < n; j++)
            if (array[j] < array[temp])
                min = j;
            if(min != i)
                change(&array[min], &array[i]);
    }
}

void time_measure(int*array) {
    /* sorting for 5 generated arrays of lenght L and 5 generated arrays in descending
    order of lenght L */
    long double elapsed_time;
    clock_t start, end;
    int index = 10;

        /* bubble sort*/
    for (int i = 0; i < 5; i++) {
        rand_fill(&array, index);
        start = clock();
        bubble_sort(array, index);
        end = clock();
        elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
        elapsed_time *= 10e2;
        printf("bubble sort runs in %LF ms with a random array of size %d\n", elapsed_time, index);
        inverse_rand_fill(&array, index);
        start = clock();
        bubble_sort(array, index);
        end = clock();
        elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
        elapsed_time *= 10e2;
        printf("bubble sort runs in %LF ms with an array of size %d filled in descending order\n", elapsed_time, index);
        index = index*10;
        printf("\n");
        free(array);
    }
    printf("\n");
    index = 10;
    /* insertion sort */
    for (int i = 0; i < 5; i++) { 
        rand_fill(&array, index);
        start = clock();
        insertion_sort(array, index);
        end = clock();
        elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
        elapsed_time *= 10e2;
        printf("insertion sort runs in %LF ms with a random array of size %d\n", elapsed_time, index);            inverse_rand_fill(&array, index);
        start = clock();
        insertion_sort(array, index);
        end = clock();
        elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
        elapsed_time *= 10e2;
        printf("insertion sort runs in %LF ms with an array of size %d filled in descending order\n", elapsed_time, index);
        index = index*10;
        printf("\n");
        free(array);
    }
    printf("\n");
    index = 10;
    /* selection sort */
    for (int i = 0; i < 5; i++) { 
        rand_fill(&array, index);
        start = clock();
        selection_sort(array, index);
        end = clock();
        elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
        elapsed_time *= 10e2;
        printf("selection sort runs in %LF ms with a random array of size %d\n", elapsed_time, index);            inverse_rand_fill(&array, index);
        start = clock();
        selection_sort(array, index);
        end = clock();
        elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
        elapsed_time *= 10e2;
        printf("selection sort runs in %LF ms with an array of size %d filled in descending order\n", elapsed_time, index);
        index = index*10;
        printf("\n");

        free(array);
    }
  
}
 

int main() {
    int* array; //global
    int index = 10;

    long double elapsed_time;
    clock_t start, end;
    time_measure(array); 


    return 0;
}
