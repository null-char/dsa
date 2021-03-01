// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> heap;

    for (auto x : nums) {
      heap.push(x);
    }

    for (int i = 1; i < k; i++) {
      heap.pop();
    }

    return heap.top();
  }
};

int main() {}