import numpy as np, matplotlib.pyplot as plt

def wavefunc(r):
    return np.exp(-2*r)

r = np.linspace(0, 4, 10000)

plt.style.use('fivethirtyeight')

plt.plot(r, wavefunc(r), label='_nolegend_')
plt.plot(3, wavefunc(3),'o', markersize = 7)

plt.xlabel(r'$r$')
plt.ylabel(r'$\psi(r)$')
plt.legend([r'$(%.1f, \hspace{0.3} %.2f\times 10^{%d})$' % (3, wavefunc(3)/(10**(-3)), -3)], loc = (0.45, 0.25), numpoints = 1, facecolor = 'blue', framealpha = 0.1)
plt.tight_layout()
plt.show()
