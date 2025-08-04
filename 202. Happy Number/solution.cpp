


#include <cmath>
#include <set>
using namespace std;


class Solution {
public:
  set<int> seen;
  int computeSum(int n){
    int sum = 0;
    while (n) {
      sum += pow(n%10,2); 
      n /= 10;
    }

    return sum;
  };
  
  bool isHappy(int n) {
    if (n == 1) {
      return true;
    }

    if (n <= 3 || seen.count(n)) {
      return false;
    }

    seen.insert(n);
    int sum = computeSum(n);
    return isHappy(sum);
  }
};
