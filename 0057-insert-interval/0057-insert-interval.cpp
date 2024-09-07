class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        vector<vector<int>> answer;
        int a1 = newInterval[0], b1 = newInterval[1];

        for (int i = 0; i < intervals.size(); ++i) {
            int a2 = intervals[i][0], b2 = intervals[i][1];

            if (a2 > b1) {
                answer.push_back({a1, b1});
                a1 = a2, b1 = b2;
            } else if (a1 > b2) { 
                answer.push_back({a2, b2});
            } else {
                int a = min(a1, a2), b = max(b1, b2);
                a1 = a, b1 = b;
            }
        }

        answer.push_back({a1, b1});

        return answer;
    }
};