#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_cat(ud_arr_char_a *head, ud_arr_char_a *tail)
{
    ud_arr_char_a  *cat;

    if (!head) return (tail) ? ud_stra_dup(tail) : NULL;
    else if (!tail) return ud_stra_dup(head);
    cat = ud_arr_tnew(ud_arr_type_char(), head->len + tail->len, ud_str_cat((char *)head->val, (char *)tail->val));
    return cat;
}