class Solution {
public:
    string smallestNumber(string pattern) {
      stack<int> stk;
    string result;
    int num = 1;  

    for (int i = 0; i <= pattern.size(); i++) {
        stk.push(num++);  
        if (i == pattern.size() || pattern[i] == 'I') {
            while (!stk.empty()) {
                result += to_string(stk.top());
                stk.pop();
            }
        }
    }
    
    return result;
  
    }
};