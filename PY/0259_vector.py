"""Vector - An abstraction on functions to be performed on vectors"""

from math import sqrt

def length(vector):
# function to get the length of a vector
    p1, p2 = vector
    x1, y1, z1 = p1
    x2, y2, z2 = p2
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 -z1, 2))

def normalize(vector):
# function to return unit vector in the same direction as given vector
    p1, p2 = vector
    x1, y1, z1 = p1
    x2, y2, z2 = p2
    if p1 == p2:
        return (0, 0, 0), (0, 0, 0)
    else:
        l = length(vector)
        return (0, 0, 0), ((x2 - x1)/l, (y2 - y1)/l, (z2 - z1)/l)

def dot_product(vectorA, vectorB):
# function to return dot product of two vectors
    p1, p2 = vectorA
    q1, q2 = vectorB
    x1, y1, z1 = p1
    x2, y2, z2 = p2
    x3, y3, z3 = q1
    x4, y4, z4 = q2
    return (x2 - x1)*(x4 - x3) + (y2 - y1)*(y4 - y3) + (z2 - z1)*(z4 - z3)

def cross_product(vectorA, vectorB):
# function to return cross product of two vectors
    p1, p2 = vectorA
    q1, q2 = vectorB
    x1, y1, z1 = p1
    x2, y2, z2 = p2
    x3, y3, z3 = q1
    x4, y4, z4 = q2
    return (0, 0, 0), ((y2 - y1)*(z4 - z3) - (y4 - y3)*(z2 - z1), (x4 - x3)*(z2 - z1) - (x2 - x1)*(z4 - z3), (x2 - x1)*(y4 - y3) - (x4 - x3)*(y2 - y1))
