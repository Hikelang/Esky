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

#include "cpp.h"

/// Allocate C++ builder struct on heap, initialize default values
/// \param   output_filename    path to output file
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppBuilder_T *init_esky_cpp_builder(char *output_filename)
{
  EskyCppBuilder_T *builder = malloc(sizeof(struct ESKY_CPP_BUILDER_STRUCT));
  builder->output_filename = output_filename;
  return builder;
}

/// Allocate C++ primary type struct on heap, initialize default values
/// \param   primary_type       primary type
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppType_T *init_esky_cpp_primary_type(EskyCppPrimaryType_T primary_type)
{
  EskyCppType_T *type = malloc(sizeof(struct ESKY_CPP_TYPE_STRUCT));
  type->kind = PRIMARY;
  type->type.primary_type = primary_type;
  return type;
}

/// Allocate C++ pointer type struct on heap, initialize default values
/// \param   type               pointer type
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppType_T *init_esky_cpp_pointer_type(EskyCppType_T *type)
{
  EskyCppType_T *secondary_type = malloc(sizeof(struct ESKY_CPP_TYPE_STRUCT));
  secondary_type->kind = POINTER;
  secondary_type->type.pointer_type = malloc(sizeof(struct ESKY_CPP_POINTER_TYPE_STRUCT));
  secondary_type->type.pointer_type->type = type;
  return secondary_type;
}

/// Allocate C++ array type struct on heap, initialize default values
/// \param   type               array type
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppType_T *init_esky_cpp_array_type(EskyCppType_T *type)
{
  EskyCppType_T *secondary_type = malloc(sizeof(struct ESKY_CPP_TYPE_STRUCT));
  secondary_type->kind = ARRAY;
  secondary_type->type.array_type = malloc(sizeof(struct ESKY_CPP_ARRAY_TYPE_STRUCT));
  secondary_type->type.array_type->type = type;
  return secondary_type;
}

/// Allocate C++ scalar declaration struct on heap, initialize default values
/// \param   name               argument's name
/// \param   type               argument's type
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppScalarDeclaration_T *init_esky_cpp_scalar_declaration(char *name, EskyCppType_T *type)
{
  EskyCppScalarDeclaration_T *scalar_declaration = malloc(sizeof(struct ESKY_CPP_SCALAR_DECLARATION_STRUCT));
  scalar_declaration->name = name;
  scalar_declaration->type = type;
  return scalar_declaration;
}

/// Allocate C++ function declaration struct on heap, initialize default values
/// \param   return_type        function's return type
/// \param   namespace          name's namespace
/// \param   name               function's name
/// \param   arguments          function's arguments
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppFunctionDeclaration_T *init_esky_cpp_function_declaration(EskyCppType_T *return_type, char *namespace, char *name, EskyCppScalarDeclaration_T **arguments)
{
  EskyCppFunctionDeclaration_T *function_declaration = malloc(sizeof(struct ESKY_CPP_FUNCTION_DECLARATION_STRUCT));
  function_declaration->return_type = return_type;
  function_declaration->namespace = namespace;
  function_declaration->arguments = arguments;
  function_declaration->name = name;
  return function_declaration;
}

/// Allocate C++ function implementation struct on heap, initialize default values
/// \param   declaration        function's declaration structure
/// \param   implementation     code block (list of statements)
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppFunctionImplementation_T *init_esky_cpp_function_implementation(EskyCppFunctionDeclaration_T *declaration, EskyCppStatement_T **implementation)
{
  EskyCppFunctionImplementation_T *function_implementation = malloc(sizeof(struct ESKY_CPP_FUNCTION_IMPLEMENTATION_STRUCT));
  function_implementation->declaration = declaration;
  function_implementation->implementation = implementation;
  return function_implementation;
}

/// Allocate C++ class declaration struct on heap, initialize default values
/// \param   namespace          name's namespace
/// \param   class_name         class' name
/// \param   inherits           does class inherit
/// \param   extends            what class it extends from
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppClassDeclaration_T *init_esky_cpp_class_declaration(char *namespace, char *name, bool inherits, EskyCppClassDeclaration_T *extends)
{
  EskyCppClassDeclaration_T *class_declaration = malloc(sizeof(struct ESKY_CPP_CLASS_DECLARATION_STRUCT));
  class_declaration->namespace = namespace;
  class_declaration->name = name;
  class_declaration->inherits = inherits;
  class_declaration->extends = extends;
  return class_declaration;
}

/// \param   type               Esky type structure
/// \return  emitted C++ type
char *esky_cpp_emit_type(EskyCppType_T *type)
{
  switch (type->kind)
  {
  case PRIMARY:
    return esky_cpp_emit_primary_type(type->type.primary_type);
  case ARRAY:
    return esky_cpp_emit_array_type(type->type.array_type);
  case POINTER:
    return esky_cpp_emit_pointer_type(type->type.pointer_type);
  default:
    return "\0";
  }
}

/// \param   type               Esky primary type structure
/// \return  emitted C++ type
char *esky_cpp_emit_primary_type(EskyCppPrimaryType_T type)
{
  switch (type)
  {
  case VOID_TYPE:
    return "void";
  case CHAR_TYPE:
    return "char";
  case INT8_TYPE:
    return "int8_t";
  case INT16_TYPE:
    return "int16_t";
  case INT32_TYPE:
    return "int32_t";
  case INT64_TYPE:
    return "int64_t";
  case FLOAT_TYPE:
    return "float";
  case DOUBLE_TYPE:
    return "double";
  default:
    return "\0";
  }
}

/// \param   type               Esky pointer type structure
/// \return  emitted C++ type
char *esky_cpp_emit_pointer_type(EskyCppPointerType_T *type)
{
  char *str;
  asprintf(&str, "%s*", esky_cpp_emit_type(type->type));
  return str;
}

/// \param   type               Esky array type structure
/// \return  emitted C++ type
char *esky_cpp_emit_array_type(EskyCppArrayType_T *type)
{
  char *str;
  asprintf(&str, "%s[]", esky_cpp_emit_type(type->type));
  return str;
}