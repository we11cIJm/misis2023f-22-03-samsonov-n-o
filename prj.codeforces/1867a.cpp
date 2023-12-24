#include <iostream>
#include <vector>
#include <algorithm>

bool firstcol(std::vector<int> a, std::vector<int> b) {
    return a[0]>b[0];
}

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n, element;
        std::cin >> n;
        std::vector<std::vector<int>> a;
        for(int i = 0; i<n; ++i) {
            std::cin >> element;
            a.push_back({element, i});
        }

        std::sort(a.begin(), a.end(), firstcol);

        std::vector<std::vector<int>> ans;
        for(int i=0; i<n; ++i) {
            ans.push_back({a[i][1], i+1});
        }
        std::sort(ans.begin(), ans.end(), firstcol);

        for(int i=n-1 ; i>-1 ; i--) {
            std::cout << ans[i][1] << " ";
        }
        std::cout << std::endl;
    }
}
