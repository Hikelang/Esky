// Part of the Esky, under the Apache License v2.0.
// See https://github.com/hikelang/esky/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0

#include "cpp.h"

EskyCppBuilder_T *init_esky_cpp_builder(char *output_filename)
{
}

EskyCppType_T *init_esky_cpp_primary_type(EskyCppPrimaryType_T primary_type)
{
  EskyCppType_T *type = malloc(sizeof(struct ESKY_CPP_TYPE_STRUCT));
  type->kind = PRIMARY;
  type->type.primary_type = primary_type;
  return type;
}

EskyCppType_T *init_esky_cpp_pointer_type(EskyCppType_T *type)
{
  EskyCppType_T *secondary_type = malloc(sizeof(struct ESKY_CPP_TYPE_STRUCT));
  secondary_type->kind = POINTER;
  secondary_type->type.pointer_type = malloc(sizeof(struct ESKY_CPP_POINTER_TYPE_STRUCT));
  secondary_type->type.pointer_type->type = type;
  return secondary_type;
}

EskyCppType_T *init_esky_cpp_array_type(EskyCppType_T *type)
{
  EskyCppType_T *secondary_type = malloc(sizeof(struct ESKY_CPP_TYPE_STRUCT));
  secondary_type->kind = ARRAY;
  secondary_type->type.array_type = malloc(sizeof(struct ESKY_CPP_ARRAY_TYPE_STRUCT));
  secondary_type->type.array_type->type = type;
  return secondary_type;
}