#include<iostream>
#include<cstdio>

int smallSubarraySumGreater(int arr[], int n, int x){

    int start =0;
    int end = 0;
    int min_len = n+1;
    int curr_sum = 0;

    while( end < n){

	while( curr_sum <=x && end < n){
	    curr_sum += arr[end];
	    end++;
	}

	while( curr_sum > x && start < n){
	    if( end-start < min_len){
		min_len = end-start;
	    }
	    curr_sum -= arr[start];
	    start++;

	}

	return min_len;
    }
}

int main(){

int arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
int n = sizeof(arr)/sizeof(arr[0]);
int x = 280;
int min_len = smallSubarraySumGreater(arr,n, x);

std::cout << min_len << "\n";

return 0;


}
