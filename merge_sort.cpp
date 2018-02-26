#include<cstdio>
#include<iostream>


void merge(int arr[], int low, int mid, int high){

    int n1 = mid-low + 1 ; //
    int n2 = high-mid ; // high -(mid+1) -1

    int left[n1];
    int right[n2];

    for(int i=0; i < n1; ++i){
	
	left[i] = arr[low+i];

    }

    for(int j=0; j < n2; ++j){
	right[j] = arr[mid+1+j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while( i < n1 && j < n2){

	if(left[i] <= right[j]){

	    arr[k] = left[i];
	    ++i;
	    ++k;
	}else{

	    arr[k] = right[j];
	    ++j;
	    ++k;
	}
    }


    while( i < n1){

	arr[k] = left[i];
	++i;
	++k;
    }

    while(j < n2) {

	arr[k] = right[j];
	++j;
	++k;
    }

}

void mergeSort(int arr[], int low, int high){

    //printf("%d %d\n", low, high);
    if(low < high){

	int mid = low + (high -low)/2;

	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);

    }
}

void printArray(int arr[], int n){

    int i=0;
    while( i< n){

	printf("%d ", arr[i]);
	++i;
    }

    printf("\n");

}


int main(){


    int a[] = {12,9,20,100,22,40,51,12,40,86};

    int n = sizeof(a)/sizeof(a[0]);

    printArray(a, n);

    mergeSort(a, 0, n-1);

    printArray(a, n);

    return 0;

}

