class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        
        // Generate a list of all prime numbers up to maxElement using the sieve method
        vector<bool> sieve(maxElement + 1, true);
        sieve[0] = sieve[1] = false;  // 0 and 1 are not primes
        for (int i = 2; i * i <= maxElement; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= maxElement; j += i) {
                    sieve[j] = false;
                }
            }
        }
        
        // Collect prime numbers in an array
        vector<int> primes;
        for (int i = 2; i <= maxElement; ++i) {
            if (sieve[i]) {
                primes.push_back(i);
            }
        }
        
        int n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            // Iterate through precomputed primes in reverse
            for (int p : primes) {
                if (p >= nums[i]) break;  // Stop if the prime is greater than or equal to the current number
                if (nums[i] - p < nums[i + 1]) {
                    nums[i] -= p;
                    break;
                }
            }
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
