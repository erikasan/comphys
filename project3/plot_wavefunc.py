import numpy as np, matplotlib.pyplot as plt

def wavefunc(r):
    return np.exp(-4*r)

r = np.linspace(0, 2, 1000)

plt.style.use('fivethirtyeight')

plt.plot(r, wavefunc(r))

plt.xlabel(r'$r_1 + r_2$')
plt.legend([r'$\Psi(r_1 + r_2)$'])
plt.tight_layout()
plt.show()
