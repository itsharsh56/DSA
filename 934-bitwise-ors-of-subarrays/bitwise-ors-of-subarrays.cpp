class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> cur, next;

        for (int a : arr) {
            next.clear();
            next.insert(a);
            for (int val : cur) {
                next.insert(a | val);
            }
            cur = next;
            result.insert(cur.begin(), cur.end());
        }

        return result.size();
    }
};