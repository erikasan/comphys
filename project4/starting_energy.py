import numpy as np, matplotlib.pyplot as plt

T = np.arange(2.20, 2.31, 0.02)
E = np.array([-944, -3416, -6072, -8716, -10824, -13044])

plt.style.use('fivethirtyeight')
plt.plot(T, E, 'o-', color = 'gold', linewidth = 1.3)
plt.xlabel(r'$T$')
plt.ylabel(r'Initital energy $E$ / [$J$]')
plt.tight_layout()
plt.show()
