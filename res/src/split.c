#include "ud_string.h"

ud_arr                      *ud_stra_split(ud_arr *str, char *sep)
{
    if (!str) ud_ut_error("Null array provided as first argument.");
    else if (str->type_s != sizeof(char)) ud_ut_error("str argument must be an array of char");
    else if (!((char*)str->val) || !*((char*)str->val)) return ud_stra_dup(str);
    else if (!sep || !*sep) ud_ut_error("separator can't be null");
    size_t              split_len   = 0;
    size_t              sep_len     = ud_ut_byte_len(sep);
    char                *val        = (char*)str->val;
    ud_str_split_len    *begin      = ud_str_split_get_len(val, sep, &split_len);
    if (!split_len)     return ud_stra_dup(str); 
    ud_arr              *new_arr    = ud_arr_init(0, split_len);
    ud_arr              **arr_val   = (ud_arr**)new_arr->val;
    char                *arr_str;
    for (ud_str_split_len *tmp = begin->next; tmp; tmp = tmp->next)
    {
        UD_UT_PROT_MALLOC(arr_str = ud_ut_malloc(sizeof(char) * (tmp->len + 1)));
        arr_str[tmp->len] = '\0';
        val = ud_mem_cpy_rs(arr_str, val, tmp->len);
        *arr_val = ud_arr_new(sizeof(char), tmp->len, arr_str);
        val += sep_len;
        ++arr_val;
    }
    ud_str_split_free_len(begin);
    return new_arr;
}