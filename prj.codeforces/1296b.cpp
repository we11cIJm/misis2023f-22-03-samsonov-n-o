#include <iostream>
 
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int s;
        std::cin >> s;
        int ans = 0;
        int pw = 1000 * 1000 * 1000;
        while (s > 0) {
            while (s < pw) {
                pw /= 10;
            }
            ans += pw;
            s -= pw - pw / 10;
        }
        std::cout << ans << '\n';
  }
}
