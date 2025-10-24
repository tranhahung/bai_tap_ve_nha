#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *p;
    int size;
} Array;

void initArray(Array *a, int size, const char *data) {
    a->p=(int *)malloc(size * sizeof(int));
    a->size=size;
    char buffer[100];
    strcpy(buffer, data);
    char *token=strtok(buffer, ",");
    int index=0;
    while (token != NULL){
        a->p[index++]=atoi(token);
        token=strtok(NULL,",");
    }
}
void insertArray(Array *a,int var,int index) {
    a->size++;
    int *temp = (int *)realloc(a->p, a->size * sizeof(int));
    if (temp == NULL) {
        printf("\nInsert fail\n");
        return;
    }
    a->p = temp;
    for (int i = a->size - 1; i >= index; i--) {
        if (i == index) {
            a->p[i] = var;
        } else {
            int tmp = a->p[i];
            a->p[i] = a->p[i - 1];
            a->p[i - 1] = tmp;
        }
    }
}

void printArray(Array *a) {
    printf("\n");
    for (int i = 0; i < a->size; i++) {
        printf("%d ", a->p[i]);
    }
    printf("\n");
}

void freeArray(Array *a) {
    free(a->p);
}

void deleteEle(Array *p, int index) {
    for (int i = index; i < p->size - 1; i++) {
        int tmp = p->p[i + 1];
        p->p[i + 1] = p->p[i];
        p->p[i] = tmp;
    }
    int *temp = (int *)realloc(p->p, (p->size - 1) * sizeof(int));
    if (temp == NULL) {
        printf("\nDelete fail\n");
        return;
    }
    p->size--;
    p->p = temp;
}

void selectionSort(Array *p) {
    printf("\nProcedure selection sort\n");
    int i, j, min_ind;
    for (i = 0; i < p->size - 1; i++) {
        min_ind = i;
        for (j = i + 1; j < p->size; j++) {
            if (p->p[min_ind] > p->p[j]) {
                min_ind = j;
            }
        }
        printf("Step %d: Min %d\n", i + 1, p->p[min_ind]);
        int temp = p->p[i];
        p->p[i] = p->p[min_ind];
        p->p[min_ind] = temp;
        printArray(p);
    }
}

void insertSort(Array *p) {
    printf("\nProcedure insertion sort\n");
    for (int i = 1; i < p->size; i++) {
        int j = i;
        int x = p->p[i];
        while (j > 0 && p->p[j - 1] > x) {
            p->p[j] = p->p[j - 1];
            j--;
        }
        p->p[j] = x;
        printf("Step %d: Inserted %d\n", i, x);
        printArray(p);
    }
}

void bubbleSort(Array *p) {
    printf("\nProcedure bubble sort\n");
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size - i - 1; j++) {
            if (p->p[j] > p->p[j + 1]) {
                int temp = p->p[j];
                p->p[j] = p->p[j + 1];
                p->p[j + 1] = temp;
            }
        }
        printArray(p);
    }
}

void quickSort(Array *p, int left, int right) {
    int i = left, j = right;
    int pivot = p->p[(left + right) / 2];
    while (i <= j) {
        while (p->p[i] < pivot)
            i++;
        while (p->p[j] > pivot)
            j--;
        if (i <= j) {
            int temp = p->p[i];
            p->p[i] = p->p[j];
            p->p[j] = temp;
            i++;
            j--;
        }
    }
}

int main() {
    Array a;
    initArray(&a, 5, "5,3,4,1,2");
    printf("Initial array:");
    printArray(&a);

    selectionSort(&a);
    insertSort(&a);
    bubbleSort(&a);

    insertArray(&a, 10, 2);
    printf("\nAfter inserting 10 at index 2:");
    printArray(&a);

    deleteEle(&a, 3);
    printf("\nAfter deleting element at index 3:");
    printArray(&a);

    freeArray(&a);
    return 0;
}

