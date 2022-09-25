#!/usr/bin/env python3
import numpy as np 
import warnings
import matplotlib.pyplot as plt
import freud

with warnings.catch_warnings():
    warnings.simplefilter("ignore")
    N = int(np.genfromtxt("diffraction.xyz", skip_header=3, max_rows=1))
    box_data = np.genfromtxt("diffraction.xyz", skip_header=5, max_rows=3)
    data = np.genfromtxt("diffraction.xyz", skip_header=9, invalid_raise=False)

data = data[~np.isnan(data).all(axis=1)].reshape(-1, N, 6)
box = freud.box.Box.from_box(box_data[:, 1] - box_data[:, 0])
data[..., :3] -= box.L / 2

for frame in data:
    dp = freud.diffraction.DiffractionPattern(grid_size=2048, output_size=2048)
    fig, ax = plt.subplots(figsize=(3, 3), dpi=150)
    dp.compute((box, frame[:, :3]), view_orientation=[1, 0, 0,0])
    dp.plot(ax,cmap='bone')
    #dp.plot(ax,cmap='hot')
    #dp.plot(ax,cmap='bone')
    #plt.show()
    plt.savefig("DP.png")






