#define _CRT_SECURE_NO_WARNINGS
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define rep1(i,n)	for(int (i)=1;(i)<=(n);(i)++)
#define rep0(i,n)	for(int (i)=0;(i)<n;(i)++)
#define rep(i,s,t) for(int i=(s);i<=(t);i++)
#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<functional>
#include<queue>
#include<stack> 
#include<iomanip>
#include<vector>
#include<set>
#define PI acos(-1)
#define VI vector<ll> 
#define PII pair<int,int>
#define SI set<int>
#define INF 0x3f3f3f3f33f3ff3f
#define ll long long
#define mem(x,y) memset((x),(y),sizeof(x))
using namespace std;


const int maxn=550;
int n,m;
template <typename T>inline void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
//这里开始写自己的东西
const double eps=1e-6;
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	if(x>0)return 1;
	return -1;
}
struct point{
	double x,y;
	point(){};
	point(double x,double y):x(x),y(y){};
	point operator -(const point& o){return point(x-o.x,y-o.y);}
	point operator +(const point& o){return point(x+o.x,y+o.y);}
	point operator *(const double& o)const{return point(x*o,y*o);}
	double operator *(const point& o)const{return x*o.y-y*o.x;}
}p[maxn],o,poly[maxn];
double det(const point& a,const point &b){
	return a*b;
}
struct line{
	point p,v;
	double ang()const{return atan2(v.x,v.y);}
	line(){};
	line(point p,point v):p(p),v(v){};
	friend double operator < (line & l1,line & l2)
	{
		if((l1.p-o)*l1.v<0)  
		l1.v=point(0,0)-l1.v;
		if((l2.p-o)*l2.v<0)
		l2.v=point(0,0)-l2.v;
		return l1.ang()<l2.ang();
	}
	int in_one_side(const point & t){return dcmp(det(v,p-o)*det(v,p-t));}
}l[550],q[maxn];
point GetIntersection(line l1,line l2){
	double s1=(l1.p-l2.p)*l2.v;
	double s2=l1.v*l2.v;
	return l1.p-l1.v*(s1/s2);
}
int plane(point *poly){
	int first,last; 
	q[first=last=0]=l[0];
	for (int i = 1; i < n+4; i++)
	{
		while(first<last&&l[i].in_one_side(p[last-1])==-1)last--;
		while(first<last&&l[i].in_one_side(p[first])==-1)first++;
		q[++last]=l[i];
		if(dcmp(q[last].v*q[last-1].v)==0){
            if(q[last-1].in_one_side(l[i].p)==1&&q[last].in_one_side(q[last-1].p)==-1)q[--last]=l[i];
        }
		if(first<last)p[last-1]=GetIntersection(q[last-1],q[last]);
	}
	while(first<last&&q[first].in_one_side(p[last-1])==-1)last--;
	if(last-first<=1)return 0;
	p[last]=GetIntersection(q[last],q[first]);
	int m=0;
    for(int i=first;i<=last;i++)poly[m++]=p[i];
    return m;
}
double area(int m, point *poly){
	double res=0;
	for(int i;i<m;i++){
		res+=fabs((poly[i]-o)*(poly[(i+1)%m]-o));
	}
	return res/2;
}
void solve(){
	double L;
	cin>>n>>m>>L;
	double a,b,c;
	point q,v;
	q=point(L,L);
	v=point(1,0);
	l[0]=line(q,v);
	v=point(0,1);
	l[1]=line(q,v);
	q=point(-L,-L);
	l[2]=line(q,v);
	v=point(1,0);
	l[3]=line(q,v);
	for (int i = 4; i < n+4; i++)
	{
		cin>>a>>b>>c;
		if(a==0)q=point(0,-b/c);
		else q=point(-c/a,0);
		v=point(b,-a);
		l[i]=line(q,v);
	}
	int k;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		o=point(x,y);
		sort(l,l+n+4);
		k=plane(poly);
		printf("%.2f\n",area(k,poly));
	}
}
int main(){
	int T;
	// cin>>T;
	T=1;
	while(T--){
		solve();
	}
}
/*
2 4 3
1 1 -1
-1 1 -1
0 2
-2 1
2 1
0 0
*/