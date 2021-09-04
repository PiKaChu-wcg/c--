#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define rep1(i,n)	for(reg (i)=1;(i)<=(n);(i)++)
#define rep0(i,n)	for(reg (i)=0;(i)<n;(i)++)
#include<stdio.h>
#include<cstring>
#include<iostream>
#include <algorithm>
#include<math.h>
#include<functional>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define INF 0x3f3f3f3f33f3ff3f
#define ll long long
#define mem(x,y) memset((x),(y),sizeof(x))
#define MAXSIZE 2050

int head[MAXSIZE],ver[MAXSIZE*2],next[MAXSIZE*2];
int dfn[MAXSIZE],low[MAXSIZE],n,m,tot,num;
bool bridge[MAXSIZE*2];
void add(int x,int y){
    ver[++tot]=y,next[tot]=head[x],head[x]=tot;
}
void tarjan(int x,int in_edge){
    dfn[x]=low[x]=++num;
    for(int i=head[x];i;i=next[i]){
        int y=ver[i];
        if(!dfn[y]){
            tarjan(y,i);
            low[x]=min(low[x],low[y]);
            if(low[y]>dfn[x])bridge[i]=bridge[i^1]=true;
        }
        else if(i!=(in_edge^1))low[x]=min(low[x],dfn[y]);
    }
}