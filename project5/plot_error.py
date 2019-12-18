import numpy as np, matplotlib.pyplot as plt

plt.style.use('seaborn-darkgrid')

# N = 11

data = np.loadtxt('errors-N=11.dat')
eps_FE = data[:, 0]; eps_BE  = data[:, 1]; eps_CN = data[:, 2]

t = np.linspace(0, 0.4, len(eps_FE))

plt.plot(t, eps_FE)
plt.plot(t, eps_BE)
plt.plot(t, eps_CN)

# N = 101

data = np.loadtxt('errors-N=101.dat')
eps_FE = data[:, 0]; eps_BE  = data[:, 1]; eps_CN = data[:, 2]

#plt.plot(t, eps_FE)
#plt.plot(t, eps_BE)
#plt.plot(t, eps_CN)

'''
plt.legend([r'Forward Euler  \Delta x = 0.1' ,
            r'Backward Euler \Delta x = 0.1' ,
            r'Crank-Nicolson \Delta x = 0.1' ,
            r'Forward Euler  \Delta x = 0.01',
            r'Backward Euler \Delta x = 0.01',
            r'Crank-Nicolson \Delta x = 0.01',])
'''

plt.legend([r'Forward Euler ',
            r'Backward Euler',
            r'Crank-Nicolson'])

plt.title(r'$\Delta x = 0.1$')
plt.xlabel(r'$t$')
plt.ylabel(r'$\epsilon(t)$')
plt.show()
