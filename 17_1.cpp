#include<bits/stdc++.h>

int add(int a, int b){

    if( b == 0) return a;

    int sum = a^b;
    int carry = (a&b) << 1;

    return add(sum, carry);
}

int main(){

    int a = 4;
    int b = 5;

    printf("%d\n", add(4,5));

    return 0;
}
