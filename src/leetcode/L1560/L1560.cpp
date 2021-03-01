// Link: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> mostVisited(int n, vector<int>& rounds) {
    vector<int> res;
    for (int i = rounds[0]; i <= rounds[rounds.size() - 1]; ++i)
      res.push_back(i);
    if (res.size() > 0) return res;
    for (int i = 1; i <= rounds[rounds.size() - 1]; ++i) res.push_back(i);
    for (int i = rounds[0]; i <= n; ++i) res.push_back(i);
    return res;
  }
};

int main() {
  vector<int> rounds{1, 3, 1, 2};
  int n = 4;
  Solution soln;

  // Should output "1 2"
  for (auto x : soln.mostVisited(n, rounds)) {
    cout << x << ' ';
  }
}