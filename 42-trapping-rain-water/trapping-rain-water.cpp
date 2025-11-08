class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int curr[n];
        curr[0] = -1;
        int max = height[0];

        // prev greatest element

        for (int i = 1; i < n; i++) {
            curr[i] = max;
            if (max < height[i]) {
                max = height[i];
            }
        }

        curr[n - 1] = -1;
        max = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (max < curr[i]) {
                curr[i] = max;
            }
            if (max < height[i]) {
                max = height[i];
            }
        }

        //fill water
        int water = 0;
        for(int i = 1; i< n - 1;i++)
        {
            if(height[i] < curr[i])
            {
                water += (curr[i] - height[i]);
            }
        }

        return water;
    }
};