//Course Deliverable 12

#include <stdio.h>
#include <stdlib.h>

void insertionsort(int* ar, int n);
void printarray(int *ar, int n);


int main(int argc, char** argv){
    int length;
    printf("Enter chosen length for array: \n");
    scanf("%d", &length);
    //if length of input is 1 or less than 1 than the input is wrong as there is no need to reverse
    if (length < 2){
        printf("Input is erroneous. \n");
        return -1;
    }
    int arr[length];
    for(int i=0; i<length; i++){
        printf("Enter value: \n");
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    printarray(arr, length);
    /*for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");*/

    insertionsort(arr, length);

    printf("Sorted array: ");
    printarray(arr, length);
}

void insertionsort(int ar[], int n){
    for(int i=1; i<n; i++){
        int k = ar[i];
        int j = i-1;

        while (k < ar[j] && j>=0)
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = k;
    }
}

void printarray(int ar[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", ar[i]);
    }
    printf("\n");
}
