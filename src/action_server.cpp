#include <memory>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "sandbox_actions/action/Navigate.hpp"

class NavigateActionServer : public rclcpp::Node
{
    public:
        using Navigate = sandbox_actions::action::Navigate;
        using GoalHandleNavigate = rclcpp::actions::ServerGoalHandle<Navigate>;

        // Initalize the node with the name "navigate_action_server"
        explicit NavigateActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions()) : Node("navigate_action_server", options)
        {
            // Time to create the actual action server!
            this -> action_server = rclcpp_action::create_server<Navigate>
            (
                this,    // The node that the server applies to
                "navigate", // The name of the action/service
                
            );
        }


    private:

}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<NavigateActionServer>);
    rclcpp::shutdown();
    return EXIT_SUCCESS;
}