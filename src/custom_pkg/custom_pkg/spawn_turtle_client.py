import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn

class TurtleSpawnClient(Node):

    def __init__(self):
        super().__init__('turtle_spawn_client')
        self.client = self.create_client(Spawn, 'spawn')  # 'spawn' 서비스 클라이언트 생성
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('서비스 서버를 대기 중...')

    def spawn_turtle(self, x, y, theta, name):
        request = Spawn.Request()
        request.x = x
        request.y = y
        request.theta = theta
        request.name = name

        future = self.client.call_async(request)  # 서비스 호출 비동기로 실행
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None:
            self.get_logger().info(f'{name} 거북이 생성 완료')
        else:
            self.get_logger().error(f'{name} 거북이 생성 실패')

def main(args=None):
    rclpy.init(args=args)
    turtle_spawn_client = TurtleSpawnClient()

    # 새로운 거북이를 생성하고 번호를 부여합니다.
    turtle_spawn_client.spawn_turtle(2.0, 2.0, 0.0, 'turtle2')  # 예시: (x, y, theta, name)
    turtle_spawn_client.spawn_turtle(5.0, 5.0, 0.0, 'turtle3')
    turtle_spawn_client.spawn_turtle(8.0, 8.0, 0.0, 'turtle4')
    rclpy.spin(turtle_spawn_client)
    turtle_spawn_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()