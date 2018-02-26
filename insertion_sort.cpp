#include<iostream>


int main(){

	int A[7]={1,3,7,4,6,9,2};

	for (int j=1; j<7;j++){

		int key=A[j];

		int i=j-1;

		while(i>-1 && A[i]>=key){

			A[i+1] = A[i];

			i=i-1;
		}
		A[i+1]= key;

	};

	for (int i=0;i<7; i++){
		std::cout << A[i] << " ";}

	std::cout << std::endl;

	return 0;
}
