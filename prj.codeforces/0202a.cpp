#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include <array>

int main(){
    std::string a;
    std::cin >> a;
    size_t len, i, j;
    std::array<int, 27> al;
    len = a.size();
    for(i = 1; i <= 26; ++i){
        al[i] = 0;
    }
    for(i = 0; i < len; ++i){
        ++al[int(a[i])-96];
    }
    for(i = 26; i >= 1; --i){
        if(al[i] > 0){
            for(j = 0; j < al[i]; ++j){
                std::cout << char(96+i);
            }
            break;
        }
    }

}
