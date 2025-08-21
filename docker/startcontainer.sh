#!/bin/bash

# This script is made to open a new terminal with two tabs for
# the math container.
# It's made to work with the terminator terminal and uses the
# xdotool to manipulate terminal commands

# sudo apt install terminator
# sudo apt install xdotool

set -e

CONTAINER_NAME="scara"
IMAGE_NAME="scara-jazzy-dev"
WORKSPACE_DIR="$PWD/scara_ws"

# Check if container is already running
if [ "$(docker ps -q -f name=^/${CONTAINER_NAME}$)" ]; then
    echo "Container ${CONTAINER_NAME} is already running."
else
    # Run container in detached mode with bash entrypoint
    docker run -itd --rm \
        --user void \
        --network=host \
        --ipc=host \
        -v "$WORKSPACE_DIR":/scara_ws \
        -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
        --env=DISPLAY \
        --name $CONTAINER_NAME \
        $IMAGE_NAME \
        bash -c "/entrypoint.sh"
fi

# Wait a moment for the container to initialize
sleep 1

# Open Terminator with a bash session in the container
terminator -e "docker exec -it $CONTAINER_NAME bash" &
sleep 0.25

# Use xdotool to source ROS workspace in first split
xdotool key ctrl+shift+e
sleep 0.1
xdotool type "docker exec -it $CONTAINER_NAME bash -c 'source /opt/ros/jazzy/setup.bash; [ -f /scara_ws/install/setup.bash ] && source /scara_ws/install/setup.bash; exec bash'"
xdotool key Return

# Use xdotool to source ROS workspace in second split
xdotool key ctrl+shift+o
sleep 0.1
xdotool type "docker exec -it $CONTAINER_NAME bash -c 'source /opt/ros/jazzy/setup.bash; [ -f /scara_ws/install/setup.bash ] && source /scara_ws/install/setup.bash; exec bash'"
xdotool key Return