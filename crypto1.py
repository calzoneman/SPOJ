#!/usr/bin/python3

import time

def k(p):
    return int(((p - 1) / 2 - 1) / 2)

def decrypt(a, p):
    sqrt = pow(a, k(p)+1, p)
    if sqrt > p / 2:
        return p - sqrt
    return sqrt

if __name__ == "__main__":
    p = 4000000007
    timestamp = decrypt(int(input()), p)
    print(time.asctime(time.gmtime(timestamp)))
