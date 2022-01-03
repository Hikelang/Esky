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

#include "../../../include/targets/cpp/header.h"

/// Convert header filename to macro's name. Example:
/// header.h => _HEADER_H_
/// Code:
/// \code
/// #ifndef _HEADER_H_
/// #define _HEADER_H_
/// ...
/// #endif /* _HEADER_H_ */
/// \endcode
/// \param   filename           header filename
/// \return  macro's name
char *esky_cpp_filename_to_macro_name(char *filename)
{
  char *macro_name = malloc(ESKY_CPP_HEADER_MACRO_NAME_MAX_SIZE * sizeof(char));
  for (size_t i = 0; i < strlen(filename); i++)
  {
    char current_character = filename[i];
    if (current_character == '-')
      current_character = '_';

    macro_name[i] = toupper(current_character);
  }

  macro_name[strlen(filename)] = '\0';
  char *new_macro_name = malloc(ESKY_CPP_HEADER_MACRO_NAME_MAX_SIZE * sizeof(char));
  sprintf(new_macro_name, "_%s_H_", macro_name);
  free(macro_name);
  return new_macro_name;
}

/// \param   header_filename    Path to header file
/// \param   header_content     Header's source code
/// \return  emitted C++ header's content
char *esky_cpp_emit_header(char *header_filename, char *header_content)
{
  char *header_macro_name = esky_cpp_filename_to_macro_name(header_filename);
  return format(
      "#ifndef %s\n"
      "#define %s\n"
      "#endif",
      header_macro_name, header_macro_name);
}