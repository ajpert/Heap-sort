/*******************************************
** Name: Andy James
** Email: jameandy@oregonstate.edu
** ID 933338855
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "heap_james.c"

int main(int argc, char* argv[]) {
    int i;
    int n = argc-1;

    // save command line arguments (keys) in an array
    int* A = malloc(n * sizeof(int));
    for (i=0; i<n; i++) {
        A[i] = atoi(argv[i+1]);
    }

    // sort the array using heapsort
    if (n > 0) {
        heapsort(A, n);
    }

    // print array after sorting
    printf("Sorted Array\n");
    for (i=n-1; i>=0; i--) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);
    return 0;
}
