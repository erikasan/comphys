import numpy as np, matplotlib.pyplot as plt


data = np.loadtxt('cnt_iterations.dat');

n = data[:, 0]; iterations = data[:, 1]; CPUtime = data[:, 2]
p = np.polyfit(n, iterations, 3)

prop_cycle = plt.rcParams['axes.prop_cycle']
colors = prop_cycle.by_key()['color']

plt.ticklabel_format(axis = 'y', style = 'sci', scilimits = (0, 0), useMathText = True)
plt.style.use('fivethirtyeight')
plt.plot(n, iterations, marker = 'o', color = colors[0])
plt.plot(n, p[0]*n**3 + p[1]*n**2 + p[2]*n + p[3], alpha = 0.5, color = colors[1])
plt.xlabel('Matrix dimension n'); plt.ylabel('# of iterations')
plt.grid()
plt.grid()
plt.tight_layout()
plt.show()
