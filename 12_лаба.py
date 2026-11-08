import matplotlib.pyplot as plt
import numpy as np


x = np.linspace(0, 10, 100)
y1 = np.sin(x)
y2 = np.cos(x)


plt.plot(x, y1, color='red', linewidth=2, linestyle='--', label='Синус')
plt.plot(x, y2, color='blue', linewidth=5, linestyle='--', label='Косинус')


plt.title('Графики тригонометрических функций')
plt.xlabel('Угол (радианы)')
plt.ylabel('Значение')
plt.grid(True)
plt.legend() 

plt.savefig('12.png')
plt.show()


