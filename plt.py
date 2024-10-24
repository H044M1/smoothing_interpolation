import matplotlib.pyplot as plt
import numpy as np


filename = "spline_results.txt"
data = np.loadtxt(filename)


original_y = data[:, 0]
interpolated_y = data[:, 1]
smoothed_y_0 = data[:, 2]
smoothed_y_33 = data[:, 3]
smoothed_y_66 = data[:, 4]
smoothed_y_99 = data[:, 5]

# Построение графиков
x_values = np.arange(len(original_y))

plt.figure(figsize=(10, 6))
plt.plot(x_values, original_y, label="Original", linestyle='--', color='blue')
plt.plot(x_values, interpolated_y, label="Interpolated", color='red')
plt.plot(x_values, smoothed_y_0, label="Smoothed (p=0)", color='green')
plt.plot(x_values, smoothed_y_33, label="Smoothed (p=0.33)", color='orange')
plt.plot(x_values, smoothed_y_66, label="Smoothed (p=0.66)", color='purple')
plt.plot(x_values, smoothed_y_99, label="Smoothed (p=0.99)", color='black')

plt.legend()
plt.xlabel("X values(index)")
plt.ylabel("Y values")
plt.title("Interpolation and Smoothing Splines")
plt.grid(True)

plt.show()