#include "ud_string.h"

ud_arr  *ud_stra_fsub(ud_arr *str, size_t start, size_t len)
{
    ud_arr  *sub = ud_stra_sub(str, start, len);
    ud_arr_free(str);
    return (sub);
}