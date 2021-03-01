// Link: https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> res;
    unordered_map<int, int> freq;

    // Build hashmap
    for (auto x : nums) {
      auto count = freq.find(x);
      if (count == freq.end()) {
        freq[x] = 1;
      } else {
        freq[x] = count->second + 1;
      }
    }

    auto compare = [&](int a, int b) { return freq[a] > freq[b]; };
    // Maintain a heap with the k most frequent elements
    priority_queue<int, vector<int>, decltype(compare)> heap(compare);

    // Build heap. O(n.logk) time.
    for (auto kv : freq) {
      heap.push(kv.first);
      // Pop element off the heap if size exceeds k
      if (heap.size() > k) heap.pop();
    }

    // Finally, build results array. O(k.logk) time.
    for (int i = 0; i < k; i++) {
      res.push_back(heap.top());
      heap.pop();
    }

    return res;
  }
};

int main() {
  vector<int> nums{4, 1, -1, 2, -1, 2, 3};
  int k = 2;
  Solution soln;
  auto res = soln.topKFrequent(nums, k);

  for (auto x : res) {
    cout << x << ' ';
  }
}