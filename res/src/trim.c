#include "ud_string_array.h"

static ud_bool ud_stra_trim_ctr(ud_arr *arr, char **trim, size_t *trim_len, ud_bool need_free)
{
    if (arr->type == ud_arr_type_arr())
    {
        ud_arr **val = (ud_arr**)arr->val;
        char *vval;
        for (ud_ut_count len = arr->len; len > 0; --len, ++val)
            if (ud_stra_trim_ctr(*val, trim, trim_len, need_free))
            {
                vval = (char*)(*val)->val;
                vval = ud_str_trim_ctr(vval, trim, trim_len, need_free);
            }
    }
    else if (arr->type == ud_stra_type_char()) return true;
    return false;
}

void    ud_stra_trim(ud_arr *arr, char **trim)
{
    size_t trim_len[ud_ptr_len(trim)];
    size_t *trim_len_tmp = trim_len;
    ud_ptr_fp(trim, ud_str_trim_len, &trim_len_tmp);
    ud_stra_trim_ctr(arr, trim, trim_len, true);
}

ud_arr   *ud_stra_ctrim(ud_arr *arr, char **trim)
{
    size_t trim_len[ud_ptr_len(trim)];
    size_t *trim_len_tmp = trim_len;
    ud_ptr_fp(trim, ud_str_trim_len, &trim_len_tmp);
    ud_arr *new = ud_arr_cpy(arr);
    ud_stra_trim_ctr(new, trim, trim_len, false);
    return new;
}