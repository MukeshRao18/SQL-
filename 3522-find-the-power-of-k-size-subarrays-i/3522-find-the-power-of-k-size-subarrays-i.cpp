#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> resultsArray(std::vector<int>& nums, int k) {
        int l = 0, r = 0;
        std::vector<int> ans;
        std::deque<int> q;

        while (r < nums.size()) {
            while (!q.empty() && nums[r]-nums[q.back()] !=1 ) {
                q.pop_back();
            }
            q.push_back(r);

            if (l > q.front()) {
                q.pop_front();
            }

            if (r + 1 >= k) {
                if(q.size()==k)
            ans.push_back(nums[q.back()]);
                else ans.push_back(-1);
                l++;
            }
            r++;
        }
        return ans;
    }
};
