import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from custom_interfaces.srv import CustomService

class PoseTurtleServer(Node):
    def __init__(self):
        # ROS 노드 초기화
        super().__init__('pose_turtle_client')

        # 터틀심의 Pose 정보를 저장할 변수 초기화
        self.pose_1 = Pose()
        self.pose_2 = Pose()
        self.pose_3 = Pose()
        self.pose_4 = Pose()
        self.pose_list = [self.pose_1, self.pose_2, self.pose_3, self.pose_4]

        # 터틀심의 Pose 정보를 구독하는 Subscriber 설정
        self.sub_pose_1 = self.create_subscription(Pose, '/turtle1/pose', self.callback_pose_1, 10)
        self.sub_pose_2 = self.create_subscription(Pose, '/turtle2/pose', self.callback_pose_2, 10)
        self.sub_pose_3 = self.create_subscription(Pose, '/turtle3/pose', self.callback_pose_3, 10)
        self.sub_pose_4 = self.create_subscription(Pose, '/turtle4/pose', self.callback_pose_4, 10)

        # Pose 정보를 제공하는 서비스 설정
        self.service = self.create_service(CustomService, 'pose_turtle', self.callback_service)

    # 각 터틀의 Pose 정보를 업데이트하는 콜백 함수들
    def callback_pose_1(self, msg):
        self.pose_list[0].x = msg.x
        self.pose_list[0].y = msg.y

    def callback_pose_2(self, msg):
        self.pose_list[1].x = msg.x
        self.pose_list[1].y = msg.y

    def callback_pose_3(self, msg):
        self.pose_list[2].x = msg.x
        self.pose_list[2].y = msg.y

    def callback_pose_4(self, msg):
        self.pose_list[3].x = msg.x
        self.pose_list[3].y = msg.y

    # 서비스 콜백 함수: 로봇의 ID를 받아 해당 로봇의 Pose 정보를 제공
    def callback_service(self, request, response):
        robot_id = request.robot_id

        # 요청한 로봇 ID가 유효한 경우 Pose 정보 반환
        if 1 <= robot_id <= 4:
            response.x = self.pose_list[robot_id - 1].x
            response.y = self.pose_list[robot_id - 1].y
        else:
            # 유효하지 않은 로봇 ID인 경우
            response.x = -1.0  # 로봇 ID를 찾을 수 없을 때 -1로 표시
            response.y = -1.0

        return response

def main(args=None):
    # ROS 노드 초기화 및 노드 클래스 생성
    rclpy.init(args=args)
    pose_turtle_server = PoseTurtleServer()

    # 노드 실행
    rclpy.spin(pose_turtle_server)

    # 노드 종료
    pose_turtle_server.destroy_node()
    rclpy.shutdown()