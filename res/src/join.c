#include "ud_string_array.h"

ud_arr  *ud_stra_join(ud_arr *head, ud_arr *tail)
{
    ud_arr  *join;

    if (!head) ud_ut_error("Null array provided as first argument.");
    else if (!tail) ud_ut_error("Null array provided as second argument.");
    join = ud_arr_new(sizeof(char), head->len + tail->len, ud_str_join((char *)head->val, (char *)tail->val));
    return join;
}