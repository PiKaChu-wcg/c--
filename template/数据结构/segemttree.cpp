#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
const int maxn=1e5+50;
struct segemttree
{
    int l,r;
    int dat;
}t[maxn<<2];

void build(int p,int l, int r){
    t[p].l=l,t[p]=r;
    if(l==r){t[p].dat=a[l];return;}
    int mid=(r+l)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].dat=max(t[p*2].dat,t[p*2+1].dat);
}//build(1,1,n)//调用入口


void change(int p,int x,int v){
    if(t[p].l==t[p].r){t[p].dat=v;return;}
    int mid=(t[p].l+t[p].r)/2;
    if(x<=mid)change(p*2,x,v);
    else change(p*2+1,x,v);
    t[p].dat=max(t[p*2].dat,t[p*2+1].dat);
}//change(1,x,v)//调用入口

int ask(int p ,int l , int r){
    if(l<=t[p].l&&r>=t[p].r)return t[p].dat;
    int mid=(t[p].l,t[p].r)/2;
    int val=-(1<<30);
    if(l<mid)val=max(val,ask(p*2,l,r));
    if(r>mid)val=max(val,ask(p*2+1,l,r));
    return val;
}//ask(1,l,r)//调用入口
int main(){
    return 0;
}


//version 2
struct SegTree {
    struct Nod {
        int l, r, tag;
        int data;
    } nod[MAXN];
#define ls (p*2)
#define rs (p*2+1)
#define mid ((l+r)/2)
    int build(int l, int r, int p) {//调用时请使用build(1,n,1),并把数据预先放在val中
        nod[p] = {l, r, 0, 0};
        if (l == r)
            return nod[p].data = val[l];
        else
            return nod[p].data = build(l, mid, ls) + build(mid + 1, r, rs);
    }
 
    void pushdown(int p) {//下放懒惰标记， 懒惰标记意思是当前值已经修改，以下值未修改
        nod[ls].data += nod[p].tag * (nod[ls].r - nod[ls].l + 1);
        nod[rs].data += nod[p].tag * (nod[rs].r - nod[rs].l + 1);
        nod[ls].tag += nod[p].tag, nod[rs].tag += nod[p].tag;
        nod[p].tag = 0;
    }
 
    void edit(int l, int r, int p, int num) {//调用的时候使用edit(l,r,1,num)
        if (l <= nod[p].l && nod[p].r <= r) {//完全、包含
            nod[p].data += num * (nod[p].r - nod[p].l + 1);
            nod[p].tag += num;
        } else if (min(nod[p].r, r) - max(nod[p].l, l) + 1 > 0) {//有交集
            nod[p].data += num * (min(nod[p].r, r) - max(nod[p].l, l) + 1);
            edit(l, r, ls, num);
            edit(l, r, rs, num);
        }
    }
 
    int sum(int l, int r, int p) {//对区间l到r进行求和
        if (nod[p].tag)pushdown(p);
        if (l <= nod[p].l && nod[p].r <= r)//完全包含
            return nod[p].data;
        else if(nod[p].l>r||nod[p].r<l)
            return 0;
        else if (nod[p].l <= l || nod[p].r >= r)//有交集
            return sum(l, r, ls) + sum(l, r, rs);
        return 0;
    }
 
#undef ls
#undef rs
#undef mid
} segTree;