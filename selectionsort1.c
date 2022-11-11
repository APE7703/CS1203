//Course Deliverable 11

#include <stdio.h>
#include <stdlib.h>

//Function Prototypes

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
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(int i=0; i<length; i++){
        int p=i;
        for(int j=i+1; j<length; j++){
            if(arr[p]>arr[j]){
                p = j;
            }  
        }
        int temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp;
    }
    printf("Sorted array: ");
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}
