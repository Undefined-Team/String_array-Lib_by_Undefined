#include "ud_string_array.h"

ud_arr  *ud_stra_whitespace(ud_arr *str)
{
    if (!str) ud_ut_error("Null array provided.");
    (char *)str->val = ud_str_whitespace((char *)str->val);
    return str;
}