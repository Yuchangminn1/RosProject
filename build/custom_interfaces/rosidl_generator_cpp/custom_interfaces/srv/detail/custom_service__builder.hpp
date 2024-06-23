// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/CustomService.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__CUSTOM_SERVICE__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__CUSTOM_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/custom_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_CustomService_Request_robot_id
{
public:
  Init_CustomService_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::CustomService_Request robot_id(::custom_interfaces::srv::CustomService_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::CustomService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::CustomService_Request>()
{
  return custom_interfaces::srv::builder::Init_CustomService_Request_robot_id();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_CustomService_Response_theta
{
public:
  explicit Init_CustomService_Response_theta(::custom_interfaces::srv::CustomService_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::CustomService_Response theta(::custom_interfaces::srv::CustomService_Response::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::CustomService_Response msg_;
};

class Init_CustomService_Response_y
{
public:
  explicit Init_CustomService_Response_y(::custom_interfaces::srv::CustomService_Response & msg)
  : msg_(msg)
  {}
  Init_CustomService_Response_theta y(::custom_interfaces::srv::CustomService_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_CustomService_Response_theta(msg_);
  }

private:
  ::custom_interfaces::srv::CustomService_Response msg_;
};

class Init_CustomService_Response_x
{
public:
  Init_CustomService_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CustomService_Response_y x(::custom_interfaces::srv::CustomService_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_CustomService_Response_y(msg_);
  }

private:
  ::custom_interfaces::srv::CustomService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::CustomService_Response>()
{
  return custom_interfaces::srv::builder::Init_CustomService_Response_x();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__CUSTOM_SERVICE__BUILDER_HPP_
