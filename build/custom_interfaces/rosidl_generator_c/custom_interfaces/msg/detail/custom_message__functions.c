// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/CustomMessage.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/custom_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_interfaces__msg__CustomMessage__init(custom_interfaces__msg__CustomMessage * msg)
{
  if (!msg) {
    return false;
  }
  // cmd_linear_vel
  // cmd_angular_vel
  // x
  // y
  return true;
}

void
custom_interfaces__msg__CustomMessage__fini(custom_interfaces__msg__CustomMessage * msg)
{
  if (!msg) {
    return;
  }
  // cmd_linear_vel
  // cmd_angular_vel
  // x
  // y
}

bool
custom_interfaces__msg__CustomMessage__are_equal(const custom_interfaces__msg__CustomMessage * lhs, const custom_interfaces__msg__CustomMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmd_linear_vel
  if (lhs->cmd_linear_vel != rhs->cmd_linear_vel) {
    return false;
  }
  // cmd_angular_vel
  if (lhs->cmd_angular_vel != rhs->cmd_angular_vel) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__CustomMessage__copy(
  const custom_interfaces__msg__CustomMessage * input,
  custom_interfaces__msg__CustomMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // cmd_linear_vel
  output->cmd_linear_vel = input->cmd_linear_vel;
  // cmd_angular_vel
  output->cmd_angular_vel = input->cmd_angular_vel;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

custom_interfaces__msg__CustomMessage *
custom_interfaces__msg__CustomMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__CustomMessage * msg = (custom_interfaces__msg__CustomMessage *)allocator.allocate(sizeof(custom_interfaces__msg__CustomMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__CustomMessage));
  bool success = custom_interfaces__msg__CustomMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__CustomMessage__destroy(custom_interfaces__msg__CustomMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__CustomMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__CustomMessage__Sequence__init(custom_interfaces__msg__CustomMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__CustomMessage * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__CustomMessage *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__CustomMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__CustomMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__CustomMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__msg__CustomMessage__Sequence__fini(custom_interfaces__msg__CustomMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__msg__CustomMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__msg__CustomMessage__Sequence *
custom_interfaces__msg__CustomMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__CustomMessage__Sequence * array = (custom_interfaces__msg__CustomMessage__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__CustomMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__CustomMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__CustomMessage__Sequence__destroy(custom_interfaces__msg__CustomMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__CustomMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__CustomMessage__Sequence__are_equal(const custom_interfaces__msg__CustomMessage__Sequence * lhs, const custom_interfaces__msg__CustomMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__CustomMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__CustomMessage__Sequence__copy(
  const custom_interfaces__msg__CustomMessage__Sequence * input,
  custom_interfaces__msg__CustomMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__CustomMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__CustomMessage * data =
      (custom_interfaces__msg__CustomMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__CustomMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__CustomMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__CustomMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}