#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_fjoin(ud_arr_char_a *head, ud_arr_char_a *tail)
{
    ud_arr_char_a  *join = ud_stra_join(head, tail);
    ud_arr_free(head);
    ud_arr_free(tail);
    return join;
}