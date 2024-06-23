// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/CustomMessage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/custom_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_CustomMessage_y
{
public:
  explicit Init_CustomMessage_y(::custom_interfaces::msg::CustomMessage & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::CustomMessage y(::custom_interfaces::msg::CustomMessage::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::CustomMessage msg_;
};

class Init_CustomMessage_x
{
public:
  explicit Init_CustomMessage_x(::custom_interfaces::msg::CustomMessage & msg)
  : msg_(msg)
  {}
  Init_CustomMessage_y x(::custom_interfaces::msg::CustomMessage::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_CustomMessage_y(msg_);
  }

private:
  ::custom_interfaces::msg::CustomMessage msg_;
};

class Init_CustomMessage_cmd_angular_vel
{
public:
  explicit Init_CustomMessage_cmd_angular_vel(::custom_interfaces::msg::CustomMessage & msg)
  : msg_(msg)
  {}
  Init_CustomMessage_x cmd_angular_vel(::custom_interfaces::msg::CustomMessage::_cmd_angular_vel_type arg)
  {
    msg_.cmd_angular_vel = std::move(arg);
    return Init_CustomMessage_x(msg_);
  }

private:
  ::custom_interfaces::msg::CustomMessage msg_;
};

class Init_CustomMessage_cmd_linear_vel
{
public:
  Init_CustomMessage_cmd_linear_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CustomMessage_cmd_angular_vel cmd_linear_vel(::custom_interfaces::msg::CustomMessage::_cmd_linear_vel_type arg)
  {
    msg_.cmd_linear_vel = std::move(arg);
    return Init_CustomMessage_cmd_angular_vel(msg_);
  }

private:
  ::custom_interfaces::msg::CustomMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::CustomMessage>()
{
  return custom_interfaces::msg::builder::Init_CustomMessage_cmd_linear_vel();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__BUILDER_HPP_
