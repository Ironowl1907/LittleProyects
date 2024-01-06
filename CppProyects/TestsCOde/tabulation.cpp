#include<iostream>
#include<vector>

using namespace std;

// long fib(int N){
//   vector<long> arr(N+1,0);
//   arr[1] = 1;

//   for (int i = 0; i <= N; i++){
//     arr[i+1] += arr[i];
//     arr[i+2] += arr[i];
//   }
//   return arr[N];
// }

// long gridTraveler(long M, long N){
//   vector<vector<long>> arr(M+1,vector<long>(N+1,0));
//   arr[1][1] = 1;
//   long current;

//   for (int Y = 0; Y <= M; Y++){
//     for (int X = 0; X <= N;X++){
//       current = arr[Y][X];

//       if (X+1 <= N) arr[Y][X+1] += current;
//       if (Y+1 <= M) arr[Y+1][X] += current;
//     }
//   }
//   return arr[M][N];
// }



int main (){
// cout << fib(6) << endl;
// cout << fib(7) << endl;
// cout << fib(8) << endl;
// cout << fib(50) << endl;

// cout << gridTraveler(1,1) << endl;
// cout << gridTraveler(2,3) << endl;
// cout << gridTraveler(3,2) << endl;
// cout << gridTraveler(3,3) << endl;
// cout << gridTraveler(18,18) << endl;

  return 0;
}
