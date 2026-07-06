class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while(left <= right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else if (s[left] > s[right])
            {
                s[left] = s[right];
            }
            else {
                s[right] = s[left];
            }
        }
        return s;
    }
};