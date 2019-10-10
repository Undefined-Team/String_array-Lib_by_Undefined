#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_fcat(ud_arr_char_a *head, ud_arr_char_a *tail)
{
    ud_arr_char_a  *cat = ud_stra_cat(head, tail);
    ud_arr_free(head);
    ud_arr_free(tail);
    return cat;
}