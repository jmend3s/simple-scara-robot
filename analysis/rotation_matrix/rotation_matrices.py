
import numpy as np


theta1 = 0
theta2 = 0

theta1 = (theta1 / 180) * np.pi
theta2 = (theta2 / 180) * np.pi

rotationMatrix0_1 = [[np.cos(theta1), -np.sin(theta1), 0], [np.sin(theta1), np.cos(theta1), 0], [0, 0, 1]]
rotationMatrix1_2 = [[np.cos(theta2), -np.sin(theta2), 0], [np.sin(theta2), np.cos(theta2), 0], [0, 0, 1]]

rotationMatrix0_2 = np.dot(rotationMatrix1_2, rotationMatrix0_1)

print(rotationMatrix0_2)
