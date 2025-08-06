#include <cctype>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

      auto index = [](char letter) -> int{
        return islower(letter)? letter - 'a' : letter - 'A' + 26; 
      };

      bool isJewel[52] = {false};
      for (char& jewel : jewels) {
        isJewel[index(jewel)] = true;
      }

      int ans = 0;
      for (char& stone : stones) {
        if (isJewel[index(stone)]) 
          ans++;
      }

      return ans;
    }
};
