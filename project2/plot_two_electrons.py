import numpy as np, matplotlib.pyplot as plt

omega = 5

n = 300;

rho_min = 0; rho_max = 5
h = (rho_max - rho_min)/(n+1);

rho = np.linspace(rho_min + h, rho_max - h, n)

plt.style.use('fivethirtyeight')

fig, ax = plt.subplots(2, sharex = True, sharey = True)

for c, ax, title in zip([0, 1], ax, ['No Coloumb interaction', 'With Coloumb interaction']):
    eigvals = np.loadtxt('eigvals-o=%.2f-c=%d.dat' % (omega, c))
    eigstates = np.loadtxt('eigstates-o=%.2f-c=%d.dat' % (omega, c))

    i = np.where(eigvals == np.min(eigvals))[0][0]
    ground_state = eigstates[:, i]

    norm = np.trapz(np.abs(ground_state)**2, dx = h)
    ground_state*= 1/np.sqrt(norm)
    ax.plot(rho, np.abs(ground_state)**2)

    ax.set_ylabel(r'$| \psi (\rho)|^2$')
    ax.set_title(title, fontsize = 'medium')

plt.legend([r'$\omega_r = %.2f$' % omega])
plt.xlabel(r'$\rho$');
plt.tight_layout()
plt.show()
