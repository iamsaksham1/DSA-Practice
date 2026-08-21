class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto gcd = [](long long a, long long b) {
            while (b) {
                long long temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        };

        auto lcm = [&](long long a, long long b) {
            return a / gcd(a, b) * b;
        };

        // Count how many valid amounts are <= x
        auto count = [&](long long x) {
            long long total = 0;

            for (int mask = 1; mask < (1 << n); mask++) {

                long long common = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        common = lcm(common, coins[i]);

                        if (common > x) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid)
                    continue;

                if (bits % 2 == 1)
                    total += x / common;
                else
                    total -= x / common;
            }

            return total;
        };

        // The answer cannot be larger than k * smallest coin
        long long left = 1;
        long long right = 1LL * k * (*min_element(coins.begin(),
                                                   coins.end()));

        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (count(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};