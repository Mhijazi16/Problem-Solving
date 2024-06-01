#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> sortArrayByParity(vector<int> nums) {
  partition(nums.begin(),nums.end(),[](const int& x){return (x&1) == 0;});
  return nums;
}

