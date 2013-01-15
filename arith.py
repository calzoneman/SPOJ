#!/usr/bin/python3

import re
import sys

def addsub(lhs, rhs, oper):
    if oper == '+':
        s = str(int(lhs) + int(rhs))
    elif oper == '-':
        s = str(int(lhs) - int(rhs))
    rhs = oper + rhs
    linelen = max(len(rhs), len(s))

    print(lhs.rjust(linelen, ' '))
    print(rhs.rjust(linelen, ' '))
    print('-' * linelen)
    print(s.rjust(linelen, ' '))

def mul(lhs, rhs):
    pass


if __name__ == "__main__":
    TESTCASE_REGEX = re.compile("([0-9]+)([\\+\\-\\*])([0-9]+)")
    t = int(input())
    for i in range(t):
        case = input()
        match = TESTCASE_REGEX.match(case)
        if not match:
            sys.exit(0)
        lhs = match.group(1)
        oper = match.group(2)
        rhs = match.group(3)
        if oper == '+' or oper == '-':
            addsub(lhs, rhs, oper)
        elif oper == '*':
            mul(lhs, rhs)
