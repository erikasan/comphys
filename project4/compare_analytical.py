import numpy as np, matplotlib.pyplot as plt

plt.style.use('seaborn-darkgrid')

N = 2
skprows = 598000

T  = np.arange  (1, 2.01, 0.10)
aT = np.linspace(1, 2.01, 100000)

font = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }

meanE  = np.zeros(len(T))
absM   = np.zeros(len(T))
Cv     = np.zeros(len(T))
X      = np.zeros(len(T))

for i, t in zip(range(len(T)), T):
    data      = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, t), skiprows = skprows)
    meanE [i] = data[:, 1][-1]
    absM  [i] = data[:, 4][-1]
    Cv    [i] = data[:, 5][-1]
    X     [i] = data[:, 6][-1]


# Analytical expressions for the 2x2 lattice

def fmeanE(T):
    return -((8*np.sinh(8/T))/(np.cosh(8/T) + 3))

def fabsM(T):
    return ( (2*np.exp(8/T) + 4)/(np.cosh(8/T) + 3) )

def fCv(T):
    return ( (  (64*np.cosh(8/T))/(np.cosh(8/T) + 3) \
    - ( (8*np.sinh(8/T))/(np.cosh(8/T) + 3) )**2  )/T**2 )

def fX(T):
    return 1/T*((8*np.exp(8/T) + 8)/(np.cosh(8/T) + 3))


# Plotting

def plot():
    plt.xlabel(r'$T$', fontdict = font)
    plt.legend(['Analytical expression', 'Computed'])
    plt.tight_layout()
    plt.show()

def plot_meanE():
    plt.plot(aT, fmeanE(aT), alpha = 0.5, linewidth = 3, color = 'midnightblue')
    plt.plot(T, meanE, 'o', color = 'gold')
    plt.ylabel(r'$\langle E \rangle$', fontdict = font)
    plot()


def plot_absM():
    plt.plot(aT, fabsM(aT), alpha = 0.5, linewidth = 3, color = 'midnightblue')
    plt.plot(T, absM, 'o',  color = 'darkorange')
    plt.ylabel(r'$\langle$ $|\mathscr{M}|$ $\rangle$',fontdict = font)
    plot()

def plot_Cv():
    plt.plot(aT, fCv(aT), alpha = 0.5, linewidth = 3, color = 'midnightblue')
    plt.plot(T, Cv, 'o',  color = 'saddlebrown')
    plt.ylabel(r'$C_V$', fontdict = font)
    plot()

def plot_X():
    plt.plot(aT, fX(aT), alpha = 0.5, linewidth = 3, color = 'midnightblue')
    plt.plot(T, X, 'o',  color = 'dimgray')
    plt.ylabel(r'$\chi$', fontdict = font)
    plot()
