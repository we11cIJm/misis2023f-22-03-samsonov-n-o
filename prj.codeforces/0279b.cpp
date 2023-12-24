#include <iostream>
#include <vector>

int main() {
    int n, t;
    std::cin >> n >> t;
    std::vector<int> a(n);
    for (int& k : a) {
        std::cin >> k;
    }
    int r = 0;
    int sm = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (r < n && sm + a[r] <= t) {
            sm += a[r];
            ++r;
        }
        ans = std::max(ans, r - i);
        sm -= a[i];
    }
    std::cout << ans << '\n';

}
