class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {

        vector<int> ans;

        for (int size = arr.size(); size > 1; size--) {

            int idx =
                max_element(arr.begin(), arr.begin() + size) - arr.begin();

            // Already in correct position
            if (idx == size - 1)
                continue;

            // Flip only if not already at front
            if (idx != 0) {
                reverse(arr.begin(), arr.begin() + idx + 1);
                ans.push_back(idx + 1);
            }

            reverse(arr.begin(), arr.begin() + size);
            ans.push_back(size);
        }

        return ans;
    }
};