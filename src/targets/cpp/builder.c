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

#include "builder.h"

/// Allocate C++ builder struct on heap, initialize default values
/// \param   output_filename    output header filename
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppBuilder_T *init_esky_cpp_builder_for_header_file(char *output_filename)
{
  EskyCppBuilder_T *builder = malloc(sizeof(struct ESKY_CPP_BUILDER_STRUCT));
  builder->header = true;
  builder->output_filename = output_filename;
  return builder;
}

/// Allocate C++ builder struct on heap, initialize default values
/// \param   output_filename    output implementation filename
/// \return  NULL on error, not NULL on success (allocated structure)
EskyCppBuilder_T *init_esky_cpp_builder_for_implementation_file(char *output_filename)
{
  EskyCppBuilder_T *builder = malloc(sizeof(struct ESKY_CPP_BUILDER_STRUCT));
  builder->header = false;
  builder->output_filename = output_filename;
  return builder;
}
