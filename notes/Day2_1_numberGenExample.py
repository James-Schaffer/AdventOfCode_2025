from math import log10, ceil, floor

s_val = 30
e_val = 76

def simpleSI(val:int):
    return floor( val / (1 + 10**floor( float(len(str(val))) / 2.0 )) )

def fx(x):
    return x*(1 + 10**(ceil(log10(x+0.01))) )

l = simpleSI(s_val)
r = simpleSI(e_val)

print(f"{s_val} : {e_val} => \n > {"\n > ".join([str(fx(i)) for i in range(l, r+1)])}")