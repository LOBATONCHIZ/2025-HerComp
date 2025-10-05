import matplotlib.pyplot as plt 
import numpy as np 

n,sumup,sumdown,diff = np.loadtxt("data.txt", unpack=True)
fig, ax = plt.subplots()
ax.plot(n,diff,"-o",label="RelDiff",color="purple")
plt.title("Error relativo")
plt.xscale("log")
plt.yscale("log")
ax.legend()
fig.savefig("fig.pdf")