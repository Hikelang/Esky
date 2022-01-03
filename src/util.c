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

#include <stdlib.h>
#include "../include/util.h"

/// @param   fmt   format
/// @param   ...   arguments list (format values)
/// @return  formatted string
char *format(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  char *str = formatv(fmt, args);
  va_end(args);

  return str;
}

/// Similar to the ::format function
/// @param   fmt   format
/// @param   args  grguments list
/// @return  formatted string
char *formatv(const char *fmt, va_list args)
{
  va_list again;
  va_copy(again, args);

  int length = vsnprintf(NULL, 0, fmt, args) + 1;
  char *out = malloc(length * sizeof(char));

  vsnprintf(out, length, fmt, again);

  return out;
}