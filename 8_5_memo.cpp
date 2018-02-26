#include<iostream>

int mult_memo(int big, int small, int memo[]){

    if(small == 0 ) return 0;
    if(small == 1 ) return big;
    if( memo[small] != 0) return memo[small];


    int s = small >> 1;

    int hprod1 = mult_memo(big, s, memo) ;// half product
    int hprod2 = hprod1;

    if(small %2 != 0){
	hprod2 = mult_memo(big, small-s, memo);

    }

    memo[small] = hprod1+hprod2;
    return memo[small];
}

int mult_(int a, int b){

    int small = a < b ? a : b;
    int big  =  a > b ? a : b;

    int memo[small+1]={0};


    return mult_memo(big, small, memo);


}


int main(){


    int a = 10;
    int b = 2;

    std::cout << mult_(a, b) << std::endl;
    return 0;
}
