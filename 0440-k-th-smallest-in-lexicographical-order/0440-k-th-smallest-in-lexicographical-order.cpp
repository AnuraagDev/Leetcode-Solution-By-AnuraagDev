class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        --k;
        
        while (k > 0) {
            long long step = countSteps(n, curr, curr + 1);
            if (step <= k) {
                curr++;
                k -= step;
            } else {
                curr *= 10;
                --k;
            }
        }
        return curr;
    }

    long long countSteps(int n, long long curr, long long next) {
        long long steps = 0;
        while (curr <= n) {
            steps += min(n + 1LL, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};
