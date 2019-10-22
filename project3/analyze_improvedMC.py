import numpy as np, matplotlib.pyplot as plt

data = np.loadtxt('improvedMC.dat')

N   = data[:, 0];       I = data[:, 1];
err = data[:, 2]; CPUtime = data[:, 3];

std = data[:, 4]

exact = 5*np.pi**2/16**2

plt.style.use('fivethirtyeight')

def plot_I():
    plt.plot(N, I, '-o', linewidth = 1, label = '_nolegend_')
    plt.hlines(exact, 0, N[-1] + 3, linestyle = 'dashed', linewidth = 1)
    plt.xlabel(r'$N$')
    plt.ylabel(r'$I$')
    plt.title('MC integration with the exp distribution', fontsize = 'medium')
    plt.legend([r'$y=5\pi²/16²$'], loc = 'lower right')
    plt.tight_layout()
    plt.show()

def plot_err():
    plt.plot(N, err, '-o', linewidth = 1)
    plt.xlabel(r'$N$')
    plt.ylabel(r'$\varepsilon_{\mathrm{abs}}$')
    plt.title('MC integration with the exp distribution', fontsize = 'medium')
    plt.tight_layout()
    plt.show()

def plot_CPUtime():
    plt.plot(N, CPUtime, '-o', linewidth = 1)
    plt.xlabel(r'$N$')
    plt.ylabel(r'CPU time / [$s$]')
    plt.title('MC integration with the exp distribution', fontsize = 'medium')
    plt.tight_layout()
    plt.show()

def plot_std():
    plt.plot(N, std, '-o', linewidth = 1)
    plt.xlabel(r'$N$')
    plt.ylabel(r'$\sigma$')
    plt.title('MC integration with the exp distribution', fontsize = 'medium')
    plt.tight_layout()
    plt.show()
