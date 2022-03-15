////////////////////////////////////////////////
////Author       : PiKaChu_wcg
////Date         : 2022-01-14 16:19:58
////LastEditors  : PiKachu_wcg
////LastEditTime : 2022-01-14 16:39:50
////FilePath     : \c--\new.cpp
////////////////////////////////////////////////
#include<iostream>
#include<cstring>
int main(){
    int x;
    scanf("%d", x);
    char res[1000] ;
    int pos = 0;
    while(x){
        res[pos]= char((x & 111)*10+'0');
        x >>= 3;
    }
    puts(res);
}