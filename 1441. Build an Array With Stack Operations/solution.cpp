#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        int shift = 0, index = 0;
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            if (i - 1 == target[target.size() - 1]) {
                return ans;
            }

            if (target[index] == i) {
                while (shift) {
                    ans.push_back("Pop");
                    shift--;
                }

                index++;
            } else
                shift++;

            ans.push_back("Push");
        }

        return ans;
    }
};
