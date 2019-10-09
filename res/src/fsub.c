#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_fsub(ud_arr_char_a *str, size_t start, size_t len)
{
    ud_arr_char_a  *sub = ud_stra_sub(str, start, len);
    ud_arr_free(str);
    return (sub);
}