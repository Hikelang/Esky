/**
 * Copyright 2022 Salimgereyev Adi
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _ESKY_TARGET_CPP_H_
#define _ESKY_TARGET_CPP_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

typedef struct ESKY_CPP_STATEMENT_STRUCT
{

} EskyCppStatement_T;

typedef struct ESKY_CPP_SCALAR_DECLARATION_STRUCT
{
  char *name;
  EskyCppType_T *type;
} EskyCppScalarDeclaration_T;

typedef struct ESKY_CPP_FUNCTION_DECLARATION_STRUCT
{
  EskyCppType_T *return_type;

  char *namespace;
  char *name;

  EskyCppScalarDeclaration_T **arguments;
} EskyCppFunctionDeclaration_T;

typedef struct ESKY_CPP_FUNCTION_IMPLEMENTATION_STRUCT
{
  EskyCppFunctionDeclaration_T *declaration;
  EskyCppStatement_T **implementation;
} EskyCppFunctionImplementation_T;

typedef struct ESKY_CPP_CLASS_DECLARATION_STRUCT
{
  char *namespace;
  char *name;

  bool inherits;
  struct ESKY_CPP_CLASS_DECLARATION_STRUCT *extends;

  EskyCppFunctionDeclaration_T **function_declarations;
} EskyCppClassDeclaration_T;

typedef struct ESKY_CPP_CLASS_IMPLEMENTATION_STRUCT
{
  EskyCppFunctionImplementation_T **function_implementations;
} EskyCppClassImplementation_T;

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

/// Allocate C++ scalar declaration struct on heap, initialize default values
/// \param   name               argument's name
/// \param   type               argument's type
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppScalarDeclaration_T *init_esky_cpp_scalar_declaration(char *name, EskyCppType_T *type);

/// Allocate C++ function declaration struct on heap, initialize default values
/// \param   return_type        function's return type
/// \param   namespace          name's namespace
/// \param   name               function's name
/// \param   arguments          function's arguments
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppFunctionDeclaration_T *init_esky_cpp_function_declaration(EskyCppType_T *return_type, char *namespace, char *name, EskyCppScalarDeclaration_T **arguments);

/// Allocate C++ function implementation struct on heap, initialize default values
/// \param   declaration        function's declaration structure
/// \param   implementation     code block (list of statements)
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppFunctionImplementation_T *init_esky_cpp_function_implementation(EskyCppFunctionDeclaration_T *declaration, EskyCppStatement_T **implementation);

/// Allocate C++ class declaration struct on heap, initialize default values
/// \param   namespace          name's namespace
/// \param   name               class' name
/// \param   inherits           does class inherit
/// \param   extends            what class it extends from
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppClassDeclaration_T *init_esky_cpp_class_declaration(char *namespace, char *class_name, bool inherits, EskyCppClassDeclaration_T *extends);

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