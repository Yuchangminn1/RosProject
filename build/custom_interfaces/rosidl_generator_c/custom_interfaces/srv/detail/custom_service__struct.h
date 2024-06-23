// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/CustomService.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__CUSTOM_SERVICE__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__CUSTOM_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CustomService in the package custom_interfaces.
typedef struct custom_interfaces__srv__CustomService_Request
{
  int32_t robot_id;
} custom_interfaces__srv__CustomService_Request;

// Struct for a sequence of custom_interfaces__srv__CustomService_Request.
typedef struct custom_interfaces__srv__CustomService_Request__Sequence
{
  custom_interfaces__srv__CustomService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__CustomService_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/CustomService in the package custom_interfaces.
typedef struct custom_interfaces__srv__CustomService_Response
{
  double x;
  double y;
  double theta;
} custom_interfaces__srv__CustomService_Response;

// Struct for a sequence of custom_interfaces__srv__CustomService_Response.
typedef struct custom_interfaces__srv__CustomService_Response__Sequence
{
  custom_interfaces__srv__CustomService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__CustomService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__CUSTOM_SERVICE__STRUCT_H_
