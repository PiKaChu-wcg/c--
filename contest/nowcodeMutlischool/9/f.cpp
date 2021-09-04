/*
 * @Author: PiKaChu-wcg
 * @Github: https://github.com/PiKaChu-wcg/
 * @Date: 2021-05-05 14:39:13
 * @LastEditTime: 2021-05-05 15:21:48
 * @LastEditors: PiKaChu-wcg
 * @FilePath: \VScode\contest\nowcodeMutlischool\9\f.cpp
 * @Description: 
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 50;
pair<int, int> c[maxn];
int num[maxn];
int main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k;j++){
            cin >> a;
            c[cnt++] = {a, i};
        }
    }
    sort(c, c + cnt);
    int t = 0;
    int r = 0, l = -1;
    int ans = 0x3f3f3f3f;
    while (true)
    {
        bool f = false;
        while (t < m)
        {
            l++;
            if(l==cnt){
                f = true;
                break;
            }
            num[c[l].second]++;
            if (num[c[l].second] == 1)
                t++;
        }
        if(f)
            break;
        while (num[c[r].second] > 1)
        {
            num[c[r].second]--;
            r++;
        }
        ans =min( c[l].first - c[r].first,ans);
        num[c[r].second]--;
        r++;
        t--;
    }

    cout << ans << endl;
}

/*
4 3 
1 3 
2 8 6 
1 2 
3 1 7 5



*/