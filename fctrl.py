#!/usr/bin/python3

import math

def z(n):
    power = math.floor(math.log(n, 5))
    return sum([int(n / (5 ** k)) for k in range(1, power + 1)])

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        print(z(int(input())))
