// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
 public:
  KthLargest(int _k, vector<int> &_nums) : k(_k), nums(_nums) {
    for (auto x : _nums) {
      add(x);
    }
  }

  int add(int val) {
    if (heap.size() < k) {
      heap.push(val);
    } else if (heap.top() < val) {
      heap.pop();
      heap.push(val);
    }

    return heap.top();
  }

 private:
  int k;
  vector<int> &nums;
  priority_queue<int, vector<int>, greater<int>> heap{greater<int>()};
};