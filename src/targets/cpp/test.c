#include "cpp.h"

int main()
{
  EskyCppType_T *int_array_pointer = init_esky_cpp_pointer_type(init_esky_cpp_array_type(init_esky_cpp_primary_type(CHAR_TYPE)));
  printf("%s", esky_cpp_emit_type(int_array_pointer));
  free(int_array_pointer);
}