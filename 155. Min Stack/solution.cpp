#include <algorithm>
#include <vector>


using namespace std;

class MinStack {
public:
    vector<int> stack; 
    vector<int> mini;

    MinStack() {
    }
    
    void push(int val) {
        stack.push_back(val);
        if (mini.empty()) {
            mini.push_back(val);
        } else {
            mini.push_back(min(val, mini.back()));
        }
    }
    
    void pop() {
      if (stack.back() == mini.back()) {
        mini.pop_back();
      }
      stack.pop_back();
    }
    
    int top() {
      return stack.back();
    }
    
    int getMin() {
      return mini.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
