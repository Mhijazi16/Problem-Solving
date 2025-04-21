#include <algorithm>
#include <cctype>
#include <ios>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {

    int left = 0, right = s.length();
    while (left < right) {

      s[left] = tolower(s[left]);
      s[right] = tolower(s[right]);

      while (left < right && s[left] < 'a' || s[left] > 'z') {
        left++;
      }

      while (left < right && s[right] < 'a' || s[right] > 'z') {
        right--;
      }

      if (s[left] != s[right]) {
        return false;
      }

      left++;
      right--;
    }

    return true;
  }
};
