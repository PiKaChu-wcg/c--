#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-8;
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
/*
line 结构体:线  a到b的线
point_make_line()两点确定一线
dis_point_line()点到直线的距离
dis_point_segemt()点到线段的距离
PointProjLine()p点到线段st的垂足,保存在cp中
PointOnSegment()判断点p是否在线段st上,包括端点
PointOnLine()
parallel()
line_make_point()两线交点 直线内返回true 线段内返回 false
angle()俩点对原点的夹角 或 一点对x轴的夹角
*/
struct line{
    point a,b;//两点确定一条线段（直线）
    double ang;
    line() {}
    line (point x,point y): a(x),b(y) {ang=atan2(b.x-a.x,b.y-a.y);}
    point prolong(const double &t){
        return t*b-(t-1)*a;
    }
    point v(){
        return b-a;
    }
    bool operator < (const line & l)const{
        return ang<l.ang;
    }
};
bool onleft(const line & l , point p){
    return det(l.b-l.a,p-l.a)>0;
}
line point_make_line(const point a,const point b){
    return line(a,b);
}
double dis_point_line(const point p,const point a,const point b){
    point v1=p-a,v2=a-b;
    return fabs(det(v1,v2)/v2.norm());
}
double dis_point_segment(const point p,const line &l){//p点到线段st的距离
    point t=l.a,s=l.b;
    if(dcmp(dot(p-s,t-s))<0) return (p-s).norm();
    if(dcmp(dot(p-t,s-t))<0) return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));
}
double dis_point_segment(const point p,const point s,const point t){//p点到线段st的距离
    if(dcmp(dot(p-s,t-s))<0) return (p-s).norm();
    if(dcmp(dot(p-t,s-t))<0) return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));
}
double dis_segment_segment(const point &a,const point &b,const point &c,const point &d){
    if (dcmp(det(a,c,d)*det(b,c,d))<=0)return 0;
    return min(dis_point_segment(a,c,d),dis_point_segment(b,c,d));
}
void PointProjLine(const point p,const point s,const point t,point &cp){//p点到线段st的垂足,保存在cp中
    double r=dot(p-s,t-s)/dot(t-s,t-s);
    cp=s+r*(t-s);
}

bool PointOnSegment(point p,point s,point t){//判断点p是否在线段st上,包括端点
    return dcmp(det(p-s,t-s))==0   &&  dcmp(dot(p-s,p-t))<=0 ;
}

bool PointOnLine(point p,line a)
{
    return dcmp(det(p-a.a,p-a.b))==0;
}

bool parallel(line a,line b){//判断a和b是否平行
    return !dcmp(det(a.a-a.b,b.a-b.b));
}

