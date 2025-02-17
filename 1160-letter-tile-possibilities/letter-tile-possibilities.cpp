class Solution {
public:
    int backtrack(unordered_map<char, int>& freq) {
        int count = 0;
        for (auto& [ch, val] : freq) {
            if (val > 0) {
                freq[ch]--;
                count += 1 + backtrack(freq); 
                freq[ch]++;
            }
        }
        return count;
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles)
            freq[ch]++; 
        return backtrack(freq);
    }
};