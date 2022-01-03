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

#ifndef _ESKY_CPP_HEADER_H_
#define _ESKY_CPP_HEADER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../../util.h"

#define ESKY_CPP_HEADER_MACRO_NAME_MAX_SIZE (int)(1e4)

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
char *esky_cpp_filename_to_macro_name(char *filename);

/// \param   header_filename    Path to header file
/// \param   header_content     Header's source code
/// \return  emitted C++ header's content
char *esky_cpp_emit_header(char *header_filename, char *header_content);

#endif /* _ESKY_CPP_HEADER_H_ */