#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=1e6+5;

//三角形外接圆（三点保证不共线）
Circle CircumscribedCircle(point p1, point p2, point p3){
    double Bx = p2.x-p1.x, By = p2.y-p1.y;
    double Cx = p3.x-p1.x, Cy = p3.y-p1.y;
    double D = 2*(Bx*Cy-By*Cx);
    double cx = (Cy*(Bx*Bx+By*By)-By*(Cx*Cx+Cy*Cy))/D+p1.x;
    double cy = (Bx*(Cx*Cx+Cy*Cy)-Cx*(Bx*Bx+By*By))/D+p1.y;
    point p = point(cx,cy);
    return Circle(p,Length(p1-p));
}
//三角形内切圆
Circle InscribedCircle(point p1, point p2, point p3){
    double a = Length(p2-p3);
    double b = Length(p3-p1);
    double c = Length(p1-p2);
    point p = (p1*a+p2*b+p3*c)/(a+b+c);
    return Circle(p, DistanceToLine(p, p1, p2));
}