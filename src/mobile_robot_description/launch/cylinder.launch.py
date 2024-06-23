import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, Command
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    start_rviz = LaunchConfiguration('start_rviz')
    use_sim_time = LaunchConfiguration('use_sim_time', default='True')
    gui = LaunchConfiguration('gui', default='True')
    model = LaunchConfiguration('model', default=PathJoinSubstitution(
        [
            FindPackageShare('mobile_robot_description'),
            'urdf',
            'cylinder.urdf'
        ]
    ))
    rviz_config_file = PathJoinSubstitution(
        [
            FindPackageShare('mobile_robot_description'),
            'rviz',
            'display.rviz'
        ]
    )

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'use_sim_time': use_sim_time, 'robot_description': Command(['xacro ', model])}]
    )
    
    joint_state_publisher_node = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher',
        condition=UnlessCondition(gui)
    )
    
    joint_state_publisher_gui_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        condition=IfCondition(gui)
    )
    
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config_file],
        condition=IfCondition(start_rviz)
    )

    return LaunchDescription([
        DeclareLaunchArgument('gui', default_value='True', description='Flag to enable joint_state_publisher_gui'),
        DeclareLaunchArgument('start_rviz', default_value='True', description='Flag to enable RViz'),
        DeclareLaunchArgument('use_sim_time', default_value='True', description='Use simulation (Gazebo) clock if true'),
        DeclareLaunchArgument('model', default_value=model, description='Absolute path to robot urdf file'),
        robot_state_publisher_node,
        joint_state_publisher_node,
        joint_state_publisher_gui_node,
        rviz_node
    ])

