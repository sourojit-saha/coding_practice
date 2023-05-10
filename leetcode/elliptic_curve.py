import numpy as np
import matplotlib.pyplot as plt

# function is y^2 = x^3 + ax + b
x = np.linspace(-100, 100, 10000)
a = 100
b = 100

y_pos = (x**3 + a*x + b)**0.5

y_neg = -(x**3 + a*x + b)**0.5

plt.plot(x, y_pos)
plt.plot(x, y_neg)
plt.grid()
plt.show()
