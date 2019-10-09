#include "ud_string.h"

ud_arr  *ud_stra_fjoin(ud_arr *head, ud_arr *tail)
{
    ud_arr  *join = ud_stra_join(head, tail);
    ud_arr_free(head);
    ud_arr_free(tail);
    return join;
}