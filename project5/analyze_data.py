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

fig, ax = plt.subplots(2)
x = np.linspace(0, 1, 1000)
ax[0].plot(x, f(x, 0), color = 'darkslategray', linewidth = 5, alpha = 0.3)
ax[0].set_ylabel(r'$u(x, 0.001)$')
ax[0].set_title(r'$t=0.000$')
ax[0].legend(['Analytical solution'])
ax[0].set_yticks([0, 0.5, 1])

ax[1].plot(x, f(x, 0.001), color = 'darkslategray', linewidth = 5, alpha = 0.3)
ax[1].set_xlabel(r'$x$')
ax[1].set_ylabel(r'$u(x, 0)$')
ax[1].set_title(r'$t=0.001$')
ax[1].legend(['Analytical solution'])
ax[1].set_yticks([0, 0.5, 1])
plt.tight_layout()
plt.show()
