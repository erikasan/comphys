import numpy as np, matplotlib.pyplot as plt

plt.style.use('seaborn-darkgrid')

T = 0.4
n = 80
N = 11

def f(x, t):
    u = 0
    for n in range(1, 20):
        u += (-1)**n*2/(n*np.pi)*np.sin(n*np.pi*x)*np.exp(-(n*np.pi)**2*t)
    return x + u

def compare(j):
    FE = np.loadtxt('forwardeuler.dat' , usecols = j)
    BE = np.loadtxt('backwardeuler.dat', usecols = j)
    CN = np.loadtxt('cranknicolson.dat', usecols = j)
    N = np.size(FE)
    t = T/(n - 1)*j
    x = np.linspace(0, 1, N)
    plt.plot(x, FE)
    plt.plot(x, BE)
    plt.plot(x, CN)
    x = np.linspace(0, 1, 1000)
    plt.plot(x, f(x, t), color = 'darkslategray', linewidth = 5, alpha = 0.3)
    plt.xlabel(r'$x$')
    plt.ylabel(r'$u(x, t)$')
    plt.title(r'$\Delta x = 0.1, t = %.2f$' % t)
    plt.legend([r'Forward Euler','Backward Euler','Crank-Nicolson', 'Analytical solution'], loc = 'upper left')
    plt.tight_layout()
    plt.show()
