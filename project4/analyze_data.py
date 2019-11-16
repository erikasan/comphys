import numpy  as np, matplotlib.pyplot as plt

plt.style.use('fivethirtyeight')

def plot():
    plt.tight_layout()
    plt.show()

def plot_E(N, T):
    E = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 0]
    plt.plot(E, linewidth = 1.3, color = 'gold')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$E$ / [ $J$ ]')
    plot()

def plot_meanE(N, T):
    meanE = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 1]
    plt.plot(meanE, linewidth = 1.3, color = 'gold')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$\langle E \rangle$ / [ $J$ ]')
    plot()


def plot_M(N, T):
    M = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 2]
    plt.plot(M, linewidth = 1.3, color = 'darkorange')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$M$')
    plot()

def plot_meanM(N, T):
    meanM = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 3]
    plt.plot(meanM, linewidth = 1.3, color = 'darkorange')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$\langle M \rangle$')
    plot()


def plot_absM(N, T):
    absM = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 4]
    plt.plot(absM, linewidth = 1.3, color = 'darkorange')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$\langle |M| \rangle$ ')
    plot()

def plot_Cv(N, T):
    Cv = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 5]
    plt.plot(Cv, linewidth = 1.3, color = 'saddlebrown')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$C_v$')
    plot()

def plot_X(N, T):
    X = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, T))[:, 6]
    plt.plot(X, linewidth = 1.3, color = 'dimgray')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$\chi$')
    plot()
