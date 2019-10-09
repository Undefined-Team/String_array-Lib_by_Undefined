#include "ud_string_array.h"

ud_arr  *ud_stra_vjoin_ctr(size_t args_len, ...)
{
    char    *args[args_len];
    va_list va;
    size_t  len[args_len];
    size_t  total_len = 0;

    va_start(va, args_len);
    for (ud_ut_count i = 0; i < args_len; ++i)
    {
        args[i] = (char *)va_arg(va, char *);
        len[i] = ud_str_len(args[i]);
        total_len += len[i];
    }
    ud_arr  *join = ud_arr_init(sizeof(char), total_len);
    char    *t_join_val = (char *)join->val;
    for (ud_ut_count i = 0; i < args_len; ++i)
    {
        ud_mem_cpy(t_join_val, args[i], len[i]);
        t_join_val += len[i];
    }
    va_end(va);
    return join;
}