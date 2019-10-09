#include "ud_string_array.h"

ud_arr  *ud_stra_sub(ud_arr *str, size_t start, size_t len)
{
    ud_arr  *sub;

    if (!str)
        ud_ut_error("%s", "Null array provided.");
    sub = ud_arr_init(sizeof(char), len);
    (char *)sub->val = ud_str_sub((char *)str->val, start, len);
    return (sub);
}