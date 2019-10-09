#include "ud_string_array.h"

int     ud_stra_cmp(ud_arr_char_a *s1, ud_arr_char_a *s2)
{
    if (!s1) ud_ut_error("Null array provided as first argument.");
    else if (!s2) ud_ut_error("Null array provided as second argument.");
    return ud_str_cmp((char *)s1->val, (char *)s2->val);
}