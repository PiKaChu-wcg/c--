#define _CRT_SECURE_NO_WARNINGS
#define fastio ios::sync_with_stdio(0);cin.tie(0);
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
#define MAXSIZE 20050


struct Edge
{
	ll to, next;
	ll w;
}edge[MAXSIZE];
ll head[MAXSIZE];
ll used[MAXSIZE];
ll low[MAXSIZE];
typedef pair<ll, ll> P;
void dij(ll start) {
	mem(used, 0);
	mem(low, INF);
	priority_queue<P, vector<P>, greater<P>> q;
	used[start] = 1;
	low[start] = 0;
	q.push(P(0, start));
	while (!q.empty())
	{
		P top = q.top();
		q.pop();
		ll u = top.second;
		for (ll k = head[u]; k != -1; k = edge[k].next)
		{
			if (low[edge[k].to] > low[u] + edge[k].w)
			{
				low[edge[k].to] = low[u] + edge[k].w;
				q.push(P(low[edge[k].to], edge[k].to));
			}
		}
	}
}
ll cnt = 0;
void addedge(ll f, ll t, ll w) {
	edge[cnt].to = t;
	edge[cnt].w = w;
	edge[cnt].next = head[f];
	head[f] = cnt++;
}
