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

#include "../../../include/targets/cpp/class.h"

/// Allocate C++ class declaration struct on heap, initialize default values
/// \param   namespace          name's namespace
/// \param   name               class' name
/// \param   inherits           does class inherit
/// \param   extends            what class it extends from
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppClassDeclaration_T *init_esky_cpp_class_declaration(char *namespace, char *class_name, bool inherits, EskyCppClassDeclaration_T *extends);

/// Allocate C++ class implementation struct on heap, initialize default values
/// \param   declaration                class' declaration structure
/// \param   methods_implementations    implementations for all methods of the class
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppClassDeclaration_T *init_esky_cpp_class_implementation(EskyCppClassDeclaration_T *declaration, EskyCppFunctionImplementation_T **methods_implementations);