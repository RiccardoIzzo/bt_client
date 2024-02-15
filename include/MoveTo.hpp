#include <functional>
#include <memory>
#include <string>
#include <sstream>
#include <optional>

#include "behaviortree_ros2/bt_action_node.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "yaml-cpp/yaml.h"

using N2P = nav2_msgs::action::NavigateToPose;
using GoalHandleN2P = rclcpp_action::ClientGoalHandle<N2P>;

using namespace BT;

// Definition of the MoveTo class, inheriting from RosActionNode for navigation
class MoveTo: public RosActionNode<nav2_msgs::action::NavigateToPose>
{
public:
  MoveTo(const std::string& name,
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
};
