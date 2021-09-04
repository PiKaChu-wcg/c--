#include<iosstream>
typedef long long ll;
struct frac
{
    ll p,q;
    frac(){}
    frac(ll _p,ll _q)
    {
        if(_p<0&&_q<0) _p=-_p,_q=-_q;
        else
            if(_q<0) _q=-_q,_p=-_p;
        p=_p/__gcd(abs(_p),abs(_q));
        q=_q/__gcd(abs(_p),abs(_q));
    }
    bool operator < (const frac &x) const
    {
        return p*x.q<q*x.p;
    }
    bool operator <= (const frac &x) const
    {
        return p*x.q<=q*x.p;
    }
    bool operator == (const frac &x) const
    {
        return p==x.p&&q==x.q;
    }
    frac operator + (const frac &x)
    {
        return frac(p*x.q+q*x.p,q*x.q);
    }
    frac operator * (const frac &x)
    {
        return frac(p*x.p,q*x.q);
    }
    frac operator / (const frac &x)
    {
        return frac(p*x.q,q*x.p);
    }
    frac operator - (const frac &x)
    {
        return frac(p*x.q-q*x.p,q*x.q);
    }
    frac operator - ()
    {
        return frac(-p,q);
    }
    friend ostream & operator<<(ostream &os, frac &obj);
};
ostream & operator<<(ostream &os, frac &obj)
{
    os << obj.p << "/" << obj.q;
    return os;
}