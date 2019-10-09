#include "ud_string.h"

ud_arr  *ud_stra_escape(ud_arr *str)
{
    if (!str->val || str->len == 0)
        return str;
    return ud_str_escape((char *)str->val);
}