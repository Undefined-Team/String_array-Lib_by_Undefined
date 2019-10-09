#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_ctoa(char c)
{
    return ud_arr_set(char, c, '\0');
}