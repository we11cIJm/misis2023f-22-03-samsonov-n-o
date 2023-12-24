#include <iostream>
#include <set>

int main() {
    int t;
    std::cin >> t;
    
    while(t--){
        int n;
        std::cin>>n;
        unsigned long long a[n];
        for(auto& k : a) {
            std::cin >> k;
        }
        for(unsigned long long po = 0; po < 62; ++po) {
            unsigned long long poa = 
                (((unsigned long long)1) << po);
                
            std::set<unsigned long long> rems;
            bool success=true;
            
            for(const auto& k : a) {
                rems.insert(k%poa);
                if(rems.size()>2) {
                    success=false;
                    break;
                }
            }
            if(rems.size()==1) {
                success=false;
            }
            if(success) {
                std::cout << poa << '\n';
                break;
            }
        }
    }
    return 0;
}
