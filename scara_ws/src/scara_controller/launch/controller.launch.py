
from launch import LaunchDescription
from launch_ros.actions import Node
import os
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    xacro_file = os.path.join(
        get_package_share_directory("scara_description"),
        "urdf",
        "robot.urdf.xacro"
    )

    robot_description = ParameterValue(
        Command(f"xacro {xacro_file}"),
        value_type=str,
    )

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{"robot_description": robot_description}]
    )
    #
    # controller_manager = Node(
    #     package="controller_manager",
    #     executable="ros2_control_node",
    #     parameters=[
    #         {"robot_description": robot_description},
    #         os.path.join(
    #             get_package_share_directory("scara_controller"),
    #             "config",
    #             "scara_controllers.yaml"
    #         )
    #     ],
    #     output="screen"
    # )

    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "joint_state_broadcaster",
            "--controller-manager",
            "/controller_manager",
        ]
    )

    arm_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "arm_controller",
            "--controller-manager",
            "/controller_manager",
        ]
    )

    actuator_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "actuator_controller",
            "--controller-manager",
            "/controller_manager",
        ]
    )

    return LaunchDescription([
        robot_state_publisher,
        # controller_manager,
        joint_state_broadcaster_spawner,
        arm_controller_spawner,
        actuator_controller_spawner
    ])