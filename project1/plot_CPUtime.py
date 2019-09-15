import numpy as np, matplotlib.pyplot as plt

notsimple = np.loadtxt('CPU_time_notsimple.dat')
simple = np.loadtxt('CPU_time_simple.dat')
LU = np.loadtxt('CPU_time_LU.dat')

"""
plt.plot(notsimple[:, 0], notsimple[:, 1], 'blue')
plt.plot(simple[:, 0], simple[:, 1], 'green')
plt.plot(LU[:, 0], LU[:, 1], 'red')
plt.xlabel('n'); plt.ylabel('CPU Time / [s]')
plt.legend(['Thomas algorithm', 'Simplified Thomas algorithm', 'LU decomposition'])
plt.grid()
plt.show()
"""

a1, b1 = np.polyfit(notsimple[:, 0], notsimple[:, 1], 1)
a2, b2 = np.polyfit(simple[:, 0], simple[:, 1], 1)
a3, b3 = np.polyfit(LU[:, 0], LU[:, 1], 1)

objects = ('General TA', 'Simplified TA')
y_pos = np.arange(len(objects))
performance = [1000*a1, 1000*a2]

plt.bar(y_pos, performance, align='center', alpha=0.5)
plt.xticks(y_pos, objects)
plt.ylabel('Slope / [CPU time per 1000 steps]')

plt.show()
