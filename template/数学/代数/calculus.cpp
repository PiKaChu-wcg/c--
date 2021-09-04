//Simpson和Romberg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int debug_num=0;
#define debug cout<<"debug "<<++debug_num<<" :"
const double pi=acos(-1.0);

//f 为被积函数
//a b 为积分上下限
//n为划分份数
//求积分值
inline double f(double x)//被积函数
{
    return sin(x);
}

double simpson(double a,double b,int n){//分成n块再相加 n一般取300 特殊情况特殊考虑
    const double h=(b-a)/n;
    double ans=f(a)+f(b);
    for(int i=1;i<n;i+=2) ans+=4*f(a+i*h);
    for(int i=2;i<n;i+=2) ans+=2*f(a+i*h);
    return ans*h/3;
}

double romberg(double a,double b,double eps=1e-8){//eps为允许误差
    vector<double > t;
    double h=b-a,last,curr;
    int k=1,i=1;
    t.push_back(h*(f(a)+f(b))/2); //梯形
    do{
        last=t.back();
        curr=0;
        double x=a+h/2;
        for(int j=0;j<k;++j){
            curr+=f(x);
            x+=h;
        }
        curr=(t[0]+h*curr)/2;
        double k1=4.0/3.0,k2=1.0/3.0;
        for(int j=0;j<i;j++){
            double temp=k1*curr-k2*t[j];
            t[j]=curr;
            curr=temp;
            k2/=4*k1-k2;
            k1=k2+1;
        }
        t.push_back(curr);
        k*=2;
        h/=2;
        i++;
    }while(fabs(last-curr)>eps);
    return t.back();
}

int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cout<<"simpson:"<<simpson(0,pi,10)<<"  romberg:"<<romberg(0,pi,1e-1)<<endl;
    cout<<"simpson:"<<simpson(0,pi,100)<<"  romberg:"<<romberg(0,pi,1e-4)<<endl;
    cout<<"simpson:"<<simpson(0,pi,200)<<"  romberg:"<<romberg(0,pi,1e-6)<<endl;
    cout<<"simpson:"<<simpson(0,pi,300)<<"  romberg:"<<romberg(0,pi)<<endl;//默认1e-8
    return 0;
}