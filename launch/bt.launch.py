import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription

from launch_ros.actions import Node


def generate_launch_description():
  pkg_bt_client = get_package_share_directory('bt_client')

  client_node_cmd = Node(
      package="bt_client",
      executable="client",
      name="client",
      parameters=[{
          "location_file": os.path.join(pkg_bt_client, "config", "locations.yaml")
      }]
  )

  ld = LaunchDescription()

  # Add the commands to the launch description
  ld.add_action(client_node_cmd)

  return ld