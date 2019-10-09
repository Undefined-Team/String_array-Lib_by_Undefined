#include "ud_string_array.h"

ud_arr  *ud_stra_ndup(ud_arr *str, size_t len)
{
    ud_arr  *dup;

    if (!str) ud_ut_error("Null array provided.");
    dup = ud_arr_new(sizeof(char), len ? len : str->len, ud_str_ndup((char *)str->val, len ? len : str->len));
    return dup;
}