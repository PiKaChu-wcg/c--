#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long n,k,ans;
int main(){
    cin>>n>>k;
    ans=0;
    for (int x = 0,gx; x <=n;x=gx+1){
        gx=(n/(n/x));
    }   
}