//Course Deliverable 1

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    float limit = 0.00000004;
    float increment = 0.0000000002;
    int count = 1;
    for(float i = 0; i<=limit; i = i+increment){
        printf("Loop %d\n", count);
        count++;
    }

    return 0;

}

//loop ran 200 times = limit/increment
