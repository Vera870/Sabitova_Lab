import matplotlib.pyplot as plt
import numpy as np
import matplotlib


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

matplotlib.rcParams['font.family'] = 'sans-serif'
matplotlib.rcParams['font.sans-serif'] = ['Arial']

# 1. Создаем сетку 50 на 50
# Берем диапазон от -2 до 2, чтобы график не уходил слишком далеко в бесконечность
x = np.linspace(-2, 2, 50)
y = np.linspace(-2, 2, 50)
X, Y = np.meshgrid(x, y)

# 2. Вычисляем функцию g(x,y) = 1/x^2 + 1/y^2
# Используем np.errstate, чтобы Python не ругался на деление на ноль, 
# а просто выдал 'inf' (бесконечность)
with np.errstate(divide='ignore'):
    Z = 1 / (X**2) + 1 / (Y**2)

# Чтобы график не был испорчен "бесконечностями", мы их немного обрежем
# Ограничим максимальное значение Z, например, до 10
Z[Z > 10] = 10

# Создаем окно для графиков
fig = plt.figure(figsize=(15, 5))

# --- Тип 1: 3D-поверхность (Surface) ---
ax1 = fig.add_subplot(131, projection='3d')
surf = ax1.plot_surface(X, Y, Z, cmap='viridis', edgecolor='none')
ax1.set_title('3D-поверхность')
ax1.set_xlabel('X')
ax1.set_ylabel('Y')
ax1.set_zlabel('Z')

# --- Тип 2: Карта цветов (Heatmap / pcolormesh) ---
ax2 = fig.add_subplot(132)
mesh = ax2.pcolormesh(X, Y, Z, cmap='plasma', shading='auto')
ax2.set_title('Тепловая карта (pcolormesh)')
fig.colorbar(mesh, ax=ax2) # Добавляем шкалу справа

# --- Тип 3: Контурный график (Contour) ---
ax3 = fig.add_subplot(133)
contour = ax3.contourf(X, Y, Z, levels=15, cmap='coolwarm')
ax3.set_title('Контурный график (contourf)')
fig.colorbar(contour, ax=ax3)

plt.tight_layout()
plt.savefig('12_2.png')
plt.show()
