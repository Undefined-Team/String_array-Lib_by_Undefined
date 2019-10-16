#include "ud_string_array.h"

ud_arr    *ud_stra_join_ctr(ud_arr *str, char *sep, ud_bool need_free)
{
    if (!str) return ud_stra_new("");  
    size_t sep_len = ud_str_len(sep);
    size_t total_len = 0;
    ud_arr *str_tmp = str;
    size_t str_nbr = str->len
    size_t strs_len[str_nbr];
    size_t *strs_len_tmp = strs_len;

}
