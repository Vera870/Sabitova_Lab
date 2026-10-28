import math
import numpy 

print(math.e)  
print(math.pi)

x = 100

print(math.sqrt(x))

y = 30

print(math.radians(y))

z = math.radians(y)

print(math.degrees(z))

A = numpy.random.randint(1, 10, size=(3, 10))

A_T = A.T

print(A)

A2 = A
A3 = A.copy()

A2[0,0] = 67
A3[0,0] = 52

print(A)
print(A2)
print(A3)

s = A*A2

matrix = A@A_T

print(s)
print(matrix)



A = numpy.random.randint(1, 10, size=(3, 10))
B = numpy.random.randint(1, 10, size=(10,))

AAT = A @ A.T                
AAT_inv = numpy.linalg.inv(AAT) 
AT_B = A @ B                 
X_1 = AAT_inv @ AT_B


X_2 = numpy.linalg.lstsq(A.T, B, rcond=None)[0]

print(X_1)
print(X_2)
print(X_2-X_1)

s_range = range(11)
s_arange = numpy.arange(11)
s_linspace  = numpy.linspace(0, 10, 11)
print(list(s_range), type(s_range))
print(s_arange, type(s_arange))
print(s_linspace, type(s_linspace))