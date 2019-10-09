#include "ud_string.h"

ud_arr  *ud_stra_fndup(ud_arr *str, size_t len)
{
    ud_arr  *dup = ud_stra_ndup(str, len);
    ud_arr_free(str);
    return dup;
}