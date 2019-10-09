#include "ud_string.h"

ud_arr  *ud_stra_ndup(ud_arr *str, size_t len)
{
    ud_arr  *dup;

    if (!str) ud_ut_error("Null array provided.");
    dup = ud_arr_init(sizeof(char), len ? len : str->len);
    (char *)dup->val = ud_str_ndup((char *)str->val, len ? len : str->len);
    return dup;
}