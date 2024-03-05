#include "FollowAruco.hpp"

FollowAruco::FollowAruco(const std::string& name,
    const NodeConfig& conf,
    const RosNodeParams& params)
    : RosActionNode<Aruco>(name, conf, params)
{
    client = params.nh;
}

// Define the provided input ports for the FollowAruco action
PortsList FollowAruco::providedPorts()
{
    return{ BT::InputPort<int>("id")};
}

// Set the goal for the FollowAruco action based on aruco id
bool FollowAruco::setGoal(RosActionNode::Goal &goal)
{
    float id;
    getInput("id", id);

    goal.aruco_id = id;

    return true;
}

// Handle the result received after executing the FollowAruco action
NodeStatus FollowAruco::onResultReceived(const RosActionNode::WrappedResult &wr)
{   
    RCLCPP_INFO(client->get_logger(), "Goal reached\n");
    return NodeStatus::SUCCESS;
}

// Handle failure cases for the FollowAruco action
NodeStatus FollowAruco::onFailure(ActionNodeErrorCode error)
{   
    RCLCPP_ERROR(node_->get_logger(), "Error: %d", error);
    return NodeStatus::FAILURE;
}

// Handle feedback during the execution of the FollowAruco action
NodeStatus FollowAruco::onFeedback(const std::shared_ptr<const Feedback> feedback)
{
    return NodeStatus::RUNNING;
}