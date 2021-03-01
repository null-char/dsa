// Link:
// https://leetcode.com/problems/check-array-formation-through-concatenation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    vector<int> pos(101, -1);

    for (int i = 0; i < pieces.size(); i++) {
      pos[pieces[i][0]] = i;
    }

    for (int i = 0; i < arr.size();) {
      int p = pos[arr[i]];
      if (p == -1) return false;
      auto piece = pieces[p];
      int j = 0;
      while (j < piece.size()) {
        if (arr[i] != piece[j]) return false;
        i++;
        j++;
      }
    }

    return true;
  }
};

int main() {
  vector<int> arr{91, 4, 64, 78};
  vector<vector<int>> pieces{{78}, {4, 64}, {91}};
  Solution soln;
  // Should output true i.e "1"
  cout << soln.canFormArray(arr, pieces) << '\n';
}