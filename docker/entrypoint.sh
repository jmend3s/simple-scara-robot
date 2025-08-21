#!/bin/bash
set -e

# Source ROS workspace if it exists
if [ -f /scara_ws/install/setup.bash ]; then
    source /scara_ws/install/setup.bash
fi

# Keep container alive with bash
exec bash