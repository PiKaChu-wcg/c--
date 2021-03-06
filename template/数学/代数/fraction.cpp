#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

struct Fraction{
    ll num;
    ll den;
    Fraction (ll num=0,ll den=1){
        if(den<0){
            num=-num;
            den=-den;
        }
        assert(den != 0);
        ll g=gcd(abs(num),den);
        this->num=num/g;
        this->den=den/g;
    }
    Fraction operator + (const Fraction &o) const{
        return Fraction(num*o.den+den*o.num,den*o.den);
    }
    Fraction operator - (const Fraction &o) const{
        return Fraction(num*o.den-den*o.num,den*o.den);
    }
    Fraction operator * (const Fraction &o) const{
        return Fraction(num*o.num,den*o.den);
    }
    Fraction operator / (const Fraction &o) const{
        return Fraction(num*o.den,den*o.num);
    }
    bool operator < (const Fraction &o) const{
        return num*o.den<den*o.num;
    }
    bool operator == (const Fraction &o) const{
        return num*o.den==den*o.num;
    }
};

int main()
{
    Fraction f1(33455,-3243235);
    Fraction f2(3533245,345323);
    cout<<f1.num<<"/"<<f1.den<<endl;
    cout<<f2.num<<"/"<<f2.den<<endl;
    Fraction f3=f2-f1;
    cout<<f3.num<<"/"<<f3.den<<endl;
    return 0;
}
