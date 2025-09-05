#!/bin/bash
set -e

if [ -f /scara_ws/install/setup.bash ]; then
    source /scara_ws/install/setup.bash
fi

exec bash
echo "export RMW_IMPLEMENTATION=rmw-cyclonedds-cpp" >> /home/void/.bashrc

