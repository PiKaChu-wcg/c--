/*
 * @Author: PiKaChu-wcg
 * @Github: https://github.com/PiKaChu-wcg/
 * @Date: 2021-05-04 15:19:48
 * @LastEditTime: 2021-05-04 15:19:49
 * @LastEditors: PiKaChu-wcg
 * @FilePath: \VScode\contest\nowcodeMutlischool\10\c.cpp
 * @Description: 
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<pair<int, int>> e[maxn];
int main(){
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        e[v].push_back({u, w});
        e[w].push_back({v, w});
    }
    

}