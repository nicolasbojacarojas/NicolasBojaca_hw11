import numpy as np
import matplotlib.pyplot as plt
x = np.loadtxt("tray.txt")
x1 = x[:,0]
v1 = x[:,1]
t1 = x[:,2]
plt.plot(x1, t1)
plt.savefig("pos")
plt.close()
plt.plot(v1, t1)
plt.savefig("vel")
plt.close()
plt.plot(v1, x1)
plt.savefig("phase")
plt.close()
