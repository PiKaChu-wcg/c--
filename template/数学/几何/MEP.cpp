#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=1e6+5;
/*
dcmp() 判断大小函数
sqr() 平方
point 结构体:点
norm()向量模长
det()叉积
dot()点积
dist()距离
ratote_point()绕原点逆时针旋转A弧度后的点
*/

int dcmp(double x){//判符函数
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}

inline double sqr(double x){//计算一个数的平方
    return x*x;
}

struct point{
    double x,y;
    point() {}
    point (double a,double b):x(a) , y(b) {}
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    friend point operator + (const point &a,const point &b){
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator - (const point &a,const point &b){
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const point &a,const point &b){
        return (dcmp(a.x-b.x)==0)&&(dcmp(a.y-b.y)==0);
    }
    friend point operator * (const point &a,const double &b){
        return point(a.x*b,a.y*b);
    }
    friend point operator * (const double &a,const point &b){
        return point(a*b.x,a*b.y);
    }
    friend point operator / (const point &a,const double &b){
        return point(a.x/b,a.y/b);
    }
    friend bool operator <(const point& a,const point& b){
        return a.x<b.x||(a.x==b.x&&a.y<b.y);//在有精度需求，比如使用lower_bound的时候，加上dcmp()
    }
    friend bool operator >(const point& a,const point& b){
        return a.x>b.x||(a.x==b.x&&a.y>b.y);//在有精度需求，比如使用lower_bound的时候，加上dcmp()
    }
    double norm(){//向量模长
        return sqrt(sqr(x)+sqr(y));
    }
};

double det(const point &a,const point &b){//叉积
    return a.x*b.y-a.y*b.x;
}
double det(const point &a,const point &b, const point &c){
    return det(a-c,b-c);
}
double dot(const point &a,const point &b){//点积
    return a.x*b.x+a.y*b.y;
}
double dot(const point &a,const point &b, const point &c){
    return dot(a-c,b-c);
}
double dist(const point &a,const point b={double(0),double(0)}){//距离
    return (a-b).norm();
}

point rotate(const point &p,double A){//绕原点逆时针旋转A弧度后的点
    double tx=p.x,ty=p.y;
    return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}
double angle(point a,point b={double(1),double(0)}){
    return acos(dot(a,b)/a.norm()/b.norm());
}
int qurd(point a){
    if(a.x>0&&a.y>=0)return 1;
    if(a.x<=0&&a.y>0)return 2;
    if(a.x<0&&a.y<=0)return 3;
    return 4;  
}
bool pcmp(point a,point b)
{
    if(qurd(a)!=qurd(b))return qurd(a)<qurd(b);
    return det(a,b)>0;
}

point o;
bool cmp(point &a,point &b){
    if(dcmp(det(a,b,o))==0)
        return (a-o).norm()<(b-o).norm();
    return dcmp(det(a,b,o))>0;
}
double dp[maxn][maxn];
double MEP(point * p,point O,int n){
    sort(p,p+n,cmp);
    memset(dp,0,sizeof(dp));
    double ans=0;
    for (int i = 0; i < n; i++)
    {
        int j=i-1;
        while(j>=0&&dcmp(det(p[i],p[j],O))==0)j--;    
        bool flag=(i==j+1);
        while(j>=0){
            int k=j-1;
            while(k>=0&&dcmp(det(p[i],p[k],O))>0)k--;
            double area=abs(det(p[i],p[j]))/2.0;
            if(k>=0)area+=dp[j][k];
            if (flag)dp[i][j]=area;
            ans=max(ans,area);
            j=k;
        }
        if(flag)for (int j = 1; j < i; j++)
        {
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
    return ans;
}
