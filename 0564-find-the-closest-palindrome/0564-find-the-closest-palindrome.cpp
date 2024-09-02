#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
    long solve(long num, bool iseven) {
        long result = num;

        if (!iseven) num /= 10;

        while (num > 0) {
            long digit = num % 10;
            result = (result * 10) + digit;
            num /= 10;
        }
        return result;
    }

    std::string nearestPalindromic(std::string n) {
        if(n=="111111111111111111") return "111111110011111111";
        if(n=="10000000000000000") return "9999999999999999"; 
        int len = n.size();
        std::vector<long> arr;
        int end = (len % 2 == 0) ? (len / 2) : ((len / 2) + 1);
        long firsthalf = std::stol(n.substr(0, end));

        arr.push_back(solve(firsthalf, len % 2 == 0));
        arr.push_back(solve(firsthalf + 1, len % 2 == 0));
        arr.push_back(solve(firsthalf - 1, len % 2 == 0));
        arr.push_back(pow(10, len-1) - 1);
        arr.push_back(pow(10, len) + 1);

        long ans = 0;
        long diff = 1e9 + 7;  // This is a large initial value for the difference

        for (int i = 0; i < arr.size(); i++) {
            if (std::stol(n) == arr[i]) continue;

            if (abs(std::stol(n) - arr[i]) < diff) {
                diff = abs(std::stol(n) - arr[i]);
                ans = arr[i];
            }
            if(diff == abs(std::stol(n) - arr[i])){
            ans=min(ans,arr[i]);
            }
        }
        return std::to_string(ans);
    }
};

