/* Copyright
*/
#include <iostream>

int fib_memo(int n, int memo[]) {
        if (n ==0 || n == 1) {
              return n;
        }
        if (!memo[n]) {
                memo[n] = fib_memo(n-1, memo) + fib_memo(n-2, memo);
              }
        return memo[n];
}

int fib(int n) {
        int memo[n+1]={0};
        return fib_memo(n, memo);
}
int main() {
        int n;
        std::cin >> n;
        std::cout << fib(n) << "\n";

        return 0;
}
