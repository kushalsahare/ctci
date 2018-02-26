#include<iostream>

using namespace std;

void swap(int*a, int *b){
int temp = *a;

*a = *b;

*b = temp;

}


int main(){


int A[7]={9,8,7,6,5,4,3};


for (int i=0; i< 6; i++){
for(int j=0; j < (6-i); j++){

if (A[j]>A[j+1])
swap(A[j],A[j+1]);

}


}

for (int i=0; i<7; i++)
cout << A[i] << " ";

cout << "\n";

return 0;
}
