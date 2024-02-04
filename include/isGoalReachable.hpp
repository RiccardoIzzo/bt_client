#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "behaviortree_ros2/plugins.hpp"
#include "behaviortree_ros2/bt_action_node.hpp"

#include <chrono>
#include <cstdlib> 

using namespace BT;
using namespace std::chrono;

#define DELAY 10

// Definition of the isGoalReachable class, inheriting from StatefulActionNode for checking the reachibility of a given goal
class isGoalReachable : public StatefulActionNode {
public:
    isGoalReachable(const std::string& name, const NodeConfig& config);
    static PortsList providedPorts();
    NodeStatus onStart() override;
    NodeStatus onRunning() override;
    virtual void onHalted() override;
private:
    system_clock::time_point deadline;
    bool isReachable;
};