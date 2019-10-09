#include "ud_string_array.h"

ud_arr  *ud_stra_escape(ud_arr *str)
{
    if (!str->val || str->len == 0)
        return str;
    char *esc = ud_str_escape((char *)str->val);
    return ud_arr_new(sizeof(char), ud_str_len(esc), esc);
}