#include <vector>

using namespace std; 

void moveZeroes(vector<int>& nums) {
  int x = 0;
  auto it = nums.begin();
  for (; it != nums.end(); ) {
    if(*it == 0)
    {
      nums.erase(it);
      x++;
      continue;
    }
    it++;
  }
  while (x--)
    nums.push_back(0);
}
