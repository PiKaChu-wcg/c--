#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
// * 目前还没找到奇完全数
// * 每个完全数的全部因数倒数之和都是2
// * 除了6以外的完全数，每个都可以表示成连续奇数的立方和
// * 每个完全数都可以表示成2的一些连续正整数次幂之和
// * 完全是都是以6、8结尾
// 当且仅当$n=2^{m-1}(2^m-1)$
bool is_perfect_num(int n){
    int a=2;
    while(a<n/2)a<<=1;
    if(a*(2*a-1)==n)return true;
    return false;
}