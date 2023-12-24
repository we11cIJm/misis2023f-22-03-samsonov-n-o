#include<iostream>

int main() {
    char c[100000];
    int n, a = 0, b = 0;
    std::cin>>n;
    for (int i=0;i<n;i++) {
        std::cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        if(c[i] == 'A') {
            a++;
        } else {
            b++;
        }
    }
    if(a>b) {
        std::cout<<"Anton";
    }
    else if(b > a) {
        std::cout << "Danik";
    }
    else if(b == a) {
        std::cout<<"Friendship";
    }

}
