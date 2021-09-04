#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> T gcd(T a,T b)
{
    return b==0? a:gcd(b,a%b);
}
template<typename T> T e_gcd(T a,T b,T &x,T &y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    T ans=e_gcd(b,a%b,x,y);
    T temp=x;
    x=y;
    y=temp-a/b*y;
    return ans;
}