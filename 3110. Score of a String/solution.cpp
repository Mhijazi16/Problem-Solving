#include <cmath>
#include <string>

using namespace std;

int scoreOfString(string s) {
  int j = 1,res = 0; 
  for (int i = 0; j < s.length(); i++) {
    res += abs(int(s[i])- int(s[j]));  
    j++;
  }

  return res;
}
