#include <iostream>

int main() {
    int tc;
    std::cin >> tc ;
    while(tc--){
        int n ;
        std::cin >> n ;
        
        int a[n];
        int ei = 0, oi =0, ee = 0, oe = 0;
        int nm = 0;
        
        for(int i = 0 ; i < n ; ++i){
            std::cin >> a[i];
            
            if(i%2 == 0) {
                ei++;
            }
            else{
                oi++;
            }            
            if(a[i]%2 == 0) {
                ee++;
            }
            else {
                oe++;
            }
           if(i%2 != a[i]%2) {
                nm++;
           }
        }
        
        if(ei != ee || oi != oe){
            std::cout << -1 << std::endl ;
            continue;
        }
        
        std::cout << nm/2 << std::endl;
    }
}

