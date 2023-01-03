#include <iostream>
#include <vector>
#include <map> 
#include <algorithm> 

using namespace std; 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result; 
       map<string ,int > hash_table; 
       int x = 0 ; 
        int n = strs.size(); 
       for (int i = 0; i < n; i++)
       {    
            string str = strs[i]; 
            sort(str.begin(), str.end());
            if(hash_table.find(str) != hash_table.end())
                result[hash_table[str]].push_back(strs[i]); 
            else 
               { hash_table[str] = x++ ; 
                result.push_back(vector<string> (1, strs[i])); 
               }
        }
            
            return result; 
        
    }
};