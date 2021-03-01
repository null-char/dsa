// Link: https://www.codewars.com/kata/5266876b8f4bf2da9b000362/train/cpp

#include <bits/stdc++.h>
using namespace std;

string likes(const vector<string> &names) {
  stringstream ss;

  switch (names.size()) {
    case 0:
      ss << "no one likes this";
      break;
    case 1:
      ss << names.at(0) << " likes this";
      break;
    case 2:
      ss << names.at(0) << " and " << names.at(1) << " like this";
      break;
    case 3:
      ss << names.at(0) << ", " << names.at(1) << " and " << names.at(2)
         << " like this";
      break;
    default:
      ss << names.at(0) << ", " << names.at(1) << " and " << names.size() - 2
         << " others like this";
      break;
  }

  return ss.str();  // Do your magic!
}