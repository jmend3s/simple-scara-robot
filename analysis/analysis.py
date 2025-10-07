
import numpy as np


theta1 = 0
theta2 = 0

theta1 = (theta1 / 180) * np.pi
theta2 = (theta2 / 180) * np.pi

rotationMatrix0_1 = [[np.cos(theta1), -np.sin(theta1), 0], [np.sin(theta1), np.cos(theta1), 0], [0, 0, 1]]
rotationMatrix1_2 = [[np.cos(theta2), -np.sin(theta2), 0], [np.sin(theta2), np.cos(theta2), 0], [0, 0, 1]]

rotationMatrix0_2 = np.dot(rotationMatrix0_1, rotationMatrix1_2)

print(np.matrix(rotationMatrix0_2))
print("\n")

a2 = 5.975
a3 = 5.6
a4 = 4.6975
a5 = 4.1738

displacementVector0_1 = [[a2*np.cos(theta1)], [a2*np.sin(theta1)], [a3]]
displacementVector1_2 = [[a4*np.cos(theta2)], [a4*np.sin(theta2)], [-a5]]

print(np.matrix(displacementVector1_2))
print("\n")

homogeneousMatrix0_1 = np.concatenate((rotationMatrix0_1, displacementVector0_1), axis = 1)
homogeneousMatrix0_1 = np.concatenate((homogeneousMatrix0_1, [[0, 0, 0, 1]]), axis = 0)

homogeneousMatrix1_2 = np.concatenate((rotationMatrix1_2, displacementVector1_2), axis = 1)
homogeneousMatrix1_2 = np.concatenate((homogeneousMatrix1_2, [[0, 0, 0, 1]]), axis = 0)

# print(np.matrix(homogeneousMatrix1_2))

homogeneousMatrix0_2 = np.dot(homogeneousMatrix0_1, homogeneousMatrix1_2)

print(np.matrix(homogeneousMatrix0_2))

# y = 4.2 x = 10.3

