#include <string>
#include <iostream>

using namespace std;

string apply_operation(string a){
  string h; 
  for (auto& x : a) {
    if (x == '#' && !h.empty()) 
      h.pop_back();
    else if(x != '#')
      h += x;
  }
  return h;
}

bool backspaceCompare(string s, string t) {
  return apply_operation(s) == apply_operation(t);
}
