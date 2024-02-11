#include "MoveTo.hpp"
#include "MoveToWithTimeout.hpp"
#include "isGoalReachable.hpp"
#include "GenerateNextDestination.hpp"
#include "isExplorationComplete.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"

// Define the directory for behavior tree XML files
const std::string bt_xml_dir =
    ament_index_cpp::get_package_share_directory("bt_client") + "/bt_xml";

// Select here the behavior tree
const std::string tree_xml = "/explore_environment.xml";

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    BehaviorTreeFactory factory;

    auto node = std::make_shared<rclcpp::Node>("bt_client_node");
	// Declare a parameter for the location file with a default value of "none"
    node->declare_parameter("location_file","none");

    RosNodeParams params; 
    params.nh = node;
    params.default_port_value = "/navigate_to_pose";

    // Register the custom MoveTo node type with the BehaviorTreeFactory
    factory.registerNodeType<MoveTo>("MoveTo", params);

    // Register the custom MoveToWithTimeout node type with the BehaviorTreeFactory
    factory.registerNodeType<MoveToWithTimeout>("MoveToWithTimeout", params);

    // Register the custom isGoalReachable node type with the BehaviorTreeFactory
    factory.registerNodeType<isGoalReachable>("isGoalReachable");

    // Register the custom GenerateNextDestination node type with the BehaviorTreeFactory
    factory.registerNodeType<GenerateNextDestination>("GenerateNextDestination");

    // Register the custom GenerateNextDestination node type with the BehaviorTreeFactory
    factory.registerNodeType<isExplorationComplete>("isExplorationComplete");

    // Create a behavior tree from an XML file located in the specified directory
    auto tree = factory.createTreeFromFile(bt_xml_dir + tree_xml);

    // Execute the behavior tree and tick while it is running
    tree.tickWhileRunning();

    return 0;
}