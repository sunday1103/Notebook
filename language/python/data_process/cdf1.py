import numpy as np
import matplotlib.pyplot as plt

# Fixing random state for reproducibility
np.random.seed(19680801)

mu, sigma = 100, 15
x = mu + sigma * np.random.randn(10000)

x = [1,2,3,4,5,5,5,5,5,5]

x = ['sd', 'dff', 'wew']

# the histogram of the data
n, bins, patches = plt.hist(x, density=True, facecolor='g', alpha=0.75)


plt.xlabel('Smarts')
plt.ylabel('Probability')
plt.title('Histogram of IQ')
plt.text(60, .025, r'$\mu=100,\ \sigma=15$')
plt.xlim(0, 10)
plt.ylim(0, 1)
plt.grid(True)
plt.show()