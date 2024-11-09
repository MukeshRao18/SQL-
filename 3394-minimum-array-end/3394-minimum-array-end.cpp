class Solution {
public:
    long long minEnd(int n, int x) {
        if (n == 1) {
            return x;
        }
        long long temp = x + 1; 
        long long result = 0;
        n--; 

        while (n > 0) {
            if ((x & temp) == x) {
                n--; 
                result = temp; 
            }
            temp=x|temp+1; 
        }
        return result;
    }
};
