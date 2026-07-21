class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        vector<int> ans;

        for (auto i : nums)
        {
            minHeap.push(i);
        }

        while(minHeap.size() > 0)
        {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        return ans;
    }
};