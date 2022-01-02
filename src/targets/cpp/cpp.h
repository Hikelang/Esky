// Part of the Esky, under the Apache License v2.0.
// See https://github.com/hikelang/esky/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0

#ifndef _ESKY_TARGET_CPP_H_
#define _ESKY_TARGET_CPP_H_

typedef enum
{
  PRIMARY,
  POINTER,
  ARRAY
} EskyCppTypeKind_T;

typedef enum
{
  VOID_TYPE,
  CHAR_TYPE,
  INT8_TYPE,
  INT16_TYPE,
  INT32_TYPE,
  INT64_TYPE,
  INT128_TYPE,
  FLOAT_TYPE,
  DOUBLE_TYPE,
} EskyCppPrimaryType_T;

typedef struct ESKY_CPP_ARRAY_TYPE_STRUCT
{
  struct ESKY_CPP_TYPE_STRUCT *type;
} EskyCppArrayType_T;

typedef struct ESKY_CPP_POINTER_TYPE_STRUCT
{
  struct ESKY_CPP_TYPE_STRUCT *type;
} EskyCppPointerType_T;

typedef struct ESKY_CPP_TYPE_STRUCT
{
  EskyCppTypeKind_T kind;
  union
  {
    EskyCppPrimaryType_T primary_type;
    EskyCppPointerType_T *pointer_type;
    EskyCppArrayType_T *array_type;
  } type;
} EskyCppType_T;

typedef struct ESKY_CPP_BUILDER_STRUCT
{
  char *output_filename;
} EskyCppBuilder_T;

EskyCppBuilder_T *init_esky_cpp_builder(char *output_filename);
EskyCppType_T *init_esky_cpp_primary_type(EskyCppPrimaryType_T primary_type);
EskyCppType_T *init_esky_cpp_pointer_type(EskyCppType_T *type);
EskyCppType_T *init_esky_cpp_array_type(EskyCppType_T *type);

#endif /* _ESKY_TARGET_CPP_H_ */