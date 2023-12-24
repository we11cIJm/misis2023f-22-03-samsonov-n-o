#include <iostream>
#include <string>

int main(){
    int t;
    std::cin>>t;
    while(t--){
        std::string s;
        std::cin >> s;
        int a=s[0]-'0', b=0, c = s.size();
        for(int i = 1; i < c; ++i) {
            if(s[i] != '0' || b > 0) {
                b = b * 10 + (s[i] - '0');
            } else {
                a *= 10;
            }
        }
        if(a<b) {
            std::cout << a << " " << b<< '\n';
        } else {
            std::cout << -1 << '\n';
        }
    }
    
}

