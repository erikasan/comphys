import numpy as np, matplotlib.pyplot as plt

plt.style.use('seaborn-darkgrid')

skprows = 399998
#T = np.arange(2.0, 2.31, 0.05)
T = np.array([2.23, 2.24, 2.25, 2.26, 2.28, 2.30])

Nlist = np.array([40, 60, 80, 100])

font = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }

Cv = np.zeros(len(T))
X  = np.zeros(len(T))

TCv = np.zeros(len(Nlist))
TX  = np.zeros(len(Nlist))

for N, j in zip(Nlist, range(len(Nlist))):
    for i, t in zip(range(len(T)), T):
        data  = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, t), skiprows = skprows)
        Cv[i] = data[:, 5][-1]
        X [i] = data[:, 6][-1]

    where  = np.where(Cv == np.max(Cv))
    TCv[j] = T[where]
    where  = np.where(X  == np.max(X))
    TX [j] = T[where]

T = list(TX) + list(TCv)
invN = 2*list(1/Nlist)
(a, b), cov = np.polyfit(invN, T, 1, cov = 1)

plt.plot(1/Nlist, TCv, '-o', color = 'saddlebrown')
plt.plot(1/Nlist, TX,  '-o', color = 'dimgray')
plt.plot(1/Nlist, a/Nlist + b)

plt.xlabel(r'$N^{-1}$', fontdict = font)
plt.ylabel(r'$T_C$', fontdict = font)
plt.legend([r'Obtained from $C_v$', r'Obtained from $\chi$', '$y=%.2fN^{-1} + %.2f$' % (a, b)], loc = (0.58, 0.6), frameon = 1)
plt.tight_layout()
plt.show()
