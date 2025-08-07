#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(char& letter : s){
            if(isupper(letter))
                letter = tolower(letter); 
        }

        return s;
    }
};
