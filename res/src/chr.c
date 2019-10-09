#include "ud_string.h"

int     ud_stra_chr(ud_arr *str, char c)
{
    if (!str) ud_ut_error("Null array provided.");
    return ud_str_chr((char *)str->val, c);
}