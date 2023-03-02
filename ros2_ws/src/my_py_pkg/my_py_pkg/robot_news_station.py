#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String
     
#THIS FILE IS AN EXAMPLE OF A PUBLISHER FOR A TOPIC

class RobotNewsStationNode(Node):
    def __init__(self): #Constructor of the node
        super().__init__("robot_news_station") #Create a node called "robot_news_station"

        self.robot_name_ = "C3PO"
        self.publisher_ = self.create_publisher(String, "robot_news", 10) #This is what makes the node a Publisher...(Data type, name of topic, queue size(10 is default))
        self.timer_ = self.create_timer(0.5, self.publish_news)
        self.get_logger().info("Robot News Station has been started.") #Inform the user through a log that the node has been started. Debugging

    def publish_news(self): #Print out something. This is what controls the info being sent to the topic (think radio transmission tower -> 97.5 FM)
        msg = String()
        msg.data = "Hi, this is " + str(self.robot_name_) + " from the robot news station."
        self.publisher_.publish(msg)
    
    
def main(args=None): #Start with the Main function
    rclpy.init(args=args) #Initialize ROS2 communications
    node = RobotNewsStationNode() #Create the node (Next step: go up to "Class RobotNewsStationNode(Node)")
    rclpy.spin(node)#Keep the node running. It will repeat the instructions from the class.
    rclpy.shutdown()#CTRL + C will make the node stop spinning, and then it will shut down. Stop Communications.
    
    
if __name__ == "__main__":
    main()