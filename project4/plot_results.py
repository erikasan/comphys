import numpy as np, matplotlib.pyplot as plt

plt.style.use('seaborn-darkgrid')

Nlist = np.array([40, 60, 80, 100])

T = np.array([2.00, 2.05, 2.10, 2.15, 2.20, 2.23, 2.24, 2.25, 2.26, 2.28, 2.30])
skprows = 399998

meanE  = np.zeros(len(T))
meanE2 = np.zeros(len(T))
meanM  = np.zeros(len(T))
meanM2 = np.zeros(len(T))
absM   = np.zeros(len(T))
Cv     = np.zeros(len(T))
X      = np.zeros(len(T))

font = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }

markers = ['o', '^', 's', '*']

'''
for i, t in zip(range(len(T)), T):
    data      = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, t), skiprows = skprows)
    meanE [i] = data[:, 1][-1]
    meanM [i] = data[:, 3][-1]
    absM  [i] = data[:, 4][-1]
    Cv    [i] = data[:, 5][-1]
    X     [i] = data[:, 6][-1]
'''
def plot():
    plt.show()

def plot_meanE():
    for N, marker in zip(Nlist, markers):
        for i, t in zip(range(len(T)), T):
            data = np.loadtxt('data-N=%d-T=%.2f.dat' % (N, t), skiprows = skprows)
            meanE [i] = data[:, 1][-1]

        plt.plot(T, meanE*N**2, marker = marker)
        plot()
