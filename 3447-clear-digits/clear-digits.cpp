class Solution {
public:
    string clearDigits(string s) {
           int i = 0;
    
    while (true) {
        bool operationPerformed = false;
        i = 0;

        while (i < s.length()) {
            if (isdigit(s[i])) {
                int j = i - 1;
                while (j >= 0 && isdigit(s[j])) {
                    j--;  
                }

                if (j >= 0) {
                    s.erase(j, 1); 
                    s.erase(i - 1, 1);
                    operationPerformed = true;
                }

                break;
            }
            i++;
        }
        if (!operationPerformed) break;
    }

    return s;
    }
};