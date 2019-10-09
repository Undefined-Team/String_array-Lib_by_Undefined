#include "ud_string_array.h"

size_t  ud_stra_len(ud_arr *str)
{
    if (!str) ud_ut_error("Null array provided.");
    else if (!str->val) return 0;
    ud_ut_count     i = 0;
    char            *a_str = (char *)str->val;
    for (; *a_str; ++i, ++a_str);
    return (i);
}