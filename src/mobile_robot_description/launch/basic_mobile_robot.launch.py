import launch


from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch.substitutions import PathJoinSubstitution
from launch.substitutions import Command, LaunchConfiguration

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    start_rviz = LaunchConfiguration('start_rviz')
    use_sim_time = LaunchConfiguration('use_sim_time', default='True')
 
    default_model_dir = PathJoinSubstitution(
        [
            FindPackageShare('mobile_robot_description'),
            'urdf',
            'basic_mobile_robot.urdf'
        ]
    )

    rviz_config_file = PathJoinSubstitution(
        [
            FindPackageShare('mobile_robot_description'),
            'rviz',
            'display.rviz'
        ]
    )
    
    # robot_state_publisher를 실행하는 노드를 설정합니다.
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'use_sim_time': use_sim_time, 'robot_description': Command(['xacro ', LaunchConfiguration('model')])}]

    )
    
    # joint_state_publisher를 실행하는 노드를 설정합니다.
    joint_state_publisher_node = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher',
        condition=launch.conditions.UnlessCondition(LaunchConfiguration('gui'))
    )
    # joint_state_publisher_gui를 실행하는 노드를 설정합니다.
    joint_state_publisher_gui_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        condition=launch.conditions.IfCondition(LaunchConfiguration('gui'))
    )

    # rviz를 실행하는 노드를 설정합니다.
    rviz_node = Node(
            package='rviz2',
            executable='rviz2',
            arguments=['-d', rviz_config_file],
            output='screen',
            condition=IfCondition(start_rviz))

    return LaunchDescription([
        # 런치 파일에 사용할 인자들을 정의합니다.
        DeclareLaunchArgument(
            'start_rviz',
            default_value='True',
            description='Whether execute rviz2'),

        DeclareLaunchArgument(
            'use_sim',
            default_value='True',
            description='Start robot in Gazebo simulation'),
            
        DeclareLaunchArgument(
            name='gui',
            default_value='True',
            description='Flag to enable joint_state_publisher_gui'),

        DeclareLaunchArgument(
            name='model', 
            default_value=default_model_dir,
            description='Absolute path to robot urdf file'),

        DeclareLaunchArgument(
            name='rvizconfig',
            default_value=rviz_config_file,
            description='Absolute path to rviz config file'),
            
        DeclareLaunchArgument(
            name='use_sim_time',
            default_value='True',
            description='Flag to enable use_sim_time'),
        
        
        # 위에서 정의한 노드들을 실행합니다.
        joint_state_publisher_node,
        robot_state_publisher_node,
        joint_state_publisher_gui_node,
        rviz_node,
    ])
