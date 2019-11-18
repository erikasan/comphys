import numpy  as np, matplotlib.pyplot as plt

font = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }

plt.style.use('seaborn-darkgrid')

def plot(N, T):
    plt.xlabel(r'$M$', fontdict = font)
    plt.title(r'$%d \times %d, T = %.2f$' % (N, N, T), fontdict = font)
    plt.tight_layout()
    plt.show()

def plot_E(N, T):
    E = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 0]
    plt.plot(E, linewidth = 1.3, color = 'gold')
    plt.ylabel(r'$E$', fontdict = font)
    plot(N, T)

def plot_meanE(N, T):
    meanE = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 1]
    plt.plot(meanE, linewidth = 1.3, color = 'gold')
    plt.ylabel(r'$\langle E \rangle$',fontdict = font)
    plot(N, T)


def plot_M(N, T):
    M = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 2]
    plt.plot(M, linewidth = 1.3, color = 'darkorange')
    plt.ylabel(r'$\mathscr{M}$',fontdict = font)
    plot(N, T)

def plot_meanM(N, T):
    meanM = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 3]
    #plt.hlines(0, 0, 1e6, linewidth = 3, alpha = 0.5, color = 'midnightblue', linestyle = 'dashed')
    plt.plot(meanM, linewidth = 1.3, color = 'darkorange')
    plt.ylabel(r'$\langle \mathscr{M} \rangle$',fontdict = font)
    plt.ticklabel_format(axis = 'x', style = 'scientific', scilimits = (0,0), useMathText = 1, useOffset=False)
    #plt.legend(['Computed','Analytical value'])
    plot(N, T)


def plot_absM(N, T):
    absM = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 4]
    plt.plot(absM, linewidth = 1.3, color = 'darkorange')
    plt.ylabel(r'$\langle \mathscr{|M|} \rangle$ ',fontdict = font)
    plot(N, T)

def plot_Cv(N, T):
    Cv = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 5]
    plt.plot(Cv, linewidth = 1.3, color = 'saddlebrown')
    plt.ylabel(r'$C_v$',fontdict = font)
    plot(N, T)

def plot_X(N, T):
    X = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 6]
    plt.plot(X, linewidth = 1.3, color = 'dimgray')
    plt.ylabel(r'$\chi$',fontdict = font)
    plot(N, T)
