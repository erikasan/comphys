import numpy as np, matplotlib.pyplot as plt

plt.style.use('fivethirtyeight')

T = np.arange(2.20, 2.31, 0.02)

meanE  = np.zeros(len(T))
meanE2 = np.zeros(len(T))
meanM  = np.zeros(len(T))
meanM2 = np.zeros(len(T))
absM   = np.zeros(len(T))

for i, t in zip(range(len(T)), T):
    data      = np.loadtxt('data-T=%.2f.dat' % t)
    meanE [i] = np.mean(data[:, 1])
    meanE2[i] = np.mean(data[:, 2])
    meanM [i] = np.mean(data[:, 4])
    meanM2[i] = np.mean(data[:, 5])
    absM  [i] = np.mean(data[:, 6][95000:])

def plot():
    plt.xlabel(r'$T$')
    plt.tight_layout()
    plt.show()

def plot_meanE():
    plt.plot(T, meanE, 'o-', linewidth = 1.3, color = 'gold')
    plt.ylabel(r'$\langle$ $E(T)$ $\rangle$ / [ $J$ ]')
    plot()

def plot_meanE2():
    plt.plot(T, meanE2, 'o-', linewidth = 1.3, color = 'gold')
    plt.ylabel(r'$\langle$ $E(T)^2$ $\rangle$ / [ $J$ ]')
    plot()

def plot_meanM():
    plt.plot(T, meanM, 'o-', linewidth = 1.3, color = 'darkorange')
    plt.ylabel(r'$\langle$ $M(T)$ $\rangle$ / [ $J$ ]')
    plot()

def plot_meanM2():
    plt.plot(T, meanM2, 'o-', linewidth = 1.3, color = 'darkorange')
    plt.ylabel(r'$\langle$ $M(T)^2$ $\rangle$ / [ $J$ ]')
    plot()

def plot_absM():
    plt.plot(T, absM, 'o-', linewidth = 1.3, color = 'darkorange')
    plt.ylabel(r'$\langle$ $|M(T)|$ $\rangle$')
    plot()

def plot_C():
    plt.plot(T, (meanE2 - meanE**2)/T**2, 'o-', linewidth = 1.3, color = 'saddlebrown')
    plt.ylabel(r'$C_V(T)$')
    plot()

def plot_X():
    plt.plot(T, (meanM2 - absM**2)/T, 'o-', linewidth = 1.3, color = 'dimgray')
    plt.ylabel(r'$\chi(T)$')
    plot()
