#!/usr/bin/python3

if __name__ == "__main__":
    inputs = []
    while True:
        inp = input()
        if inp == '42':
            break
        inputs.append(inp)
    for i in inputs:
        print(i)
