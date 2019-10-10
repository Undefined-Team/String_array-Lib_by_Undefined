#include "ud_string_array.h"

ud_arr_char_a                      *ud_stra_split(ud_arr_char_a *str, char *sep)
{
    if (!str) ud_ut_error("Null array provided as first argument.");
    else if (str->type_s != sizeof(char)) ud_ut_error("String argument must be an array of char");
    else if (!((char*)str->val) || !*((char*)str->val)) 
    {
        ud_arr_str_a       *new_arr    = ud_arr_init(0, 1);
        *(ud_arr_char_a**)new_arr->val = ud_stra_dup(str);
        return new_arr;
    }
    else if (!sep || !*sep) ud_ut_error("Separator can't be null");
    size_t              split_len   = 0;
    size_t              sep_len     = ud_str_len(sep);
    char                *val        = (char*)str->val;
    ud_str_split_len    *begin      = ud_str_split_get_len(val, sep, &split_len);
    if (!split_len)     return ud_stra_dup(str); 
    ud_arr_str_a        *new_arr    = ud_arr_init(0, split_len);
    ud_arr_char_a       **arr_val   = (ud_arr_char_a**)new_arr->val;
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

static ud_arr   *ud_stra_split_rec(ud_arr *str, char **floor_sep)
{
    if (!floor_sep || !*floor_sep) return NULL;
    char *sep = *floor_sep;
    ++floor_sep;
    ud_arr *splitted = ud_stra_split(str, sep);
    if (splitted->type_s == 0 && *floor_sep)
    {
        size_t len = splitted->len;
        ud_arr **val = (ud_arr**)splitted->val;
        ud_arr *new_val;
        while (len-- > 0)
        {
            new_val = ud_stra_split_rec(*val, floor_sep);
            ud_arr_free(*val);
            *val++ = new_val;
        }
    }
    return splitted;
}

ud_arr          *ud_stra_rsplit_call(ud_arr *str, size_t args_len, ...)
{
    va_list args;
    va_start(args, args_len);
    char *sep[args_len + 1];
    char **sep_tmp = sep;
    while (args_len-- > 0) *sep_tmp++ = (char*)va_arg(args, char*);
    *sep_tmp = NULL;
    ud_arr *parsed = ud_stra_split_rec(str, sep);
    va_end(args);
    return parsed;
}