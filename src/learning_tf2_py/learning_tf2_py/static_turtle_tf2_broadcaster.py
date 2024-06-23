import math
import sys

from geometry_msgs.msg import TransformStamped
import numpy as np
import rclpy
from rclpy.node import Node
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster

# 함수: 오일러 각도를 쿼터니언으로 변환
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
    cc = ci * ck
    cs = ci * sk
    sc = si * ck
    ss = si * sk

    q = np.empty((4,))
    q[0] = cj * sc - sj * cs
    q[1] = cj * ss + sj * cc
    q[2] = cj * cs - sj * sc
    q[3] = cj * cc + sj * ss

    return q

# 클래스: 정적 프레임을 브로드캐스트하는 노드
class StaticFramePublisher(Node):

    def __init__(self, transformation):
        super().__init__('static_turtle_tf2_broadcaster')
        self.tf_static_broadcaster = StaticTransformBroadcaster(self)
        self.make_transforms(transformation)

    # 함수: 정적 프레임을 만들어 브로드캐스트
    def make_transforms(self, transformation):
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'world'
        t.child_frame_id = transformation[1]

        t.transform.translation.x = float(transformation[2])
        t.transform.translation.y = float(transformation[3])
        t.transform.translation.z = float(transformation[4])
        quat = quaternion_from_euler(
            float(transformation[5]), float(transformation[6]), float(transformation[7]))
        t.transform.rotation.x = quat[0]
        t.transform.rotation.y = quat[1]
        t.transform.rotation.z = quat[2]
        t.transform.rotation.w = quat[3]

        self.tf_static_broadcaster.sendTransform(t)

# 메인 함수
def main():
    logger = rclpy.logging.get_logger('logger')

    # 명령행 인수에서 매개변수 얻기
    if len(sys.argv) != 8:
        logger.info('매개변수 개수가 잘못되었습니다. 사용법:\n'
                    '$ ros2 run learning_tf2_py static_turtle_tf2_broadcaster'
                    'child_frame_name x y z roll pitch yaw')
        sys.exit(1)

    if sys.argv[1] == 'world':
        logger.info('정적 거북이 프레임 이름은 "world"일 수 없습니다.')
        sys.exit(2)

    # 매개변수 전달 및 노드 초기화
    rclpy.init()
    node = StaticFramePublisher(sys.argv)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    rclpy.shutdown()

if __name__ == '__main__':
    main()