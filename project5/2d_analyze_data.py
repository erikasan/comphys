import numpy as np, matplotlib.pyplot as plt

plt.style.use('seaborn-darkgrid')

font = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }

N = 30
n = 10000
T = 1

def plot(f):
    plt.xlabel(r'$x$')
    plt.ylabel(r'$y$')
    x = np.linspace(0, 1, N); y = np.linspace(0, 1, N)
    x, y = np.meshgrid(x, y)
    plt.pcolormesh(x, y, f, cmap = 'inferno')
    plt.tight_layout()
    plt.show()

def plot_u(k):
    data = np.loadtxt('data2d.dat', skiprows = k*N, max_rows = N)
    plot(data)

def f(x, y, t):
    return np.sin(np.pi*x)*np.sin(np.pi*y)*np.exp(-2*np.pi**2*t)

def plot_f(k):
    t = k*T/(n - 1)
    plot(f(x, y, t))
