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

/* switches values of pointers */
void change(int *x, int *y) {
 int z; 
 z = *x; 
 *x = *y; 
 *y = z; 
}

/* partitioning with the middle element as pivot */
int partition(int* array, int smaller, int biggest)
{
    int pivot = array[((biggest + smaller)/2)];
    int i = (smaller- 1); 
    for (int j = smaller; j <= biggest - 1; j++) {
        // If current element is smaller than the pivot
        if (array[j] < pivot) {
            i++; // increment index of smaller element
            change(&array[i], &array[j]);
        }
    }
    change(&array[i + 1], &array[biggest]);
    return (i + 1);
}

void quick_sort(int* array, int smaller, int biggest)
{
    if (smaller < biggest) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int divide = partition(array, smaller, biggest);
        quick_sort(array, smaller, divide - 1);
        quick_sort(array, divide + 1, biggest);
    }
}  

void heapify(int* array, int index, int aux) {
    int biggest = aux; // tree root
    int left = (2*aux + 1);
    int right = left + 1;
    if (left < index && array[left] > array[biggest]) { // left child
        biggest = left;
    }
    if(biggest != aux) {
        change(&array[aux], &array[biggest]);
        heapify(array, index, biggest);
    }
}

void heap_sort(int array[], int index) {
    /* max heap */
    for(int i = (index/2)-1; i <= 0; i--) {
        heapify(array, index, i);
    } 
    /* heap sort */
    for (int i = index - 1; i >=0; i--) {
        change(&array[0], &array[i]);
        heapify(array, i, 0);
    }

}

void media_calculator(long double * list) {
    long double media[5];
    int aux = 10;
    for (int i = 0; i < 5; i++) {
        media[i] = list[i]/5;
    }
    for(int p = 0; p < 5; p++) {
         printf("the media of trials for an array of size %d is %LF \n", aux, media[p]);    
         aux = aux*10;
    }
}

void time_measure(int *array) {
    /* sorting for 5 generated arrays of lenght L and 5 generated arrays in descending
    order of lenght L */
    long double elapsed_time;
    clock_t start, end;
    int index = 10;
    long double medias_random[5] = {0};
    long double medias_reversed[5] = {0};

        /* quick sort */
    for(int j = 0; j < 5; j++) { //number of trials loop
        index = 10;
        for (int i = 0; i < 5; i++) { //list of sizes loop
            rand_fill(&array, index);
            start = clock();
            quick_sort(array, 0, index - 1);
            end = clock();
            elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
            elapsed_time *= 100;
          //  printf("quick sort runs in %LF ms with an array of size %d filled in random order\n", elapsed_time, index);

            medias_random[i] += elapsed_time; //adds to the list of medias

            inverse_rand_fill(&array, index);
            start = clock();
            quick_sort(array, 0, index - 1);
            end = clock();
            elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
            elapsed_time *= 100;
          //  printf("quick sort runs in %LF ms with an array of size %d filled in descending order\n", elapsed_time, index);
            medias_reversed[i] += elapsed_time;
            index = index*10;
        }
        free(array);
    }
    printf("QUICK SORT ALGORITHM:\n");
    printf("for a random generated array:\n");
    media_calculator(medias_random); 
    printf("for a reversed array:\n");
    media_calculator(medias_reversed);
    printf(" \n");


            /* heap sort */
    for(int j = 0; j < 5; j++) { //number of trials loop
        index = 10;
        for (int i = 0; i < 5; i++) { //list of sizes loop
            rand_fill(&array, index);
            start = clock();
            heap_sort(array, index);
            end = clock();
            elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
            elapsed_time *= 100;

            medias_random[i] += elapsed_time; //adds to the list of medias

            inverse_rand_fill(&array, index);
            start = clock();
            heap_sort(array, index);
            end = clock();
            elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
            elapsed_time *= 100;
            medias_reversed[i] += elapsed_time;
            index = index*10;
        }
        free(array);
    }
    printf("HEAP SORT ALGORITHM:\n");
    printf("for a random generated array:\n");
    media_calculator(medias_random); 
    printf("for a reversed array:\n");
    media_calculator(medias_reversed);
}
 

int main() {
    int* array; //global
    int index = 10;

    long double elapsed_time;
    clock_t start, end;
    time_measure(array); 


    return 0;
}
