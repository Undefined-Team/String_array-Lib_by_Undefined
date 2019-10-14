#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_vjoin_ctr(size_t args_len, char *sep, size_t skip, ...)
{
    if (!args_len)
        return (NULL);
    char    *args[args_len];
    va_list va;
    size_t  len[args_len];
    size_t  total_len = 0;

    va_start(va, skip);
    size_t  sep_len = ud_str_len(sep);
    for (ud_ut_count i = 0; i < args_len; ++i)
    {
        char *buf = (char *)va_arg(va, char *);
        if (!buf && --i < --args_len) continue;
        args[i] = buf;
        len[i] = ud_str_len(args[i]);
        total_len += (!skip || !(i % skip)) ? len[i] + sep_len : len[i];
    }
    ud_arr_char_a   *join = ud_arr_init(sizeof(char), (!skip || !(args_len % skip)) ? total_len - sep_len : total_len);
    char            *t_join_val = (char *)join->val;
    for (ud_ut_count i = 0; i < args_len; ++i)
    {
        ud_mem_cpy(t_join_val, args[i], len[i]);
        t_join_val += len[i];
        if ((!skip || !((i + 1) % skip)) && i < args_len - 1)
        {
            ud_mem_cpy(t_join_val, sep, sep_len);
            t_join_val += sep_len;
        }
    }
    *t_join_val = '\0';
    va_end(va);
    return join;
}