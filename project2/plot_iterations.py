import numpy as np, matplotlib.pyplot as plt

data = np.loadtxt('cnt_iterations.dat');

n = data[:, 0]; iterations = data[:, 1]; CPUtime = data[:, 2]


# Plot # of iterations vs matrix dimension
plt.style.use('fivethirtyeight')
plt.grid()
plt.grid()
plt.plot(n, iterations, 'o')
plt.xlabel('Matrix dimension n'); plt.ylabel('# of iterations')
plt.tight_layout()
plt.show()


'''
# Plot CPU time vs matrix dimension
plt.style.use('fivethirtyeight')
plt.grid()
plt.grid()
plt.plot(n, CPUtime)
plt.tight_layout()
plt.show()
'''
# Iterations, least squares and error analysis
p, error = np.polyfit(n, iterations, 3, cov = True)


# CPUtime, least squares and error analysis
#p, error = np.polyfit(n, CPUtime, 3, cov = True)
