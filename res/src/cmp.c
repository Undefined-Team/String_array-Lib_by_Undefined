#include "ud_string_array.h"

int     ud_stra_cmp(ud_arr_char_a *s1, ud_arr_char_a *s2)
{
    if (!s1) return (s2) ? -1 : 0;
    else if (!s2) return 1;
    return ud_str_cmp((char *)s1->val, (char *)s2->val);
}

int     ud_stra_ncmp(ud_arr_char_a *s1, ud_arr_char_a *s2, size_t n)
{
    if (!s1) return (s2) ? -1 : 0;
    else if (!s2) return 1;
    return ud_str_ncmp((char *)s1->val, (char *)s2->val, n);
}