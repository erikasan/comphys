import numpy as np, matplotlib.pyplot as plt

plt.style.use('fivethirtyeight')

N = 2

T  = np.arange  (1, 1.31, 0.05 )
aT = np.linspace(1, 1.30, 10000)

meanE  = np.zeros(len(T))
#meanM  = np.zeros(len(T))
absM   = np.zeros(len(T))
Cv     = np.zeros(len(T))
X      = np.zeros(len(T))

for i, t in zip(range(len(T)), T):
    data      = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, t))
    meanE [i] = np.mean(data[:, 1])
    #meanM [i] = np.mean(data[:, 3])
    absM  [i] = np.mean(data[:, 4])
    Cv    [i] = np.mean(data[:, 5])
    X     [i] = np.mean(data[:, 6])


# Analytical expressions for the 2x2 lattice

def fmeanE(T):
    return -((8*np.sinh(8/T))/(np.cosh(8/T) + 3))/N**2

def fabsM(T):
    return ( (2*np.exp(8/T) + 4)/(np.cosh(8/T) + 3) )/N**2

def fCv(T):
    return ( (  (64*np.cosh(8/T))/(np.cosh(8/T) + 3) \
    - ( (8*np.sinh(8/T))/(np.cosh(8/T) + 3) )**2  )/T**2 )/N**2

def fX(T):
    return 1/T*((8*np.exp(8/T) + 8)/(np.cosh(8/T) + 3))/N**2



# Plotting

def plot():
    plt.xlabel(r'$T$')
    plt.tight_layout()
    plt.show()

def plot_meanE():
    plt.plot(T, meanE, 'o-', linewidth = 1.3, color = 'gold')
    plt.plot(aT, fmeanE(aT), alpha = 0.7)
    plt.ylabel(r'$\langle$ $E(T)$ $\rangle$ / [ $J$ ]')
    plot()


def plot_absM():
    plt.plot(T, absM, 'o-', linewidth = 1.3, color = 'darkorange')
    plt.plot(aT, fabsM(aT), alpha = 0.7)
    plt.ylabel(r'$\langle$ $|M(T)|$ $\rangle$')
    plot()

def plot_Cv():
    plt.plot(T, Cv, 'o-', linewidth = 1.3, color = 'saddlebrown')
    plt.plot(aT, fCv(aT), alpha = 0.7)
    plt.ylabel(r'$C_V(T)$')
    plot()

def plot_X():
    plt.plot(T, X, 'o-', linewidth = 1.3, color = 'dimgray')
    plt.plot(aT, fX(aT), alpha = 0.7)
    plt.ylabel(r'$\chi(T)$')
    plot()
