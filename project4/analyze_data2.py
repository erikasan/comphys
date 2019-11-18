import numpy as np, matplotlib.pyplot as plt

plt.style.use('seaborn-darkgrid')

N = 60
T = np.arange(2.0, 2.31, 0.05)
skprows = 0

meanE  = np.zeros(len(T))
meanE2 = np.zeros(len(T))
meanM  = np.zeros(len(T))
meanM2 = np.zeros(len(T))
absM   = np.zeros(len(T))
Cv     = np.zeros(len(T))
X      = np.zeros(len(T))

font = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }

for i, t in zip(range(len(T)), T):
    data      = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, t), skiprows = skprows)
    meanE [i] = data[:, 1][-1]
    meanM [i] = data[:, 3][-1]
    absM  [i] = data[:, 4][-1]
    Cv    [i] = data[:, 5][-1]
    X     [i] = data[:, 6][-1]

def plot():
    plt.xlabel(r'$T$', fontdict = font)
    plt.tight_layout()
    plt.show()

def plot_meanE():
    plt.plot(T, meanE, 'o-', linewidth = 1.3, color = 'gold')
    plt.ylabel(r'$\langle$ $E(T)$ $\rangle$',fontdict = font)
    plot()


def plot_meanM():
    plt.plot(T, meanM, 'o-', linewidth = 1.3, color = 'darkorange')
    plt.ylabel(r'$\langle$ $\mathscr{M}(T)$ $\rangle$',fontdict = font)
    plot()


def plot_absM():
    plt.plot(T, absM, 'o-', linewidth = 1.3, color = 'darkorange')
    plt.ylabel(r'$\langle$ $|\mathscr{M}(T)|$ $\rangle$',fontdict = font)
    plot()

def plot_Cv():
    plt.plot(T, Cv, 'o-', linewidth = 1.3, color = 'saddlebrown')
    plt.ylabel(r'$C_V$',fontdict = font)
    plot()

def plot_X():
    plt.plot(T, X, 'o-', linewidth = 1.3, color = 'dimgray')
    plt.ylabel(r'$\chi$',fontdict = font)
    plot()
