#include<iostream>

long int recursive_mult(long int a, long int b){

if( b == 1) return a;

int half = b >> 1;
long int half_part = recursive_mult(a, half);

if( b%2 == 0){

return half_part + half_part;
}else{

return half_part + half_part + a;
}

}

int main(){

int a = 10;
int b = 5;

std::cout << recursive_mult(a, b) << "\n";

return 0;
}
