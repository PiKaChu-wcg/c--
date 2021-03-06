//TIMUS1503  模板题
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int debug_num=0;
#define debug cout<<"debug "<<++debug_num<<" :"

const double eps=1e-12;
const double inf=1e12;

inline int sign(double x){
    return x<-eps ? -1 : x>eps ;
}

//coef 系数  coef[i]=a[i]
inline double get(const vector<double> &coef,double x){//将x带入方程的值
    double e=1,s=0;//e=x^i (i=0,1,2,...,n)   coef.size():n+1
    for(int i=0;i<coef.size();++i) s+=coef[i]*e,e*=x;
    return s;
}

double Find(const vector <double> &coef,int n,double lo,double hi){
    double sign_lo,sign_hi;
    if((sign_lo=sign(get(coef,lo)))==0) return lo;//lo就是零点
    if((sign_hi=sign(get(coef,hi)))==0) return hi;//hi就是零点
    if(sign_hi*sign_lo>0) return inf;//当前区间没有零点
    for(int step=0;step<100 && hi-lo>eps;++step){//标准二分
        double m=(lo+hi)*.5;
        int sign_mid=sign(get(coef,m));
        if(sign_mid==0) return m;
        if(sign_lo*sign_mid<0) hi=m;
        else lo=m;
    }
    return (lo+hi)*.5;
}

vector<double> solve(vector<double> coef,int n){
    vector<double> ret;
    if(n==1){
        if(sign(coef[1])) ret.push_back(-coef[0]/coef[1]);
        return ret;//直接求解
    }
    vector<double> dcoef(n);//求导 大小只有n(原函数是n+1)
    for(int i=0;i<n;++i) dcoef[i]=coef[i+1]*(i+1);
    vector<double> droot=solve(dcoef,n-1);
    droot.insert(droot.begin(),-inf);
    droot.push_back(inf);//开头结尾插上-inf 和inf 方便二分  关键（和最高次系数的正负有关？）
    for(int i=0;i+1<droot.size();++i){
        double tmp=Find(coef,n,droot[i],droot[i+1]);
        if(fabs(tmp)<inf) ret.push_back(tmp);//是有效根
    }
    return ret;
}

vector <double > ans;

vector <double > coef;

int main()
{
    //freopen("in.txt","r",stdin);
    //ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    ans.clear();
    coef.clear();
    for(int i=0;i<=n;++i){//n+1个系数
        double tp;
        scanf("%lf",&tp);
        coef.push_back(tp);
    }
    reverse(coef.begin(),coef.end());//注意顺序看要不要逆序   coef[0]放的是x^0对应的系数

    ans=solve(coef,n);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();++i){
        printf("%.6f\n",ans[i]);
    }
    return 0;
}
