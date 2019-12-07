import numpy as np, matplotlib.pyplot as plt

plt.style.use('seaborn-darkgrid')

font = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }

def plot_u(j):
    data = np.loadtxt('data.dat', usecols = j);
    N = np.size(data)
    x = np.linspace(0, 1, N)
    plt.plot(x, data)
    plt.xlabel(r'$x$', fontdict = font)
    plt.ylabel(r'$u(x, t)$', fontdict = font)
    plt.legend([r'$t = %.2f$' % ((1/(N - 1)**2)*j/2)])
    plt.tight_layout()
    plt.show()
