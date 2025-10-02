
import numpy as np


theta1 = 0
theta2 = 0

theta1 = (theta1 / 180) * np.pi
theta2 = (theta2 / 180) * np.pi

rotationMatrix0_1 = [[np.cos(theta1), -np.sin(theta1), 0], [np.sin(theta1), np.cos(theta1), 0], [0, 0, 1]]
rotationMatrix1_2 = [[np.cos(theta2), -np.sin(theta2), 0], [np.sin(theta2), np.cos(theta2), 0], [0, 0, 1]]

rotationMatrix0_2 = np.dot(rotationMatrix1_2, rotationMatrix0_1)

# print(rotationMatrix0_2)

a2 = 59.75
a3 = 56
a4 = 46.975
a5 = 41.738

displacementVector0_1 = [[a2*np.cos(theta1)], [a2*np.sin(theta1)], [a3]]
displacementVector1_2 = [[a4*np.cos(theta2)], [a4*np.sin(theta2)], [-a5]]

# print(np.matrix(displacementVector0_1))

homogeneousMatrix0_1 = np.concatenate((rotationMatrix0_1, displacementVector0_1), axis = 1)
homogeneousMatrix0_1 = np.concatenate((homogeneousMatrix0_1, [[0, 0, 0, 1]]), axis = 0)

homogeneousMatrix1_2 = np.concatenate((rotationMatrix1_2, displacementVector1_2), axis = 1)
homogeneousMatrix1_2 = np.concatenate((homogeneousMatrix1_2, [[0, 0, 0, 1]]), axis = 0)

homogeneousMatrix0_2 = np.dot(homogeneousMatrix0_1, homogeneousMatrix1_2)

print(np.matrix(homogeneousMatrix0_2))

# 15.8 h 16.7 v

