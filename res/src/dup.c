#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_ndup(ud_arr_char_a *str, size_t len)
{
    ud_arr_char_a  *dup;

    if (!str) return NULL;
    dup = ud_arr_tnew(ud_arr_type_char(), len ? len : str->len, ud_str_ndup((char *)str->val, len ? len : str->len));
    return dup;
}