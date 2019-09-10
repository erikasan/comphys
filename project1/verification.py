import numpy as np, matplotlib.pyplot as plt

def exact(x):
    return 1 - (1 - np.exp(-10))*x - np.exp(-10*x)

n_points = np.array([10, 100, 1000])

fig, ax = plt.subplots(len(n_points) + 1)
colors = ['red', 'green', 'blue', 'indigo']

x = np.linspace(0, 1, 1000)
ax[0].plot(x, exact(x), colors[0])
ax[0].legend(['Exact solution f(x)'])
ax[0].grid()

for n, i in zip(n_points, range(1, len(n_points) + 1)):
    data = np.loadtxt('poisson-n=1e%d.dat' % np.log10(n))
    x = data[:, 0]; u = data[:, 1]

    ax[i].plot(x, u, colors[i])
    ax[i].legend(['u(x), n = %d' % n])
    ax[i].grid()

plt.tight_layout()
plt.xlabel('x')
plt.savefig('verification.png', type = 'png')
