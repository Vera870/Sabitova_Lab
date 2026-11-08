from sympy import *
import matplotlib.pyplot as plt
import numpy as np

x = symbols("x")

print(limit((cos(x))**1/x, x, 0))

n = symbols('n')

print(limit(cos(x/(n**1/2))**n, n, 00))

expr = (x**2*(sin(3*x))*E**(-x))

print(simplify(diff(expr).subs(x, pi/4)))

expr = x/(x+1)**1/2 

print(integrate(expr, x))
print(integrate(expr, (x, 2)))

y = symbols('y')
X = symbols('X')

F = x**3 + y**3 - 6*x*y

dF_dx = diff(F, x)
dF_dy = diff(F, y)

print(simplify(-dF_dx / dF_dy))

f = Piecewise((X**2, X < 0), (sin(X), X >= 0)) 

print(diff(f, X))

inner_integral = integrate(x + y, (y, x**2, x))

double_integral = integrate(inner_integral, (x, 0, 1))

pprint(double_integral)

x_vals = np.linspace(0, 1, 100)

y_upper = x_vals

y_lower = x_vals**2 

plt.figure(figsize=(6, 5))

plt.fill_between(x_vals, y_lower, y_upper, color='skyblue', alpha=0.5, label='Область D')

plt.plot(x_vals, y_upper, 'r-', label='y = x')
plt.plot(x_vals, y_lower, 'b-', label='y = x²') 

plt.title('Область интегрирования D')
plt.xlabel('x')
plt.ylabel('y')
plt.xlim(0, 1.1)
plt.ylim(0, 1.1)
plt.grid(True, linestyle='--')
plt.legend()
plt.savefig('14.png')
plt.show()


expr = ((x**2 - 4)*(x+3))/(x**2 - x - 6)

print(simplify(expr))

expr = sin(x)**2 + cos(x)**2 + tan(x)**2 - sec(x)**2 

print(trigsimp(expr))

z = symbols('z')

expr = (2*ln(x)*ln(y))/2 + ln(z)

print(logcombine(expr))

print(logcombine(expr).subs(x, 2).subs(y,4).subs(z, 3))

expr = sin(2*x)/(2*sin(x)) + (cos(2*x) - cos(x)**2)/sin(x)**2 

print(simplify(expr))

print(logcombine(expr))
