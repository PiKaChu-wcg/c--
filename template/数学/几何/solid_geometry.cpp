#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-7;
const double pi=acos(-1);
struct Point3{
    double x,y,z;
    Point3(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
};

typedef Point3 Vector3;

Vector3 operator +(Vector3 A,Vector3 B){
    return Vector3(A.x+B.x,A.y+B.y,A.z+B.z);
}
Vector3 operator -(Vector3 A,Vector3 B){
    return Vector3(A.x-B.x,A.y-B.y,A.z-B.z);
}
Vector3 operator *(Vector3 A,double p){
    return Vector3(A.x*p,A.y*p,A.z*p);
}
Vector3 operator /(Vector3 A,double p){
    return Vector3(A.x/p,A.y/p,A.z/p);
}
int dcmp(double a){
    if(fabs(a)<eps)return 0;
    else if(a>0)return 1;
    return -1;
}

bool operator ==(Vector3 a,Vector3 b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0&&dcmp(a.z-b.z)==0;
}
double Dot(Vector3 A,Vector3 B){
    return A.x*B.x+A.y*B.y+A.z*B.z;
}
double Length(Vector3 A){
    return sqrt(Dot(A,A));
}
double Angle(Vector3 A,Vector3 B){
    return acos(Dot(A,B/Length(A)/Length(B)));
}

//点p到平面p0-n的距离。n必须为单位向量
double DistancetoPlane(const Point3& p,const Point3& p0,const Vector3& n){
    return fabs(Dot(p-p0,n));
}

//点p在平面p0-n上的投影。n必须为单位向量
Point3 GetPlaneProjection(const Point3& p,const Point3& p0,const Vector3& n){
    return p-n*Dot(p-p0,n);
}

//直线p1-p2到平面p0-n的交点。假设交点唯一存在
Point3 LinePlaneIntersection(Point3 p1,Point3 p2,Point3 p0,Vector3 n){
    Vector3 v=p2-p1;
    double t=(Dot(n,p0-p1))/Dot(n,p2-p1);
    return p1+v*t;
}

Vector3 Cross(Vector3 A,Vector3 B){
    return Vector3(A.y*B.z-A.z*B.y,A.z*B.x-A.x*B.z,A.x*B.y-A.y*B.x);
}

double Area2(Point3 A,Point3 B,Point3 C){
    return Length(Cross(B-A,C-A));
}

//点p在△p0p1p2中
bool PointInTri(Point3 p,Point3 p0,Point3 p1,Point3 p2){
    double area1=Area2(p,p0,p1);
    double area2=Area2(p,p1,p2);
    double area3=Area2(p,p2,p0);
    return dcmp(area1+area2+area3-Area2(p0,p1,p2))==0;
}

//△p0p1p2是否和线段ab相交
bool TriSegIntersection(Point3 p0,Point3 p1,Point3 p2,Point3 a,Point3 b,Point3& p)
{
    Vector3 n=Cross(p1-p0,p2-p0);
    if(dcmp(Dot(n,b-a))==0)return false;
    else {
        double t=Dot(n,p0-a)/Dot(n,b-a);
        if(dcmp(t)<0||dcmp(t-1)>0)return false;
        p=a+(b-a)*t;
        return PointInTri(p,p0,p1,p2);
    }
}

//点p到直线ab的距离
double DistancetoLine(Point3 p,Point3 a,Point3 b)
{
    Vector3 v1=b-a,v2=p-a;
    return Length(Cross(v1,v2)/Length(v1));
}

//点p到线段ab的距离
double DistanceToSegment(Point3 p,Point3 a,Point3 b){
    if(a==b)return Length(p-a);
    Vector3 v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2)<0))return Length(v2);
    else if(dcmp(Dot(v1,v3))>0)return Length(v3);
    else return Length(Cross(v1,v2))/Length(v1);
}

//返回ab，ac，ad的混合积。它也等于四面体的有向体积的6倍
double Volume6(Point3 a,Point3 b,Point3 c,Point3 d)
{
    return Dot(d-a,Cross(b-a,c-a));
}

