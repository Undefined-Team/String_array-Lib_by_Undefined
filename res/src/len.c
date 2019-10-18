#include "ud_string_array.h"

size_t  ud_stra_len(ud_arr_char_a *str)
{
    if (!str) ud_ut_error("Null array provided.");
    else if (!str->val) return 0;
    return ud_str_len((char*)str->val);
}