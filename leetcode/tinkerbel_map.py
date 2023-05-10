import numpy as np
import matplotlib.pyplot as plt

x0 = -0.72
y0 = -0.64

x = [x0]
y = [x0]

coeff_1 = [0.9, -0.6013, 2.0, 0.5]
coeff_2 = [0.3, 0.6, 2.0, 0.27]

coeff_used  = []

for i in coeff_1:
    coeff_used.append(i)

iterations = 100000

color = [0]

for i in range(iterations):
    x_prev = x[-1]
    y_prev = y[-1]

    x_next = x_prev**2 - y_prev**2 + coeff_used[0]*x_prev + coeff_used[1]*y_prev
    y_next = 2*x_prev*y_prev + coeff_used[2]*x_prev + coeff_used[3]*y_prev

    x.append(x_next)
    y.append(y_next)
    color.append(i)

plt.scatter(x, y, s = 1, c = "green")
plt.show()