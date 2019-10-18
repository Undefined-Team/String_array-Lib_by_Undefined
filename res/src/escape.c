#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_escape(ud_arr_char_a *str)
{
    if (!str->val || str->len == 0)
        return str;
    char *esc = ud_str_escape((char *)str->val);
    return ud_arr_tnew(ud_stra_type_char(), ud_str_len(esc), esc);
}