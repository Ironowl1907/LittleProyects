#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo;

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    
    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
  int a = 100;
  memo.resize(a +1, -1);
  cout << fibonacci(a) << endl;
  return 0;
}