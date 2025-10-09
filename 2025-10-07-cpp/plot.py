import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D  

data = np.loadtxt("data.txt", skiprows=1)

t = data[:, 0]
x = data[:, 1]
y = data[:, 2]
z = data[:, 3]


fig = plt.figure(figsize=(8,6))
ax = fig.add_subplot(111, projection='3d')
ax.plot(x, y, z, lw=0.5, color='navy')

ax.set_xlabel("X", labelpad=10)
ax.set_ylabel("Y", labelpad=10)
ax.set_zlabel("Z", labelpad=10)
ax.set_title("Atractor de Lorenz (C++ → Python)")


fig.savefig("fig.pdf")
