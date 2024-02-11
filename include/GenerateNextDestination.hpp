#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "behaviortree_ros2/plugins.hpp"
#include "behaviortree_ros2/bt_action_node.hpp"

#include <chrono>
#include <cstdlib> 
#include <vector>
#include <algorithm>

using namespace BT;
using namespace std::chrono;

// Definition of the GenerateNextDestination class inheriting from SyncActionNode, it generates a new destination in order to explore the environment
class GenerateNextDestination : public SyncActionNode {
public:
    GenerateNextDestination(const std::string& name, const NodeConfig& config);
    static PortsList providedPorts();
    NodeStatus tick() override;
private:
};