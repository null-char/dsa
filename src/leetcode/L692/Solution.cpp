// Link: https://leetcode.com/problems/top-k-frequent-words/

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

class Solution {
 public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> freq;
    vector<string> res(k);
    auto compare = [&](const string &a, const string &b) {
      // Alphabetical order if freq[a] == freq[b]
      if (freq[a] == freq[b]) return a.compare(b) == -1 ? false : true;
      return freq[a] < freq[b];
    };
    priority_queue<string, vector<string>, decltype(compare)> heap(compare);

    for (string s : words) {
      auto count = freq.find(s);
      if (count == freq.end()) {
        freq[s] = 1;
      } else {
        freq[s] = count->second + 1;
      }
    }

    for (auto kv : freq) {
      heap.push(kv.first);
    }

    for (int i = 0; i < k; i++) {
      res[i] = heap.top();
      heap.pop();
    }

    return res;
  }
};

TEST_CASE("It returns the top K frequent words", "[topKFrequent]") {
  Solution s;

  vector<string> words1 = {"the", "day", "is",    "sunny", "the",
                           "the", "the", "sunny", "is",    "is"};
  vector<string> r1 = {"the", "is", "sunny", "day"};
  REQUIRE(s.topKFrequent(words1, 4) == r1);

  vector<string> words2 = {"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> r2 = {"i", "love"};
  REQUIRE(s.topKFrequent(words2, 2) == r2);

  vector<string> words3 = {"aaa", "aa", "a"};
  vector<string> r3 = {"a"};
  REQUIRE(s.topKFrequent(words3, 1) == r3);
}