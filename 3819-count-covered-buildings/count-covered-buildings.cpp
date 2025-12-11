class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rows;
    unordered_map<int, vector<int>> cols;
    
    for (const auto& b : buildings) {
        int x = b[0], y = b[1];
        rows[y].push_back(x);
        cols[x].push_back(y);
    }
    
    for (auto& [y, i] : rows) {
        sort(i.begin(), i.end());
    }
    for (auto& [x, j] : cols) {
        sort(j.begin(), j.end());
    }
    
    int count = 0;
    for (const auto& b : buildings) {
        int x = b[0], y = b[1];
        
        const vector<int>& rowi = rows[y];
        auto it_x = lower_bound(rowi.begin(), rowi.end(), x);
        bool has_left = (it_x != rowi.begin());
        bool has_right = (next(it_x) != rowi.end());
        
        const vector<int>& colj= cols[x];
        auto it_y = lower_bound(colj.begin(), colj.end(), y);
        bool has_below = (it_y != colj.begin());
        bool has_above = (next(it_y) != colj.end());
        
        if (has_left && has_right && has_above && has_below) {
            count++;
        }
    }
    
    return count;
    }
};