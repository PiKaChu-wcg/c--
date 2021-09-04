/*
 * @Author: PiKaChu-wcg
 * @Github: https://github.com/PiKaChu-wcg/
 * @Date: 2021-05-04 16:45:57
 * @LastEditTime: 2021-05-04 17:22:29
 * @LastEditors: PiKaChu-wcg
 * @FilePath: \VScode\contest\nowcodeMutlischool\10\i.cpp
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int n2 = n / 2;
    for (int i = 2; i <= n2;i++){
        for (int j = 1; j < i;j++){
            cout << j << " " <<i<< endl;
        }
    }
    for (int i = 1; i <= n2; i++)
    {
        for (int j = n2 + 1; j <= n; j++)
        {
            cout << i << " " << j << endl;
        }
    }
    for (int i = n2+1; i <= n;i++){
        for (int j = i+1; j <= n;j++){
            cout << i << " " << j << endl;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}