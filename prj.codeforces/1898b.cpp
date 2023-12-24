#include <iostream>
#include <vector>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            std::cin >> nums[i];
        }

        long long int ans = 0;
        int m = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            int x = (nums[i] + m - 1) / m;
            ans += x - 1;
            m = nums[i] / x;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}

