import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("./data_float.txt")
data_double = np.loadtxt("./data_double.txt")
plt.loglog( data[:, 0], data[ :, 1 ], marker='o' )
plt.loglog( data_double[:, 0], data_double[ :, 1 ], marker='o' )
plt.show()
