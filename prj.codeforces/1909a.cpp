#include <iostream>
#include <array>

int main(){
    int t;
    std::cin>>t;
    
    while(t--){
        int n;
        std::cin>>n;
        std::array<int, 4> arr = {0, 0, 0, 0};
        for(int i=0; i < n; ++i){
            int x, y;
            std::cin >> x >> y;
            if(x<0) {
                arr[0]++;
            }
            if(y<0) {
                arr[1]++;
            }
            if(x>0) {
                arr[2]++;
            } if(y>0) {
                arr[3]++;
            }
        }
        int k=0;
        for(int i = 0; i < 4; ++i) {
            if(arr[i]!=0){
                k++;
            }
        }
        if(k<4)  {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
}
