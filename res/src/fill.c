#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_fill(char c, size_t len)
{
    ud_arr_char_a  *str;

    str = ud_arr_tnew(ud_arr_type_char(), len, ud_str_fill(c, len));
    return (str);
}