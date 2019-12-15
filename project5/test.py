import numpy as np, matplotlib.pyplot as plt

plt.style.use('seaborn-darkgrid')

def f(x, t):
    u = 0
    for n in range(1, 1000):
        u += (-1)**n*2/(n*np.pi)*np.sin(n*np.pi*x)*np.exp(-(n*np.pi)**2*t)
    return x + u


x = np.linspace(0, 1, 100)

plt.plot(x, f(x, 0.3))
plt.show()
