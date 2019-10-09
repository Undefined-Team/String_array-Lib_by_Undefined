#include "ud_string_array.h"

int     ud_stra_chr(ud_arr_char_a *str, char c)
{
    if (!str) ud_ut_error("Null array provided.");
    return ud_str_chr((char *)str->val, c);
}