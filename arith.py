#!/usr/bin/python3

import re

def unzeroify(result):
    linelen = len(result)
    result = result.lstrip('0')
    if result == '':
        result = '0'
    return result.rjust(linelen, ' ')

def initial_pass(lhs, rhs, oper=''):
    rhs = oper + rhs
    linelen = max(len(lhs), len(rhs))
    lhs = lhs.rjust(linelen, ' ')
    rhs = rhs.rjust(linelen, ' ')
    # Convert each digit to a number
    top = [0] * linelen
    bottom = [0] * linelen
    for i in range(0, linelen):
        if lhs[i] != ' ':
            top[i] = int(lhs[i])
        if rhs[i] != ' ' and rhs[i] != oper:
            bottom[i] = int(rhs[i])
    return lhs, rhs, top, bottom

def add(lhs, rhs):
    lhs, rhs, top, bottom = initial_pass(lhs, rhs, '+')
    linelen = len(rhs)
    result = ['0'] * linelen
    for i in range(linelen-1, -1, -1):
        c = top[i] + bottom[i]
        if c > 9:
            if i > 0:
                top[i - 1] += 1
            if i - 1 < 0:
                result.insert(0, '1')
                linelen += 1
                lhs = lhs.rjust(linelen, ' ')
                rhs = rhs.rjust(linelen, ' ')
                result[i + 1] = str(c - 10)
            else:
                result[i] = str(c - 10)
        else:
            result[i] = str(c)

    result = unzeroify(''.join(result))

    print(lhs)
    print(rhs)
    print('-' * linelen)
    print(''.join(result))

def sub(lhs, rhs):
    lhs, rhs, top, bottom = initial_pass(lhs, rhs, '-')
    linelen = len(rhs)
    result = ['0'] * linelen
    for i in range(linelen-1, -1, -1):
        if lhs[i] == ' ' and rhs[i] == '-':
            break
        c = top[i] - bottom[i]
        if c < 0:
            if i - 1 > 0:
                top[i - 1] -= 1
            else:
                print("Invalid test case, rhs < lhs for subtraction")
            c += 10
        result[i] = str(c)

    result = unzeroify(''.join(result))

    print(lhs)
    print(rhs)
    print('-' * linelen)
    print(result)


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
        if oper == '+':
            add(lhs, rhs)
        elif oper == '-':
            sub(lhs, rhs)
