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

#ifndef _ESKY_CPP_CONTEXT_H_
#define _ESKY_CPP_CONTEXT_H_

#include "function.h"

typedef struct ESKY_CPP_GLOBAL_CONTEXT_STRUCT
{
  struct ESKY_CPP_GLOBAL_VARIABLE_DECLARATION_STRUCT **globales;
  struct ESKY_CPP_CLASS_DECLARATION_STRUCT **classes;
  struct ESKY_CPP_FUNCTION_DECLARATION_STRUCT **functions;
} EskyCppGlobalContext_T;

/// Allocate C++ global context struct on heap, initialize default values
/// \param   globales         declarated global variables
/// \param   classes          declarated classes
/// \param   functions        declarated functions
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppGlobalContext_T *init_esky_cpp_global_context(struct ESKY_CPP_GLOBAL_VARIABLE_DECLARATION_STRUCT **globales,
                                                     struct ESKY_CPP_CLASS_DECLARATION_STRUCT **classes,
                                                     struct ESKY_CPP_FUNCTION_DECLARATION_STRUCT **functions);

// Allocate C++ global context struct on heap, initialize empty values
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppGlobalContext_T *init_empty_esky_cpp_global_context();

/// \param   global_context    global context
/// \return  amount of declarated global variables in the global context
size_t amount_of_global_variables_in_esky_cpp_global_context(EskyCppGlobalContext_T *global_context);

/// \param   global_context    global context
/// \return  amount of declarated classes in the global context
size_t amount_of_classes_in_esky_cpp_global_context(EskyCppGlobalContext_T *global_context);

/// \param   global_context    global context
/// \return  amount of declarated functions in the global context
size_t amount_of_functions_in_esky_cpp_global_context(EskyCppGlobalContext_T *global_context);

/// Adds global variable into the global context
/// \param   global_context    global context
/// \param   global_variable   variable declaration, that we need to add to the global context
void add_global_variable_to_esky_cpp_global_context(EskyCppGlobalContext_T *global_context,
                                                    struct ESKY_CPP_GLOBAL_VARIABLE_DECLARATION_STRUCT *global_variable);

/// Adds class into the global context
/// \param   global_context    global context
/// \param   class             class declaration, that we need to add to the global context
void add_class_to_esky_cpp_global_context(EskyCppGlobalContext_T *global_context, struct ESKY_CPP_CLASS_DECLARATION_STRUCT *class);

/// Adds function into the global context
/// \param   global_context    global context
/// \param   function          function declaration, that we need to add to the global context
void add_function_to_esky_cpp_global_context(EskyCppGlobalContext_T *global_context,
                                             struct ESKY_CPP_FUNCTION_DECLARATION_STRUCT *function);

#endif /* _ESKY_CPP_CONTEXT_H_ */