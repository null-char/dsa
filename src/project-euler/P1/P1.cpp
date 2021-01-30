// Link: https://projecteuler.net/problem=1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int sumMultiplesOf3And5(int N) {
    int sum = 0;

    for (int i = 1; i < N; i++) {
      if (i % 3 == 0 || i % 5 == 0) {
        sum += i;
      }
    }

    return sum;
  }
};

int main() {
  Solution soln;
  cout << soln.sumMultiplesOf3And5(1000) << '\n';
}