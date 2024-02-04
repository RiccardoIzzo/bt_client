#include <functional>
#include <memory>
#include <string>
#include <sstream>
#include <optional>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "behaviortree_ros2/plugins.hpp"
#include "behaviortree_ros2/bt_action_node.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "yaml-cpp/yaml.h"
#include <chrono>

using namespace BT;

#define TIMEOUT 15

// Definition of the MoveTo class, inheriting from RosActionNode for navigation
class MoveToWithTimeout: public RosActionNode<nav2_msgs::action::NavigateToPose>
{
public:
  MoveToWithTimeout(const std::string& name,
                const NodeConfig& conf,
                const RosNodeParams& params);

    static PortsList providedPorts();
    bool setGoal(Goal& goal) override;
    NodeStatus onFeedback(const std::shared_ptr<const Feedback> feedback);
    NodeStatus onResultReceived(const WrappedResult& wr) override;
    virtual NodeStatus onFailure(ActionNodeErrorCode error) override;
private:
    // Shared pointer to the ROS 2 node for communication
    std::shared_ptr<rclcpp::Node> client;
    std::chrono::steady_clock::time_point start_time;
    std::chrono::seconds timeout_duration;
};