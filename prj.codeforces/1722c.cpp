#include<iostream>
#include <string>
#include<bits/stdc++.h>
#include <algorithm>

long long read(){
    long long x=0, sgn=1;
    char ch = getchar();
    while (ch<'0' || ch>'9') {
        if(ch=='-') {
            sgn=-1;ch=getchar();
        }        
    }
    while (ch>='0' && ch<='9') {
        x= (x<<3) + (x<<1) + (ch & 15);
        ch=getchar();
    }
    return x * sgn;
}

void write(long long n, bool p) {
    if(n<0) {
        putchar('-');
        n=-n;
    }
    if(n==0) {
        if(p) {
            putchar('0');
        }
        return;
    }
    write(n/10,0);
    putchar(n % 10 + '0');
}

long long t,n,ans1,ans2,ans3;
bool p1[20000],p2[20000],p3[20000];
std::string st;

int main(){
    std::cin>>t;
    while(t--){
        ans1=0;
        ans2=0;
        ans3=0;
        memset(p1,0,sizeof(p1));
        memset(p2,0,sizeof(p2));
        memset(p3,0,sizeof(p3));
        std::cin>>n;
        for(int i=1;i<=n;i++){
            std::cin>>st;
            p1[(st[0]-'a')*26*26+(st[1]-'a')*26+st[2]-'a']=true; 
        }
        for(int i=1;i<=n;i++){
            std::cin>>st;
            p2[(st[0]-'a')*26*26+(st[1]-'a')*26+st[2]-'a']=true; 
        }
        for(int i=1;i<=n;i++){
            std::cin>>st;
            p3[(st[0]-'a')*26*26+(st[1]-'a')*26+st[2]-'a']=true; 
        }
        for(int i=0;i<=17576;i++){
            if(p1[i] && p2[i] && p3[i]) continue;
            if(p1[i] && p2[i]){
                ans1++;
                ans2++;
                continue;
            }
            if(p1[i] && p3[i]){
                ans1++;
                ans3++;
                continue;
            }
            if(p2[i] && p3[i]){
                ans2++;
                ans3++;
                continue;
            }
            if(p1[i]) ans1+=3;
            if(p2[i]) ans2+=3;
            if(p3[i]) ans3+=3;
        }
        std::cout << ans1 << " " << ans2 << " " << ans3 << std::endl;
    }
    return 0;
}
