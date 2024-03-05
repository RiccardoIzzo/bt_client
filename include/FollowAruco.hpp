#include <functional>
#include <memory>
#include <string>
#include <sstream>
#include <optional>

#include "behaviortree_ros2/bt_action_node.hpp"
#include "action_aruco_interfaces/action/follow_aruco.hpp"

using Aruco = action_aruco_interfaces::action::FollowAruco;
using GoalHandleAruco = rclcpp_action::ServerGoalHandle<Aruco>;

using namespace BT;

// Definition of the FollowAruco class, inheriting from RosActionNode
class FollowAruco: public RosActionNode<Aruco>
{
public:
  FollowAruco(const std::string& name,
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
