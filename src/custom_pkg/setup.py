from setuptools import find_packages, setup

package_name = 'custom_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # 런치파일 추가 
        ('share/' + package_name + '/launch', ['launch/run_my_nodes.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='cm23',
    maintainer_email='cm23@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'pose_and_cmd_vel = custom_pkg.pose_and_cmd_vel:main',
            'spawn_turtle_client = custom_pkg.spawn_turtle_client:main',
            'pose_turtle_server = custom_pkg.pose_turtle_server:main',
        ],
    },
)
