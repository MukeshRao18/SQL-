#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;  // Edge case: if the tree is empty
        
        vector<long long> arr; // To store level sums
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;
            
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                if (curr != nullptr) {
                    sum += curr->val;  // Add current node value to sum
                    
                    // Push left and right children into the queue if they are not null
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                }
            }
            // Add sum of the current level to the array if the level had valid nodes
            arr.push_back(sum);
        }
        
        // Sort the sums in descending order
        sort(arr.begin(), arr.end(), greater<long long>());
        
        // Handle case where k is larger than the number of levels
        if (k > arr.size()) return -1;
        
        return arr[k - 1]; // Return the k-th largest sum
    }
};
