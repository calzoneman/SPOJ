#!/usr/bin/python3

class Node:
    def __init__(self, oper, lhs, rhs):
        self.oper = oper
        self.lhs = lhs
        self.rhs = rhs

    def rpn(self):
        result = self.lhs.rpn()
        if self.rhs:
            result += self.rhs.rpn()
        return result + self.oper

class VarNode:
    def __init__(self, name):
        self.name = name

    def rpn(self):
        return self.name

class Parser:

    OPCHARS = "+-*/^"
    VARCHARS = "abcdefghijklmnopqrstuvwxyz"

    def __init__(self, src):
        self.src = src
        self.index = 0

    def parse_expr(self):
        if self.src[self.index] == '(':
            self.index += 1
            lhs = self.parse_expr()
            if self.src[self.index] in Parser.OPCHARS:
                oper = self.src[self.index]
                self.index += 1
                rhs = self.parse_expr()
                self.index += 1
                return Node(oper, lhs, rhs)
            elif self.src[self.index] == ')':
                return Node('', lhs, None)
        elif self.src[self.index] in Parser.VARCHARS:
            node = VarNode(self.src[self.index])
            self.index += 1
            return node

if __name__ == "__main__":
    parser = Parser("")
    t = int(input())
    for i in range(t):
        parser = Parser(input())
        print(parser.parse_expr().rpn())
