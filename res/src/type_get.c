#include "ud_string_array.h"

ud_arr_type    *ud_stra_type_char(void)
{
    static ud_arr_type *char_type = NULL;
    if (!char_type) char_type = ud_arr_type_get(char);
    return char_type;
}