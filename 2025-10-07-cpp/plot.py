import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  # para el gráfico 3D

# Leer archivo (usa skiprows si tiene encabezado)
data = np.loadtxt("lorenz_trayectoria.txt", skiprows=1, delimiter=",")

t = data[:, 0]
x = data[:, 1]
y = data[:, 2]
z = data[:, 3]

# Crear figura
fig = plt.figure(figsize=(8,6))
ax = fig.add_subplot(111, projection='3d')

# Graficar el atractor
ax.plot(x, y, z, lw=0.5, color='navy')

# Etiquetas y título
ax.set_xlabel("X", labelpad=10)
ax.set_ylabel("Y", labelpad=10)
ax.set_zlabel("Z", labelpad=10)
ax.set_title("Atractor de Lorenz (C++ → Python)")

# Ajustar vista y estilo
ax.view_init(elev=30, azim=45)
plt.tight_layout()

# Guardar en PDF con buena resolución
plt.savefig("lorenz_atractor.pdf", format="pdf", bbox_inches="tight")
