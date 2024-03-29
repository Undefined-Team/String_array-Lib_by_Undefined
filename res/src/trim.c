#include "ud_string_array.h"

static void ud_stra_trim_ctr(ud_arr *arr, char **trim, size_t *trim_len)
{
    if (arr->type == ud_arr_type_arr())
    {
        ud_arr **val = (ud_arr**)arr->val;
        for (ud_ut_count len = arr->len; len > 0; --len) ud_stra_trim_ctr(*val++, trim, trim_len);
    }
    else if (arr->type == ud_arr_type_char())
    {
        char *vval;
        vval = (char*)arr->val;
        vval = ud_str_trim_main_ctr(vval, trim, trim_len, true);
        arr->val = vval;
        arr->len = ud_str_len(vval);
    }
}

void    ud_stra_trim(ud_arr *arr, char **trim)
{
    size_t trim_len[ud_ptr_len(trim)];
    size_t *trim_len_tmp = trim_len;
    ud_ptr_foreach(trim, elem, *trim_len_tmp++ = ud_str_len(*elem););
    ud_stra_trim_ctr(arr, trim, trim_len);
}