#include <functional>
#include <iostream>
#include <string>

using namespace std;

bool skip = true;
bool validPalindrome(string s) {
  int i = 0, j = s.length()-1 ;

  while (i < j) {
    if (s[i] != s[j])
    {
      if (!skip) 
        return false;

      skip = false;
      return validPalindrome(s.substr(i+1,j-i)) || 
             validPalindrome(s.substr(i,j-i));
    }
    i++;
    j--;
  }

  return true;
}

int main(){

  cout << validPalindrome("abc");
  return 0;
}
