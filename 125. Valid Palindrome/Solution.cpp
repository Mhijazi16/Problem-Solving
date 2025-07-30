#include <functional>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {

      bool tolerate = true;

      function<bool(string, int, int)> isPlaindrome;
      isPlaindrome = [&](string str, int left, int right) -> bool{ 
        while (left <= right) {
          if (str[left] == str[right]) {
            left++;
            right--;
            continue;
          }

          if (!tolerate) {
            return false;
          }

          tolerate = false;
          return isPlaindrome(str, left, right-1) || isPlaindrome(str, left+1, right);
        }

        return true;
      };

      return isPlaindrome(s, 0, s.length()-1);
    }
};
