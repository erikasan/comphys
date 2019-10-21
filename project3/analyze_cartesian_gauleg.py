import numpy as np, matplotlib.pyplot as plt

data = np.loadtxt('cartesian_gauleg.dat')

N   = data[:, 0];       I = data[:, 1]
err = data[:, 2]; CPUtime = data[:, 3]

exact = 5*np.pi**2/16**2

plt.style.use('fivethirtyeight')

def plot_I():
    plt.plot(N, I, '-o', linewidth = 1, label = '_nolegend_')
    plt.hlines(exact, 0, N[-1] + 3, linestyle = 'dashed', linewidth = 1)
    plt.xlabel(r'$N$')
    plt.ylabel(r'$I$')
    plt.title(r'Integral $I$ vs number of integration points $N$')
    plt.legend([r'$y=5\pi²/16²$'], loc = 'lower right')
    plt.tight_layout()
    plt.show()

def plot_err():
    plt.plot(N, err, '-o', linewidth = 1)

    plt.xlabel(r'$N$')
    plt.ylabel(r'$\varepsilon_{\mathrm{abs}}$')
    plt.title(r'Absolute error $\varepsilon_{\mathrm{abs}}$ vs number of grid points $N$')
    plt.tight_layout()
    plt.show()

def plot_CPUtime():
    plt.plot(N, CPUtime, '-o', linewidth = 1)
    plt.xlabel(r'$N$')
    plt.ylabel(r'CPU time / [$s$]')
    plt.title(r'CPU time vs number of grid points $N$')
    plt.tight_layout()
    plt.show()
