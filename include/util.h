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

#ifndef _ESKY_UTIL_H_
#define _ESKY_UTIL_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/// @param   fmt   format
/// @param   ...   arguments list (format values)
/// @return  formatted string
char *format(const char *fmt, ...);

/// Similar to the ::format function
/// @param   fmt   format
/// @param   args  grguments list
/// @return  formatted string
char *formatv(const char *fmt, va_list args);

#endif /* _ESKY_UTIL_H_ */