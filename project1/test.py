import numpy as np, matplotlib.pyplot as plt

data = np.loadtxt('test.dat')
x = data[:, 0]
u = data[:, 1]
plt.plot(x, u)

def f(x):
    return 100*np.exp(-10*x)



plt.show()
