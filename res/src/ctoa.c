#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_ctoa(char c)
{
    return ud_arr_tset(char, ud_stra_type_char(), c, '\0');
}