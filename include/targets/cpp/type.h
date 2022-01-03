/**
 *  Copyright 2022 Salimgereev Adi
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef _ESKY_TARGET_CPP_H_
#define _ESKY_TARGET_CPP_H_

#define ESKY_CPP_EMITTED_TYPE_MAX_BUFFER_SIZE (int)(1e6)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "class.h"

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

  char **imports;
} EskyCppBuilder_T;

/// Allocate C++ builder struct on heap, initialize default values
/// \param   output_filename    path to output file
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppBuilder_T *init_esky_cpp_builder(char *output_filename);

/// Allocate C++ primary type struct on heap, initialize default values
/// \param   primary_type       primary type
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppType_T *init_esky_cpp_primary_type(EskyCppPrimaryType_T primary_type);

/// Allocate C++ pointer type struct on heap, initialize default values
/// \param   type               pointer type
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppType_T *init_esky_cpp_pointer_type(EskyCppType_T *type);

/// Allocate C++ array type struct on heap, initialize default values
/// \param   type               array type
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppType_T *init_esky_cpp_array_type(EskyCppType_T *type);

/// \param   type               Esky type structure
/// \return  emitted C++ type
char *esky_cpp_emit_type(EskyCppType_T *type);

/// \param   type               Esky primary type structure
/// \return  emitted C++ type
char *esky_cpp_emit_primary_type(EskyCppPrimaryType_T type);

/// \param   type               Esky pointer type structure
/// \return  emitted C++ type
char *esky_cpp_emit_pointer_type(EskyCppPointerType_T *type);

/// \param   type               Esky array type structure
/// \return  emitted C++ type
char *esky_cpp_emit_array_type(EskyCppArrayType_T *type);

#endif /* _ESKY_TARGET_CPP_H_ */