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

#ifndef _ESKY_CPP_STATEMENT_H_
#define _ESKY_CPP_STATEMENT_H_

#include "type.h"
#include "value.h"
#include "function.h"
#include "class.h"

typedef enum ESKY_CPP_PREPROCESSOR_STATEMENT_KIND
{
  DEFINE,
  INCLUDE,
  IF,
  IFDEF,
  IFNDEF,
  ENDIF
} EskyCppPreprocessorStatementKind_T;

typedef enum ESKY_CPP_TOP_STATEMENT_KIND
{
  GLOBAL_VARIABLE_DECLARATION,
  FUNCTION_DECLARATION,
  FUNCTION_IMPLEMENTATION,
  CLASS_DECLARATION,
  CLASS_IMPLEMENTATION,
} EskyCppTopStatementKind_T;

typedef enum ESKY_CPP_STATEMENT_KIND
{
  VARIABLE_DECLARATION,
  IF_STATEMENT,
  WHILE_STATEMENT,
  FOR_STATEMENT,
  VALUE,
} EskyCppStatementKind_T;

typedef struct ESKY_CPP_PREPROCESSOR_STATEMENT_STRUCT
{
  EskyCppPreprocessorStatementKind_T kind;
  union
  {

  } arguments;
} EskyCppPreprocessorStatement_T;

typedef struct ESKY_CPP_GLOBAL_VARIABLE_DECLARATION_STRUCT
{
  bool is_static;
  bool is_const;

  struct ESKY_CPP_TYPE_STRUCT *type;

  bool has_value;
  EskyCppValue_T *value;
} EskyCppGlobalVariableDeclaration_T;

typedef struct ESKY_CPP_TOP_STATEMENT_STRUCT
{
  EskyCppTopStatementKind_T kind;

  union
  {
    EskyCppGlobalVariableDeclaration_T *global_variable_declaration;
    struct ESKY_CPP_FUNCTION_DECLARATION_STRUCT *function_declaration;
    struct ESKY_CPP_FUNCTION_IMPLEMENTATION_STRUCT *function_implementation;
    struct ESKY_CPP_CLASS_DECLARATION_STRUCT *class_declaration;
    struct ESKY_CPP_CLASS_IMPLEMENTATION_STRUCT *class_implementation;
  } statement;
} EskyCppTopStatement_T;

typedef struct ESKY_CPP_STATEMENT_STRUCT
{
  EskyCppStatementKind_T kind;
} EskyCppStatement_T;

// EskyCppPreprocessorStatement_T *init_esky_cpp_define_preprocessor_statement(char *macro_name, EskyCppValue_T *value);
// EskyCppPreprocessorStatement_T *init_esky_cpp_include_preprocessor_statement(char *header_filename);
// EskyCppPreprocessorStatement_T *init_esky_cpp_ifdef_preprocessor_statement(EskyCppValue_T *condition);
// EskyCppPreprocessorStatement_T *init_esky_cpp_ifndef_preprocessor_statement(EskyCppValue_T *condition);
// EskyCppPreprocessorStatement_T *init_esky_cpp_endif_preprocessor_statement();

/// Allocate C++ global variable declaration struct on heap, initialize default values
/// \param   is_static                      true if variable is static (static int a;)
/// \param   is_const                       true if variable is constant (const int a;)
/// \param   type                           variable type
/// \param   has_value                      true if variable stores some value (int a; - false, int a = 3; - true)
/// \param   value                          variable value
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppGlobalVariableDeclaration_T *init_esky_cpp_global_variable_declaration(bool is_static, bool is_const, struct ESKY_CPP_TYPE_STRUCT *type, bool has_value, EskyCppValue_T *value);

/// Allocate C++ top statement struct on heap, initialize default values
/// \param   global_variable_declaration    global variable declaration
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppTopStatement_T *init_esky_cpp_top_statement_with_global_variable_declaration(EskyCppGlobalVariableDeclaration_T *global_variable_declaration);

/// Allocate C++ top statement struct on heap, initialize default values
/// \param   function_declaration           function declaration
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppTopStatement_T *init_esky_cpp_top_statement_with_function_declaration(struct ESKY_CPP_FUNCTION_DECLARATION_STRUCT *function_declaration);

/// Allocate C++ top statement struct on heap, initialize default values
/// \param   function_implementation        function implementation
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppTopStatement_T *init_esky_cpp_top_statement_with_function_implementation(struct ESKY_CPP_FUNCTION_IMPLEMENTATION_STRUCT *function_implementation);

/// Allocate C++ top statement struct on heap, initialize default values
/// \param   class_declaration              class declaration
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppTopStatement_T *init_esky_cpp_top_statement_with_class_declaration(struct ESKY_CPP_CLASS_DECLARATION_STRUCT *class_declaration);

/// Allocate C++ top statement struct on heap, initialize default values
/// \param   class_implementation           class implementation
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppTopStatement_T *init_esky_cpp_top_statement_with_class_implementation(struct ESKY_CPP_CLASS_IMPLEMENTATION_STRUCT *class_implementation);

#endif /* _ESKY_CPP_STATEMENT_H_ */