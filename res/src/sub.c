#include "ud_string_array.h"

ud_arr  *ud_stra_sub(ud_arr *str, size_t start, size_t len)
{
    if (!str)
        ud_ut_error("%s", "Null array provided.");
    char *test = ud_str_sub((char *)str->val, start, len);
    printf("%s\n",test);
    return ud_arr_new(sizeof(char), len, ud_str_sub((char *)str->val, start, len));
}