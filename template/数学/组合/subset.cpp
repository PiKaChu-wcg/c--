#include<iostream>
using namespace std;
void subset(int k, int n)
{
    //枚举2^n以内的所有1个数为k个的数字
    int t = (1 << k) - 1;
    while (t < 1 << n) {
        cout<<t<<endl;
        int x = t & -t, y = t + x;
        t = ((t & ~y) / x >> 1) | y;
    }
}