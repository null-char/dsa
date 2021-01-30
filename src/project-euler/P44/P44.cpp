// Link: https://projecteuler.net/problem=44

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int pentagonalNumbers() {
    set<int> P;
    int i = 1;
    int c = 1;
    while (c < 25000000) {
      P.insert(c);
      i += 3;
      c += i;
    }

    for (int Pj : P) {
      for (int Pk : P) {
        if (P.find(Pk + Pj) != P.end() && P.find(Pk - Pj) != P.end()) {
          return abs(Pk - Pj);
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution soln;
  cout << soln.pentagonalNumbers();
}