from setuptools import setup

package_name = 'py_pubsub'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    py_modules=[
        'py_pubsub.publisher_member_function',
        'py_pubsub.subscriber_member_function',
        'py_pubsub.tf2_broadcaster'  # 이 줄을 추가합니다.
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='your.email@example.com',
    description='Examples of minimal publisher/subscriber using rclpy',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'talker = py_pubsub.publisher_member_function:main',
            'listener = py_pubsub.subscriber_member_function:main',
            'tf2_broadcaster = py_pubsub.tf2_broadcaster:main'  # 이 줄을 수정합니다.
        ],
    },
)

