# simple-scara-robot

## Why?
This is a project to use a simple scara robot for the following purposes:
- Get familiar with simulations inside ROS2 ecosystem:
  - Rviz2, Gazebo, Moveit2
- Get a grasp of basic robotics concepts like motion planning
- Implement and get familiar with using linear algebra concepts applied to robots:
  - Rotation matrices
 
## How?
The first step was to design a simple scara robot using common components. This is intended to run as a simulation and after to test with real world constraints. <br>
The CAD project can be found at [simple scara onshape](https://cad.onshape.com/documents/279454e002b82a1c88763d28/w/bfc48f8bc82c52e64762d77e/e/52b60b650d906e859a73596c) <br>
The urdf core is extracted from Onshape using [Onshape-to-urdf exporter](https://onshape-urdf-exporter.readthedocs.io/en/latest/). And then refined manually <br>
<br>
All the development environment will run inside a docker container running the [jazzy-desktop-full](https://discourse.openrobotics.org/t/ros-jazzy-docker-images/37879). This allows for flexibility using different flavors of ROS inside my machine (which by the way is not compatible with Jazzy, I'm still running Ubuntu 22), and also it allows for other developers, makers and curious people to run the project locally smoothly. <br>

#### Instructions
Inside the docker folder you will find the Dockerfile, just run the command ```docker build -t scara-jazzy-dev .``` inside to generate an image. After that just running ```./startcontainer.sh``` should start the container, please **read the instructions inside the script**. In case it is not compatible with your system just run the raw command to start a container present inside the script. <br>
The other script ```env.sh``` is to print the environment variables that ROS needs to work, I need that because I'm working on Clion and it won't work without the env variables and the root ```CMakeLists.txt```. So if you're not using Clion you can probably ignore those. Shoutout to [piraka9011](https://github.com/piraka9011) for the script and [instructions](https://www.allaban.me/posts/2020/08/ros2-setup-ide-docker/)
