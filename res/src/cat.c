#include "ud_string_array.h"

ud_arr_char_a  *ud_stra_cat(ud_arr_char_a *head, ud_arr_char_a *tail)
{
    ud_arr_char_a  *cat;

    if (!head) ud_ut_error("Null array provided as first argument.");
    else if (!tail) ud_ut_error("Null array provided as second argument.");
    cat = ud_arr_tnew(ud_stra_type_char(), head->len + tail->len, ud_str_cat((char *)head->val, (char *)tail->val));
    return cat;
}