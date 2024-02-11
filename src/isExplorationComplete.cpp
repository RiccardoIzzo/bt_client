#include "isExplorationComplete.hpp"

isExplorationComplete::isExplorationComplete(const std::string& name, 
    const NodeConfig& config)
    : SyncActionNode(name, config)
{
}

// Define the provided input ports for the isExplorationComplete action
PortsList isExplorationComplete::providedPorts()
{
    // location input that identified the goal location
    return{ BT::InputPort<std::string>("location")};
}

// Handle the node's behavior
NodeStatus isExplorationComplete::tick()
{   
    std::string goalLocation;
    getInput("location", goalLocation);

    if(goalLocation != "Parking"){
        std::cout<<"Exploration not complete. Going on ..."<<std::endl;
        return NodeStatus::FAILURE;
    }
    else {
        std::cout<<"Exploration complete! "<<std::endl;
        return NodeStatus::SUCCESS;
    }
}