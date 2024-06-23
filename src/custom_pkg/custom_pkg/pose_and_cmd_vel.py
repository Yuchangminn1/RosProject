import rclpy as rp
from rclpy.node import Node

from turtlesim.msg import Pose  # 터틀심의 Pose 메시지를 사용하기 위해 불러옵니다.
from geometry_msgs.msg import Twist  # 이동 명령을 나타내는 Twist 메시지를 사용하기 위해 불러옵니다.
from custom_interfaces.msg import CustomMessage  # 사용자 정의 메시지 CustomMessag을 사용하기 위해 불러옵니다.

class CmdAndPose(Node):

    def __init__(self):
        # 노드 이름을 cmd_and_pose로 설정합니다.
        super().__init__('cmd_and_pose')
        # 터틀심의 pose를 받기 위한 subscriber를 생성합니다.
        self.timer_period = 1.0
        self.sub_pose = self.create_subscription(Pose, '/turtle1/pose', self.callback_pose, 10) 

        # Twist 메시지를 발행하는 발행자를 생성합니다.
        self.pub_cmd_vel = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        # 사용자 정의 메시지 CustomMessag를 발행하는 발행자를 생성합니다.
        self.pub_custom_msg = self.create_publisher(CustomMessage, '/cmd_and_pose', 10)
        
        # 타이머를 생성하고, timer_callback 메서드를 주기적으로 호출합니다.
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        
        # 사용자 정의 메시지와 Twist 메시지를 초기화합니다.
        self.cmd_pose = CustomMessage()
        self.cmd_vel = Twist()
        self.cmd_vel.linear.x = 1.
        self.cmd_vel.angular.z = 1.

    # 터틀심의 pose와 현재 속도를 받는 callback 함수 
    def callback_pose(self, msg):
        # Pose 메시지에서 위치 및 속도 정보를 추출하여 cmd_pose 객체에 저장합니다.
        self.cmd_pose.x = msg.x
        self.cmd_pose.y = msg.y
        self.cmd_pose.cmd_linear_vel = msg.linear_velocity
        self.cmd_pose.cmd_angular_vel = msg.angular_velocity
    
    def timer_callback(self):
        # cmd_pose와 cmd_vel 메시지를 발행합니다.
        self.pub_custom_msg.publish(self.cmd_pose)
        self.pub_cmd_vel.publish(self.cmd_vel)

def main(args=None):
    # 노드를 초기화하고 실행합니다.
    rp.init(args=args)
    turtle_cmd_pose_node = CmdAndPose()
    rp.spin(turtle_cmd_pose_node)
    turtle_cmd_pose_node.destroy_node()
