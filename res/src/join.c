#include "ud_string_array.h"

ud_arr    *ud_stra_join_ctr(ud_arr *str, char *sep, ud_bool need_free)
{
    if (!str) return ud_stra_snew("");  
    size_t sep_len = ud_str_len(sep);
    size_t total_len = 0;
    ud_arr **str_tmp = (ud_arr**)str->val;
    size_t str_nbr = str->len;
    ud_arr **val = (ud_arr**)str->val;
    for (ud_ut_count i = 0; i < str_nbr; ++i) 
        total_len += (*val++)->len;
    total_len += sep_len * (str_nbr - 1);
    ud_arr *res = ud_stra_init(total_len);
    char *res_val = (char*)res->val;
    --str_nbr;
    if (need_free)
    {
        for (ud_ut_count i = 0; i < str_nbr; ++i)
        {
            ud_str_cpy_rd(res_val, (char*)(((*str_tmp)->val)));
            ud_arr_free(*str_tmp++);
            ud_str_cpy_rd(res_val, sep);
        }
        ud_str_cpy_rd(res_val, (char*)(((*str_tmp)->val)));
        ud_arr_free(*str_tmp);
        ud_ut_free(str->val);
        ud_ut_free(str);
    }
    else
    {
        for (ud_ut_count i = 0; i < str_nbr; ++i)
        {
            ud_str_cpy_rd(res_val, (char*)(((*str_tmp)->val)));
            ++str_tmp;
            ud_str_cpy_rd(res_val, sep);
        }
        ud_str_cpy_rd(res_val, (char*)(((*str_tmp)->val)));
    }
    return res;
}

ud_arr *ud_stra_rjoin_ctr(ud_arr *str, char **sep, ud_bool need_free)
{
    ++sep;
    ud_arr **str_val = (ud_arr**)str->val;
    if (*sep)
    {
        if (!need_free)
        {
            ud_arr *new = ud_arr_tinit(ud_arr_type_arr(), str->len);
            ud_arr **new_val = (ud_arr**)new->val;
            for (ud_ut_count len = str->len; len-- > 0;)
                *new_val++ = ud_stra_rjoin_ctr(*str_val++, sep, need_free);
            return ud_stra_join_ctr(new, *(sep - 1), true);
        }
        else
            for (ud_ut_count len = str->len; len-- > 0; ++str_val)
                *str_val = ud_stra_rjoin_ctr(*str_val, sep, true);
    }
    return ud_stra_join_ctr(str, *(sep - 1), need_free);
}