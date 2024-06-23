// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/CustomMessage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/custom_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CustomMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd_linear_vel
  {
    out << "cmd_linear_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_linear_vel, out);
    out << ", ";
  }

  // member: cmd_angular_vel
  {
    out << "cmd_angular_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_angular_vel, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CustomMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd_linear_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_linear_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_linear_vel, out);
    out << "\n";
  }

  // member: cmd_angular_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_angular_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_angular_vel, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CustomMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::CustomMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::CustomMessage & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::CustomMessage>()
{
  return "custom_interfaces::msg::CustomMessage";
}

template<>
inline const char * name<custom_interfaces::msg::CustomMessage>()
{
  return "custom_interfaces/msg/CustomMessage";
}

template<>
struct has_fixed_size<custom_interfaces::msg::CustomMessage>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::msg::CustomMessage>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::msg::CustomMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__TRAITS_HPP_
