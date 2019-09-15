import numpy as np, matplotlib.pyplot as plt


def exact(x):
    return 1 - (1 - np.exp(-10))*x - np.exp(-10*x)

n_points = np.array([10, 100, 1000])

fig, ax = plt.subplots(len(n_points))
colors = ['red', 'green', 'blue', 'indigo']

for n, i in zip(n_points, range(len(n_points))):
    data = np.loadtxt('poisson-n=1e%d.dat' % np.log10(n))
    x = data[:, 0]; u = data[:, 1]

    ax[i].plot(x, u, colors[i])
    ax[i].legend(['u(x), n = %d' % n])
    ax[i].grid()

plt.tight_layout()
plt.xlabel('x')
#plt.savefig('verification2.png', type = 'png')
plt.show()
