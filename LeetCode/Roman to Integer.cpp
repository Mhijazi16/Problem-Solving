#include <iostream>
#include <map> 

using namespace std; 

class Solution {
public:
    int romanToInt(string str) {
        map<char,int> roman = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        int len = str.length();
        int sum = roman[str[len-1]];
        for(int i = len-2; i >= 0 ;i--)
        {
            if(roman[str[i]] >= roman[str[i+1]])
            {sum += roman[str[i]]; continue; }
            
            sum -= roman[str[i]];
        }
        return sum ;
    }
};