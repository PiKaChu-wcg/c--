#include<iostream>
#include<string.h>
using namespace std;

const int maxn=101;
const int maxm=101;
int mod;//需要时使用

struct Matrix{
    int n,m;//行 列
    int a[maxn][maxm];//注意函数内数组大小不能超过500000int
    void Clear(){
        n=m=0;
        memset(a,0,sizeof(a));
    }

    Matrix operator +(const Matrix &b) const{
        Matrix tmp;
        tmp.n=n; tmp.m=m;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                tmp.a[i][j]=a[i][j]+b.a[i][j];
        return tmp;
    }

    Matrix operator -(const Matrix &b) const{
        Matrix tmp;
        tmp.n=n; tmp.m=m;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                tmp.a[i][j]=a[i][j]-b.a[i][j];
        return tmp;
    }

    Matrix operator *(const Matrix &b) const{
        Matrix tmp;
        tmp.Clear();
        tmp.n=n; tmp.m=b.m;
        for(int i=0;i<n;++i)
            for(int j=0;j<b.m;++j)
                for(int k=0;k<m;++k){
                    tmp.a[i][j]+=a[i][k]*b.a[k][j]%mod;
                    tmp.a[i][j]%=mod;
                }
        return tmp;
    }
};
