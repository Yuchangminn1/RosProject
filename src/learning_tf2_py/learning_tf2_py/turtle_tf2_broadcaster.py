import math

from geometry_msgs.msg import TransformStamped

import numpy as np

import rclpy
from rclpy.node import Node

from tf2_ros import TransformBroadcaster

from turtlesim.msg import Pose


def quaternion_from_euler(ai, aj, ak):
    ai /= 2.0
    aj /= 2.0
    ak /= 2.0
    ci = math.cos(ai)
    si = math.sin(ai)
    cj = math.cos(aj)
    sj = math.sin(aj)
    ck = math.cos(ak)
    sk = math.sin(ak)
    cc = ci*ck
    cs = ci*sk
    sc = si*ck
    ss = si*sk

    q = np.empty((4, ))
    q[0] = cj*sc - sj*cs
    q[1] = cj*ss + sj*cc
    q[2] = cj*cs - sj*sc
    q[3] = cj*cc + sj*ss

    return q


class FramePublisher(Node):

    def __init__(self):
        super().__init__('turtle_tf2_frame_publisher')

        # `turtlename` 파라미터를 선언하고 가져옵니다.
        self.turtlename = self.declare_parameter(
          'turtlename', 'turtle').get_parameter_value().string_value

        # 변환 브로드캐스터 초기화
        self.tf_broadcaster = TransformBroadcaster(self)

        # turtle{1}{2}/pose 토픽에 구독하고 각 메시지에 handle_turtle_pose 콜백 함수를 호출합니다.
        self.subscription = self.create_subscription(
            Pose,
            f'/{self.turtlename}/pose',
            self.handle_turtle_pose,
            1)
        self.subscription  # 사용하지 않는 변수 경고 방지

    def handle_turtle_pose(self, msg):
        t = TransformStamped()

        # 메시지 내용을 읽고 해당 TF 변수에 할당합니다.
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'world'
        t.child_frame_id = self.turtlename

        # 거북이는 2D 공간에서만 존재하므로 메시지에서 x 및 y 변환 좌표를 가져와 z 좌표를 0으로 설정합니다.
        t.transform.translation.x = msg.x
        t.transform.translation.y = msg.y
        t.transform.translation.z = 0.0

        # 같은 이유로 거북이는 하나의 축 주위로만 회전할 수 있으므로 x 및 y 회전을 0으로 설정하고 z 축 회전은 메시지에서 가져옵니다.
        q = quaternion_from_euler(0, 0, msg.theta)
        t.transform.rotation.x = q[0]
        t.transform.rotation.y = q[1]
        t.transform.rotation.z = q[2]
        t.transform.rotation.w = q[3]

        # 변환을 게시합니다.
        self.tf_broadcaster.sendTransform(t)


def main():
    rclpy.init()
    node = FramePublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    rclpy.shutdown()