bool line_make_point(line a,line b,point &res){//判断a和b(直线)是否相交 如果相交则保存交点在res中 并返回true
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    res=(s1*a.b-s2*a.a)/(s1-s2);
    if(parallel(a,b)) return false;
    return true;
}
bool line_make_point(point x,point y,point c,point d,point &res){//判断a和b(直线)是否相交 如果相交则保存交点在res中 并返回true
    line a=point_make_line(x,y),b=point_make_line(c,d);
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    res=(s1*a.b-s2*a.a)/(s1-s2);
    if(parallel(a,b)) return false;
    return true;
}
line move_d(line a,const double &len){//将直线a沿法向量方向平移距离len得到的直线
    point d=a.b-a.a;
    d=d/d.norm();
    d=rotate(d,pi/2);
    return line(a.a+d*len,a.b+d*len);
}
/*
polygon 多边形 cvector<point> S
polygon_area 多边形面积 
CutPolygon 用有向直线A->B切割多边形poly
inside 点是否在多边形内 
convehull 求凸包
*/
typedef vector<point> Polygon;
//多边形的有向面积，逆时针为正
double polygon_area(const Polygon &p){
    double area =0.0;
    int n=p.size();
    for (int i = 0; i < n-1; i++)
    {
        area+=det(p[i]-p[0],p[i+1]-p[0]);
    }
    return area*0.5;
}
//用有向直线A->B切割多边形poly， 返回“左侧”。 如果退化，可能会返回一个单点或者线段
//复杂度O(n2);
Polygon CutPolygon(Polygon poly, point A, point B) {
    Polygon newpoly;
    int n = poly.size();
    for(int i = 0; i < n; i++) {
        point C = poly[i];
        point D = poly[(i+1)%n];
        if(dcmp(det(B-A, C-A)) >= 0) newpoly.push_back(C);
        if(dcmp(det(B-A, C-D)) != 0) {
            point ip ;
            line_make_point(A, B-A, C, D-C,ip);
            if(PointOnSegment(ip, C, D)) newpoly.push_back(ip);
        }
    }
    return newpoly;
}
int inside(const Polygon & po,const point &p){
    int wn=0;
    int n=po.size();
    for (int i = 0; i < n; i++)
    {
        if (po[i]==p||po[(i+1)%n]==p||PointOnSegment(p,po[i],po[(i+1)%n]))
        {
            return 0;
        }
        int k=dcmp(det(po[(i+1)%n]-po[i],p-po[i]));
        int d1=dcmp(po[i].y-p.y);
        int d2=dcmp(po[(i+1)%n].y-p.y);
        if(k>0&&d1<=0&&d2>0)
            wn++;
        if(k<0&&d2<=0&&d1>0)
            wn--;
    }
    if(wn!=0)return 1;
    return -1;
}
// 凸包 , 返回值为点数, 凸包结果在ch中
int convehull(Polygon p,Polygon &ch){
    ch.clear();
    sort(p.begin(),p.end(),pcmp);
    int n=p.size();
    int m=0;
    for (int i = 0; i < n; i++)
    {
        while(m>1&&dcmp(det(ch[m-1]-ch[m-2],p[i]-ch[m-1]))<=0)
            m--,ch.pop_back();
        ch.push_back(p[i]),m++;
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while(m>k&&dcmp(det(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0))m--,ch.pop_back();//注意<=与<的区别
        ch.push_back(p[i]),m++;
    }
    if(n>1)m--,ch.pop_back();
    return m;
}

struct Circle{
    point c;
    double r;
    Circle(){};
    Circle(point c,double r=0):c(c),r(r){};
    point cpoint(double a){
        return point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};
int getlinecirclentersection(const Circle &C,line &L,vector<point> &sol){
    double a=L.b.x-L.a.x,b=L.a.x-C.c.x,c=L.a.y-L.b.y,d=L.a.y-C.c.y;
    double e=a*a+c*c,f=2*(a*b+c*d),g=b*b+d*d-C.r*C.r;
    double delta=f*f-4*e*g;
    if(dcmp(delta)<0)return 0;
    if(dcmp(delta)==0){
        sol.push_back(L.prolong(-f/(2*e)));
        return 1;
    }
    sol.push_back(L.prolong((-f-sqrt(delta))/(2*e)));
    sol.push_back(L.prolong((-f+sqrt(delta))/(2*e)));
    return 2;
}
int getcirclecircleintersection(Circle &C1,Circle &C2,vector<point>& sol){
    double d=(C1.c-C2.c).norm();
    if(dcmp(d)==0){
        if(dcmp(C1.r-C2.r)==0)return -1;
        return 0;
    }
    if(dcmp(C1.r+C2.r-d)<0)return 0;
    if(dcmp(fabs(C1.r-C2.r)-d)>0)return 0;
    double  a=angle(C2.c-C1.c);//直线c1c2
    double da=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));//c1c2到c1p1的角
    point p1=C1.cpoint(a-da),p2=C1.cpoint(a+da);
    sol.push_back(p1);
    if(p1==p2)return 1;
    sol.push_back(p2);
    return 2;
}
int getTangents(point p,Circle C,point* v){
    point u=C.c-p;
    double dist=u.norm();
    if(dcmp(dist-C.r)<0)return 0;
    else if(dcmp(dist-C.r)==0){
        v[0]=rotate(u,pi/2);
        return 1;
    }
    else {
        double ang=asin(C.r/dist);
        v[0]=rotate(u,-ang)+p;
        v[1]=rotate(u,+ang)+p;
        return 2;
    }
}
int getTangents(Circle &C1,Circle &C2,point *a ,point *b){
    int cnta=0,cntb=0;
    point p1=(C1.r*C1.c+C2.r*C2.c)/(C1.r+C2.r);
    cnta=getTangents(p1,C1,b);
    for (int i = 0; i < cnta; i++)
    {
        a[i]=p1;
    }
    if(dcmp(C1.r-C2.r)!=0)
    {
        point p2=(C1.r*C1.c-C2.r*C2.c)/(C1.r-C2.r);
        cntb=getTangents(p2,C2,b+cnta);
        for (int i = cnta; i < cnta+cntb; i++)
        {
            a[i]=p2;
        }
    }
    return cnta+cntb;
}






int HalfplaneIntersection(line* L,int n,point* poly)
{
    sort(L,L+n);
    int first,last;
    point *p=new point[n];//会在函数内开大容量数组，请在使用时注意开成全局！！！！！
    line *q=new line[n];//会在函数内开大容量数组，请在使用时注意开成全局！！！！！
    q[first=last=0]=L[0];
    for(int i=1;i<n;i++){
        while(first<last&&!onleft(L[i],p[last-1]))last--;
        while(first<last&&!onleft(L[i],p[first]))first++;
        q[++last]=L[i];
        if(fabs(det(q[last].v(),q[last-1].v()))<eps){
            last--;
            if(onleft(q[last],L[i].a))q[last]=L[i];
        }
        if(first<last)
            line_make_point(q[last-1],q[last],p[last-1]);
    }
    while(first<last&&!onleft(q[first],p[last-1]))last--;
    if(last-first<=1)return 0;
    line_make_point(q[last],q[first],p[last]);

    int m=0;
    for(int i=first;i<=last;i++)poly[m++]=p[i];
    return m;
}//会在函数内开大容量数组，请在使用时注意开成全局


//旋转卡壳

//求凸包内最远点
long long getmaxdistance(point a[],int n)
{
    int j=2;
    double ans=0;
    a[n]=a[0];//方便写下一个点，避免取模
    for(int i=0;i<n;i++){
        while(fabs(det(a[i],a[i+1],a[j+1]))>fabs(det(a[i],a[i+1],a[j])))j=(j+1)%n;
        //通过比较面积大小，比较到直线的距离
        ans=max(ans,(a[j]-a[i]).norm());
    }
    return ans;
}
//求2个凸包间的最短距离
double getmindistance(point p1[],point p2[],int n1,int n2)
{
    int i=0,j=0;
    for(int k=0;k<n1;k++){
        if(p1[k].y<p1[i].y)i=k;//找出p1中的y最小值的点      
    }
    for(int k=0;k<n2;k++){
        if(p2[k].y>p2[j].y)j=k;//找出p2中的y最大值的点
    }
    p1[n1]=p1[0];
    p2[n2]=p2[0];
    double ans=99999999999;
    for(int k=0;k<n1;k++){
        //循环n1次，相当于求p1中每一条边与p2的最近距离
        while((det(p1[i],p1[i+1],p2[j+1])-det(p1[i],p1[i+1],p2[j]))>eps)
            j=(j+1)%n2;
        ans=min(ans,dis_segment_segment(p1[i],p1[i+1],p2[j],p2[j+1]));//求线段间的最短距离
        i=(i+1)%n1;
    }
    return ans;
}
