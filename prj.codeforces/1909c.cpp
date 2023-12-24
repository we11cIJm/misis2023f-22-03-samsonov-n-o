#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    long long t;
    std::cin>>t;
    while(t--){
        long long n;
        std::cin>>n;
        std::vector<long long> l;
        for(long long i=0; i<n; ++i){
            long long a;
            std::cin>>a;
            l.push_back(a);
        }
        std::vector<long long> r;
        for(long long i=0; i<n; ++i){
            long long a;
            std::cin>>a;
            r.push_back(a);
        }
        std::vector<long long> c;
        for(long long i=0; i<n; ++i){
            long long a;
            std::cin>>a;
            c.push_back(a);
        }
        std::vector<std::pair<long long, char>> v;
        for(auto it : l){
            v.push_back({it,'l'});
        }
        for(auto it : r){
            v.push_back({it,'r'});
        }
        std::sort(v.begin(), v.end());

        std::vector<long long> diff;
        std::stack<long long> st;
        for(auto it : v){
            if(it.second=='l'){
                st.push(it.first);
            } else {
                diff.push_back(it.first - st.top());
                st.pop();
            }
        }

        
        std::sort(diff.begin(), diff.end());
        std::sort(c.begin(), c.end(), std::greater<long long>());
        long long ans=0;
        for(long long i=0; i<n; ++i) {
            ans += c[i]*diff[i];
        }
        std::cout<< ans << std::endl;
    }
    return 0;
}

