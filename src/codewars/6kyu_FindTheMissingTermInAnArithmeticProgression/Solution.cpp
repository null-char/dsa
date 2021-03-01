// Link: https://www.codewars.com/kata/52de553ebb55d1fca3000371/train/cpp

#include <bits/stdc++.h>
using namespace std;

static long findMissing(vector<long> list) {
  size_t n = list.size() + 1;
  long a = list.front();
  long l = list.back();
  long long expected = (a + l) * n;
  long long actual = accumulate(list.begin(), list.end(), 0ll);

  return (expected - 2 * actual) / 2;
}

int main() { cout << findMissing({1, 3, 5, 9, 11}); }