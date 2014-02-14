#usr/bin/env python

#module to test the working of the vector module

from q2 import *

def test_generic_functions():
    p1 = 1, 2, 3
    p2 = 4, 5, 6
    p3 = 7, 8, 9
    p4 = 1, 9, 5
    assert(type(length((p1, p2))) is float)
    assert(type(normalize((p3, p4))) is tuple)
    assert(type(dot_product((p1, p2), (p3, p4))) is int or type(dot_product((p1, p2), (p3, p4))) is float)
    assert(type(cross_product((p1, p2), (p3, p4))) is tuple)

    try:
        length(p2)
        assert(0)
    except ValueError as e:
        pass
    
    try:
        length(p1, p2, p3)
        assert(0)
    except TypeError as e:
        pass
    
    try:
        normalize(p4)
        assert(0)
    except ValueError as e:
        pass
    
    try:
        normalize(p4, p2, p3)
        assert(0)
    except TypeError as e:
        pass

    try:
        dot_product(p3)
        assert(0)
    except TypeError as e:
        pass

    try:
        dot_product(p1, p4)
        assert(0)
    except ValueError as e:
        pass

    try:
        cross_product((p1, p2), (p3))
        assert(0)
    except ValueError as e:
        pass

    try:
        cross_product(p2)
        assert(0)
    except TypeError as e:
        pass

if __name__ == '__main__':
    test_generic_functions()
