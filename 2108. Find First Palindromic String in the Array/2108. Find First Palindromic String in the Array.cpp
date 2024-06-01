#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

bool isPlaindrome(string& s){
  string b = s; 
  reverse(s.begin(),s.end());
  return b == s;
}

string firstPalindrome(vector<string>& words) {
  for (auto& x : words) {
    if(isPlaindrome(x))
      return x;
  }

  return "";
}
