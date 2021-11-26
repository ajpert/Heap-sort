
/*******************************************
** Name: Andy James
** Email: jameandy@oregonstate.edu
** ID 933338855
********************************************/
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void percolateDown(int A[], int n, int index) {
    int temp;
    int left_node;
    int right_node;
    int swap_node = index;
    while(index < n) {
        left_node = 2 * index + 1;
        right_node = 2 * index + 2;

        //if the left node is smaller
        if((left_node < n) && A[index] > A[left_node]) { 
            swap_node = left_node;
        }
        //if the right node is smaller than both left and parent
        if(right_node < n && A[index] > A[right_node] && A[left_node] > A[right_node]) { 
            swap_node = right_node;
        }
        //swap if there was a change to the swap node
        if(swap_node != index) {
            temp = A[index];
            A[index] = A[swap_node];
            A[swap_node] = temp;
            index = swap_node;
        }
        else {
            break;
        }
    }
}

void heapify(int A[], int n) {
    int i;
    for(i = ((n-2)/2); i >= 0; i--) {
        percolateDown(A,n,i);
    }

}

void heapsort(int A[], int n) {
    int temp;
    int i = n - 1;
    heapify(A,n);
    for(i; i >= 0; i--) {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        percolateDown(A,i,0);
    }
}