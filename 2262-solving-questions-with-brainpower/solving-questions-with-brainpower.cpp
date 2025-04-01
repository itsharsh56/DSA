class Solution {
public:
    long long findMaxPoints(vector<vector<int>>& questions, int pos,
                            vector<long long>& mem) {
        if (pos >= questions.size())
            return 0;
        if (mem[pos] != -1)
            return mem[pos];

        long long exclude = findMaxPoints(questions, pos + 1, mem);
        long long include =
            questions[pos][0] +
            findMaxPoints(questions, pos + questions[pos][1] + 1, mem);
        return mem[pos] = max(exclude, include);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> mem(n, -1);
        return findMaxPoints(questions, 0, mem);
    }
};