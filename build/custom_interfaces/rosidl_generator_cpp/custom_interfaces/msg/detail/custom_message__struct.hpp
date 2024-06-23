// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/CustomMessage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__CustomMessage __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__CustomMessage __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CustomMessage_
{
  using Type = CustomMessage_<ContainerAllocator>;

  explicit CustomMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_linear_vel = 0.0f;
      this->cmd_angular_vel = 0.0f;
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  explicit CustomMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_linear_vel = 0.0f;
      this->cmd_angular_vel = 0.0f;
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  // field types and members
  using _cmd_linear_vel_type =
    float;
  _cmd_linear_vel_type cmd_linear_vel;
  using _cmd_angular_vel_type =
    float;
  _cmd_angular_vel_type cmd_angular_vel;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;

  // setters for named parameter idiom
  Type & set__cmd_linear_vel(
    const float & _arg)
  {
    this->cmd_linear_vel = _arg;
    return *this;
  }
  Type & set__cmd_angular_vel(
    const float & _arg)
  {
    this->cmd_angular_vel = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::CustomMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::CustomMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::CustomMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::CustomMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::CustomMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::CustomMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::CustomMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::CustomMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::CustomMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::CustomMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__CustomMessage
    std::shared_ptr<custom_interfaces::msg::CustomMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__CustomMessage
    std::shared_ptr<custom_interfaces::msg::CustomMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CustomMessage_ & other) const
  {
    if (this->cmd_linear_vel != other.cmd_linear_vel) {
      return false;
    }
    if (this->cmd_angular_vel != other.cmd_angular_vel) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const CustomMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CustomMessage_

// alias to use template instance with default allocator
using CustomMessage =
  custom_interfaces::msg::CustomMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__STRUCT_HPP_
