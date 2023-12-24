#include<iostream>
#include <string>

int main() {
    int n;
    std::string word;
    std::cin>>n;
    while(n--) {
        std::cin>>word;
        int Size = word.size();
        if(Size>10) {
            std::cout << word[0] << Size - 2 << word[Size-1];
        }
        else {
            std::cout << word;
        }
        std::cout << std::endl;
    }
    return 0;
}
