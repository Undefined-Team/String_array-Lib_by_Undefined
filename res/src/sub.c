#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_sub(ud_arr_char_a *str, size_t start, size_t len)
{
    if (!str)
        ud_ut_error("Null array provided.");
    return ud_arr_tnew(ud_arr_type_arr(), len, ud_str_sub((char *)str->val, start, len));
}