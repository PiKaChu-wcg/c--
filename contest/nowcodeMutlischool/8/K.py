'''
Author: PiKaChu-wcg
Github: https://github.com/PiKaChu-wcg/
Date: 2021-05-09 12:56:23
LastEditTime: 2021-05-09 12:56:24
LastEditors: PiKaChu-wcg
FilePath: \VScode\contest\nowcodeMutlischool\8\K.py
Description: 
'''
def f():

t=int(input())
for j in range(t):
    n=int(input())
    a=list(map(int,input().split(" ")))
    b=list(map(int,input().split(" ")))
    ans=0
    num=b[0]
    sum=0
    idx=1
    ans+=a[0]*b[0]
    while idx<n:
        sum+=a[idx]
        num=min(num,b[idx])
        if(sum>0):
            ans+=sum*num
            sum=0
        idx+=1
    print("Case #{}: {} {}".format(j+1,b[0],ans))
