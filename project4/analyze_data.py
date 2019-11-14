import numpy  as np, matplotlib.pyplot as plt

plt.style.use('fivethirtyeight')

def plot():
    plt.tight_layout()
    plt.show()

def plot_E(T):
    E = np.loadtxt('data-T=%.2f.dat' % T)[:, 0]
    plt.plot(E, linewidth = 1.3, color = 'gold')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$E$ / [ $J$ ]')
    plot()

def plot_meanE(T):
    meanE = np.loadtxt('data-T=%.2f.dat' % T)[:, 1]
    plt.plot(meanE, linewidth = 1.3, color = 'gold')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$\langle E \rangle$ / [ $J$ ]')
    plot()

def plot_meanE2(T):
    meanE2 = np.loadtxt('data-T=%.2f.dat' % T)[:, 2]
    plt.plot(meanE2, linewidth = 1.3, color = 'gold')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$\langle E^2 \rangle$ / [ $J$ ]')
    plot()

def plot_M(T):
    M = np.loadtxt('data-T=%.2f.dat' % T)[:, 3]
    plt.plot(M, linewidth = 1.3, color = 'darkorange')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$M$ / [ $J$ ]')
    plot()

def plot_meanM(T):
    meanM = np.loadtxt('data-T=%.2f.dat' % T)[:, 4]
    plt.plot(meanM, linewidth = 1.3, color = 'darkorange')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$\langle M \rangle$ / [ $J$ ]')
    plot()

def plot_meanM2(T):
    meanM2 = np.loadtxt('data-T=%.2f.dat' % T)[:, 5]
    plt.plot(meanM2, linewidth = 1.3, color = 'darkorange')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$\langle M^2 \rangle$ / [ $J$ ]')
    plot()

def plot_absM(T):
    absM = np.loadtxt('data-T=%.2f.dat' % T)[:, 6]
    plt.plot(absM, linewidth = 1.3, color = 'darkorange')
    plt.xlabel(r'$ \mathrm{MC sweeps}$')
    plt.ylabel(r'$\langle |M| \rangle$ / [ $J$ ]')
    plot()
