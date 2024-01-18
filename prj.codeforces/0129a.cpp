#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    //int a[n] = {0};
    std::vector<int> a(n);
    int odd =0;
    int even = 0;
    int sum =0;
    
    for (int i=0; i<n; ++i) {
        std::cin>>a[i];
        if(a[i]%2 ==0) ++even;
        else {
            ++odd;
        }
        sum += a[i];
    }
    
    if(!(sum % 2)) {
        std::cout << even;
    } else {
        std::cout << odd;
    }
}
