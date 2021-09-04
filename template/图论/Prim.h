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

int N;
int d[MAXSIZE][MAXSIZE];
int Prim() {
	int res = 0;
	int mind[MAXSIZE];
	mind[0] = INF;
	int used[MAXSIZE];
	mem(used, 0);
	used[1] = 1;

	for (int i = 1; i < N + 1; i++)
	{
		mind[i] = d[1][i];
	}
	for (int i = 0; i < N - 1; i++)
	{
		int mini = 0;
		for (int j = 1; j < N + 1; j++)
		{
			if (mind[mini] > mind[j] && !used[j])
			{
				mini = j;
			}
		}
		used[mini] = 1;
		res += mind[mini];
		for (int j = 1; j < N + 1; j++)
		{
			mind[j] = min(mind[j], d[mini][j]);
		}
	}
	return res;
}
