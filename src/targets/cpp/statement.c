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

#include "../../../include/targets/cpp/statement.h"

/// Allocate C++ global variable declaration struct on heap, initialize default values
/// \param   is_static                      true if variable is static (static int a;)
/// \param   is_const                       true if variable is constant (const int a;)
/// \param   type                           variable type
/// \param   has_value                      true if variable stores some value (int a; - false, int a = 3; - true)
/// \param   value                          variable value
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppGlobalVariableDeclaration_T *init_esky_cpp_global_variable_declaration(bool is_static, bool is_const, EskyCppType_T *type, bool has_value, EskyCppValue_T *value)
{
  EskyCppGlobalVariableDeclaration_T *global_variable_declaration = malloc(sizeof(struct ESKY_CPP_GLOBAL_VARIABLE_DECLARATION_STRUCT));
  global_variable_declaration->is_static = is_static;
  global_variable_declaration->is_const = is_const;
  global_variable_declaration->type = type;
  global_variable_declaration->has_value = has_value;
  if (has_value)
    global_variable_declaration->value = value;
  else
    global_variable_declaration->value = (void *)0;
  return global_variable_declaration;
}

/// Allocate C++ top statement struct on heap, initialize default values
/// \param   global_variable_declaration    global variable declaration
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppTopStatement_T *init_esky_cpp_top_statement_with_global_variable_declaration(EskyCppGlobalVariableDeclaration_T *global_variable_declaration)
{
  EskyCppTopStatement_T *top_statement = malloc(sizeof(struct ESKY_CPP_TOP_STATEMENT_STRUCT));
  top_statement->kind = GLOBAL_VARIABLE_DECLARATION;
  top_statement->statement.global_variable_declaration = global_variable_declaration;
  return top_statement;
}

/// Allocate C++ top statement struct on heap, initialize default values
/// \param   function_declaration           function declaration
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppTopStatement_T *init_esky_cpp_top_statement_with_function_declaration(EskyCppFunctionDeclaration_T *function_declaration)
{
  EskyCppTopStatement_T *top_statement = malloc(sizeof(struct ESKY_CPP_TOP_STATEMENT_STRUCT));
  top_statement->kind = FUNCTION_DECLARATION;
  top_statement->statement.function_declaration = function_declaration;
  return top_statement;
}

/// Allocate C++ top statement struct on heap, initialize default values
/// \param   function_implementation        function implementation
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppTopStatement_T *init_esky_cpp_top_statement_with_function_implementation(EskyCppFunctionImplementation_T *function_implementation)
{
  EskyCppTopStatement_T *top_statement = malloc(sizeof(struct ESKY_CPP_TOP_STATEMENT_STRUCT));
  top_statement->kind = FUNCTION_IMPLEMENTATION;
  top_statement->statement.function_implementation = function_implementation;
  return top_statement;
}

/// Allocate C++ top statement struct on heap, initialize default values
/// \param   class_declaration              class declaration
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppTopStatement_T *init_esky_cpp_top_statement_with_class_declaration(EskyCppClassDeclaration_T *class_declaration)
{
  EskyCppTopStatement_T *top_statement = malloc(sizeof(struct ESKY_CPP_TOP_STATEMENT_STRUCT));
  top_statement->kind = CLASS_DECLARATION;
  top_statement->statement.class_declaration = class_declaration;
  return top_statement;
}

/// Allocate C++ top statement struct on heap, initialize default values
/// \param   class_implementation           class implementation
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppTopStatement_T *init_esky_cpp_top_statement_with_class_implementation(EskyCppClassImplementation_T *class_implementation)
{
  EskyCppTopStatement_T *top_statement = malloc(sizeof(struct ESKY_CPP_TOP_STATEMENT_STRUCT));
  top_statement->kind = CLASS_IMPLEMENTATION;
  top_statement->statement.class_implementation = class_implementation;
  return top_statement;
}