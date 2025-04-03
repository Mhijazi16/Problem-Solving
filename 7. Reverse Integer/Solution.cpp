#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int reverse(int x) {

    string b = to_string(x);
    std::reverse(b.end(), b.end());
    long upper_limit = pow(2, 31) - 1;
    long lower_limit = -pow(2, 31);

    string upper = to_string(upper_limit);
    string lower = to_string(lower_limit);
  }
};
