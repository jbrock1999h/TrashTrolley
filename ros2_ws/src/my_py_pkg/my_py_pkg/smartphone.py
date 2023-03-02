#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String

# THIS FILE IS AN EXAMPLE OF A SUBSCRIBER FOR A TOPIC

class SmartphoneNode(Node):
    def __init__(self):
        super().__init__("smartphone")
        # This is what makes this node a subscriber. Make sure the topic name is the same as the topic name for the publisher.
        self.subscriber_ = self.create_subscription(
            String, "robot_news", self.callback_robot_news, 10)
        self.get_logger().info("Smartphone has been started.")

    # callback_name_of_function to keep track of everything. Does "msg" need to be called the same thing in the publisher as in the receiver????
    def callback_robot_news(self, msg):
        self.get_logger().info(msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = SmartphoneNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
#CTRL+Shift+I to autoformat your code after writing it. Neat.