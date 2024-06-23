from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # pose_turtle_server 노드 실행
        Node(
            package='custom_pkg',
            executable='pose_turtle_server',
            name='pose_turtle_server',
            output='screen',  # 노드의 출력을 터미널에 표시
        ),
        # turtlesim_node 노드 실행
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='turtlesim_node',
            output='screen',  # 노드의 출력을 터미널에 표시
        ),
        # spawn_turtle_client 노드 실행
        Node(
            package='custom_pkg',
            executable='spawn_turtle_client',
            name='spawn_turtle_client',
            output='screen',  # 노드의 출력을 터미널에 표시
        ),
    ])