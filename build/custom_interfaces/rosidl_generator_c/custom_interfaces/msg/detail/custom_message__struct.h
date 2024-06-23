// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/CustomMessage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/CustomMessage in the package custom_interfaces.
/**
  * 로봇의 선형, 각 속도 pub
 */
typedef struct custom_interfaces__msg__CustomMessage
{
  float cmd_linear_vel;
  float cmd_angular_vel;
  /// 로봇의 현재 위치 sub
  float x;
  float y;
} custom_interfaces__msg__CustomMessage;

// Struct for a sequence of custom_interfaces__msg__CustomMessage.
typedef struct custom_interfaces__msg__CustomMessage__Sequence
{
  custom_interfaces__msg__CustomMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__CustomMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__CUSTOM_MESSAGE__STRUCT_H_
