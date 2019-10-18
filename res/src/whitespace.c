#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_whitespace(ud_arr_char_a *str)
{
    if (!str) ud_ut_error("Null array provided.");
    char *ws = ud_str_whitespace((char *)str->val);
    return ud_arr_tnew(ud_stra_type_char(), ud_str_len(ws), ws);
}