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

#ifndef _ESKY_CPP_FUNCTION_H_
#define _ESKY_CPP_FUNCTION_H_

#include "type.h"
#include "statement.h"

typedef struct ESKY_CPP_SCALAR_DECLARATION_STRUCT
{
  char *name;
  struct ESKY_CPP_TYPE_STRUCT *type;
} EskyCppScalarDeclaration_T;

typedef struct ESKY_CPP_FUNCTION_DECLARATION_STRUCT
{
  struct ESKY_CPP_TYPE_STRUCT *return_type;

  char *namespace;
  char *name;

  EskyCppScalarDeclaration_T **arguments;
} EskyCppFunctionDeclaration_T;

typedef struct ESKY_CPP_FUNCTION_IMPLEMENTATION_STRUCT
{
  EskyCppFunctionDeclaration_T *declaration;
  EskyCppStatement_T **implementation;
} EskyCppFunctionImplementation_T;

/// Allocate C++ scalar declaration struct on heap, initialize default values
/// \param   name               argument's name
/// \param   type               argument's type
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppScalarDeclaration_T *init_esky_cpp_scalar_declaration(char *name, struct ESKY_CPP_TYPE_STRUCT *type);

/// Allocate C++ function declaration struct on heap, initialize default values
/// \param   return_type        function's return type
/// \param   namespace          name's namespace
/// \param   name               function's name
/// \param   arguments          function's arguments
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppFunctionDeclaration_T *init_esky_cpp_function_declaration(struct ESKY_CPP_TYPE_STRUCT *return_type, char *namespace, char *name, EskyCppScalarDeclaration_T **arguments);

/// Allocate C++ function implementation struct on heap, initialize default values
/// \param   declaration        function's declaration structure
/// \param   implementation     code block (list of statements)
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppFunctionImplementation_T *init_esky_cpp_function_implementation(EskyCppFunctionDeclaration_T *declaration, EskyCppStatement_T **implementation);

#endif /* _ESKY_CPP_FUNCTION_H_ */