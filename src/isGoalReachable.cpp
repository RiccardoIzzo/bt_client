#include "isGoalReachable.hpp"

isGoalReachable::isGoalReachable(const std::string& name, 
    const NodeConfig& config)
    : StatefulActionNode(name, config)
{
}

// Define the provided input ports for the isGoalReachable action
PortsList isGoalReachable::providedPorts()
{
    // prob input identify the probability of a goal pose to be reachable
    return{ BT::InputPort<float>("prob") };
}

// Handle the node's behavior when it starts its execution
NodeStatus isGoalReachable::onStart()
{   
    // Declare a variable to store the probability input
    float prob;
    getInput("prob", prob);
    
    // Mock to check if the goal is reachable or not given the initial probability
    isReachable = (rand() % 100) <= (int) prob * 100;

    // Set a deadline for the execution based on the current time and delay
    deadline = system_clock::now() + seconds(DELAY);
    return NodeStatus::RUNNING;
}

// Handle the node's behavior while it is running
NodeStatus isGoalReachable::onRunning()
{   
    // Check if the current time has exceeded the deadline
    if (system_clock::now() >= deadline) {
        // Check if the goal is reachable
        if(isReachable){
            std::cout << "The goal is reachable!" << std::endl;
            return NodeStatus::SUCCESS;
        }
        else{
            std::cout << "The goal is not reachable! Skipping to the next action..." << std::endl;
            return NodeStatus::FAILURE;
        }
    }
    else {
        return NodeStatus::RUNNING;
    }
}

// Handle any feedback during the execution of the node
void isGoalReachable::onHalted()
{
    // No specific actions defined for feedback during the execution halt
}