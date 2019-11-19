import numpy as np, matplotlib.pyplot as plt

E1 = np.loadtxt('data-N=20-T=1.00.dat', usecols = 0)
E2 = np.loadtxt('data-N=20-T=2.40.dat', usecols = 0)

E1 *= 20**2
E2 *= 20**2

sigma1 = np.std(E1)
sigma2 = np.std(E2)

bns = 200
alph = 0.7
dens = 0

plt.style.use('seaborn-darkgrid')

font = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }


def plot(T, sigma):
    plt.xlabel(r'$E$', fontdict = font)
    plt.ylabel(r'$n(E)$',fontdict = font)
    plt.title(r'$T = %.2f$' % T,fontdict = font)
    plt.legend([r'$\sigma = %.2f$' % sigma], fontsize = 'x-large')
    plt.tight_layout()
    plt.show()

def plot_E1():
    plt.hist(E1, bins = bns, density = dens, log = 1, alpha = alph)
    plot(1, sigma1)

def plot_E2():
    plt.hist(E2, bins = bns, density = dens, log = 0, alpha = alph)
    plt.ticklabel_format(axis = 'y', style = 'scientific', scilimits = (0,0), useMathText = 1, useOffset=False)
    plot(2.4, sigma2)
