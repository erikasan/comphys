import numpy as np, matplotlib.pyplot as plt

plt.style.use('seaborn-darkgrid')

N = 2
T = 1

data = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))

n = len(data)

meanE = data[:, 1]
absM  = data[:, 4]
Cv    = data[:, 5]
X     = data[:, 6]

font = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }

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
    plt.xlabel(r'$M$', fontdict = font)
    plt.legend(['Computed','Analytical value'])
    plt.title(r'$T = %.2f$' % T, fontdict = font)
    plt.tight_layout()
    plt.show()

def plot_meanE():
    plt.hlines(fmeanE(T), 1, n, linewidth = 3, alpha = 0.5, color = 'midnightblue', linestyle = 'dashed')
    plt.plot(meanE, linewidth = 1.3, color = 'gold')
    plt.ylabel(r'$\langle E \rangle$', fontdict = font)
    plot()

def plot_absM():
    plt.hlines(fabsM(T), 1, n, linewidth = 3, alpha = 0.5, color = 'midnightblue', linestyle = 'dashed')
    plt.plot(absM, linewidth = 1.3, color = 'darkorange')
    plt.ylabel(r'$\langle |\mathscr{M}| \rangle$', fontdict = font)
    plot()

def plot_Cv():
    plt.hlines(fCv(T), 1, n, linewidth = 3, alpha = 0.5, color = 'midnightblue', linestyle = 'dashed')
    plt.plot(Cv, linewidth = 1.3, color = 'saddlebrown')
    plt.ylabel(r'$C_v$', fontdict = font)
    plot()

def plot_X():
    plt.hlines(fX(T), 1, n, linewidth = 3, alpha = 0.5, color = 'midnightblue', linestyle = 'dashed')
    plt.plot(X, linewidth = 1.3, color = 'dimgray')
    plt.ylabel(r'$\chi$', fontdict = font)
    plt.ticklabel_format(axis = 'x', style = 'scientific', scilimits = (0,0), useMathText = 1, useOffset=False)
    plot()
