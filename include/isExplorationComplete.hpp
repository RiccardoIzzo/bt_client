#include "behaviortree_ros2/bt_action_node.hpp"
#include <chrono>
#include <cstdlib> 

#define NUM_LOCATIONS 2

using namespace BT;
using namespace std::chrono;

// Definition of the isExplorationComplete class inheriting from SyncActionNode, it checks if the exploration is complete
class isExplorationComplete : public SyncActionNode {
public:
    isExplorationComplete(const std::string& name, const NodeConfig& config);
    static PortsList providedPorts();
    NodeStatus tick() override;
private:
};