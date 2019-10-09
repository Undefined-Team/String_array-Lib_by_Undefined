#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_fndup(ud_arr_char_a *str, size_t len)
{
    ud_arr_char_a  *dup = ud_stra_ndup(str, len);
    ud_arr_free(str);
    return dup;
}