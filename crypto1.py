#!/usr/bin/python3

import time

"""
Calculate k based on the equation
(p-1)/2 = 2k + 1
"""
def k(p):
    return int(((p - 1) / 2 - 1) / 2)

"""
Find sqrt such that (sqrt*sqrt)%p = a
It turns out, if prime p = 3 (mod 4), sqrt can be determined as
sqrt = a^(k+1)%p where k is defined by k(p) from above
The prime given by SPOJ, 4000000007 = 3 (mod 4)

Python's pow() function accepts a 3rd parameter as the modulus, thus
making it possible to efficiently calculate such a large exponent
mod p without overflowing

This yields 2 possible solutions, sqrt and (p-sqrt).
SPOJ's problem description states the year of the answer lies in the range
[1970, 2030].  The timestamp for 2030 is less than half of 4000000007, so
always choose the smaller of the 2 solutions.

Further reading:
<https://en.wikipedia.org/wiki/Quadratic_residue>
<http://www.2000clicks.com/MathHelp/NumberSquareQuadraticResidues.aspx>
"""
def decrypt(a, p):
    sqrt = pow(a, k(p)+1, p)
    if sqrt > p / 2:
        return p - sqrt
    return sqrt

if __name__ == "__main__":
    p = 4000000007
    timestamp = decrypt(int(input()), p)
    print(time.asctime(time.gmtime(timestamp)))
