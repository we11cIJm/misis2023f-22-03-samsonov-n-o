#include <iostream>

int main(){
    int64_t t, a, b, res, res1, res2;
    std::cin >> t;
    while(t--){
        std::cin >> a >> b;
        res1 = std::min(a, b);
        res2 = (a+b)/3;
        res = std::min(res1 , res2);
        std::cout << res << '\n';
    }
}
