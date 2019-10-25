#include "ud_string_array.h"

ud_arr_char_a                      *ud_stra_split(ud_arr_char_a *str, char *sep)
{
    if (!str) ud_ut_error("Null array provided as first argument.");
    else if (str->type != ud_arr_type_char()) ud_ut_error("String argument must be an array of char");
    else if (!((char*)str->val) || !*((char*)str->val)) 
    {
        ud_arr_str_a       *new_arr    = ud_arr_tinit(ud_arr_type_arr(), 1);
        *(ud_arr_char_a**)new_arr->val = ud_stra_dup(str);
        return new_arr;
    }
    else if (!sep || !*sep) ud_ut_error("Separator can't be null");
    size_t              split_len   = 0;
    size_t              sep_len     = ud_str_len(sep);
    char                *val        = (char*)str->val;
    ud_str_split_len    *begin      = ud_str_split_get_len(val, sep, &split_len);
    if (!split_len)     return ud_stra_dup(str); 
    ud_arr_str_a        *new_arr    = ud_arr_tinit(ud_arr_type_arr(), split_len);
    ud_arr_char_a       **arr_val   = (ud_arr_char_a**)new_arr->val;
    char                *arr_str;
    for (ud_str_split_len *tmp = begin->next; tmp; tmp = tmp->next)
    {
        ud_ut_prot_malloc(arr_str = ud_ut_malloc(sizeof(char) * (tmp->len + 1)));
        arr_str[tmp->len] = '\0';
        ud_mem_cpy_rs(arr_str, val, tmp->len);
        *arr_val = ud_arr_tnew(ud_arr_type_char(), tmp->len, arr_str);
        val += sep_len;
        ++arr_val;
    }
    ud_list_free(ud_str_split_len, begin);
    return new_arr;
}

ud_arr   *ud_stra_rsplit(ud_arr *str, char **floor_sep)
{
    if (!floor_sep || !*floor_sep) return NULL;
    ud_arr *splitted = ud_stra_split(str, *floor_sep);
    ++floor_sep;
    if (splitted->type == ud_arr_type_arr() && *floor_sep)
    {
        size_t len = splitted->len;
        ud_arr **val = (ud_arr**)splitted->val;
        ud_arr *new_val;
        while (len-- > 0)
        {
            new_val = ud_stra_rsplit(*val, floor_sep);
            ud_arr_free(*val);
            *val++ = new_val;
        }
    }
    return splitted;
}