'''
Author: PiKaChu-wcg
Github: https://github.com/PiKaChu-wcg/
Date: 2021-04-30 13:44:42
LastEditTime: 2021-04-30 13:44:59
LastEditors: PiKaChu-wcg
FilePath: \VScode\nowcodeeveryday\4_29.py
Description: https://ac.nowcoder.com/acm/problem/19999
'''
n = int(input())
for i in range(n):
    input()
f = []
f.append(0)
f.append(1)
for i in range(2, n):
    f.append(i * (f[i - 1] + f[i - 2]))
print(f[n - 1])
