#include<iostream>

/*! \brief This code calculates the product of  
 *    numbers without multiplication operator.
 *    Problem 8.5 of CTCI Ch8 Recursion and Dynamics
 */

//! Helper function to the main function

int minMultiplyHelper(int bigger, int smaller){

    if(smaller == 0) return 0;
    if(smaller == 1) return bigger;

    int s = smaller >> 1; // divide by 2;
    int hf_product = minMultiplyHelper(bigger, s);
    std::cout << hf_product << "\n";
    hf_product <<= 1;

    if(smaller%2 == 0){

	return  hf_product; 

    }else{

	return ( hf_product += bigger);
    }
}

//! Function to calculate the product of two integers
/*!
  \param a an integer
  \param b other integer
  \return product of a and b
 */

int minMultiply(int a, int b){

    int bigger  = (a>b)?a:b;
    int smaller = (a<b)?a:b;

    return minMultiplyHelper(bigger, smaller);
}

// !Main function

int main(){

    int big = 10;
    int small = 2;

    std::cout << minMultiply(10,2) << std::endl;

    return 0;
}
