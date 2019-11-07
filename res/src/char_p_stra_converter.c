#include "ud_string_array.h"

void    ud_stra_arr_from_char_p_arr(ud_arr *arr)
{
    if (!arr) ud_ut_error("Array can't be null");
    ud_arr_type *arr_type = arr->type;
    ud_ut_count len = arr->len;
    if (arr_type == ud_arr_type_arr())
    {
        ud_arr **val = (ud_arr**)arr->val;
        while (len-- > 0) ud_stra_arr_from_char_p_arr(*val++);
    }
    else if (arr_type == ud_arr_type_char_p())
    {
        char **val = (char**)arr->val;
        while (len-- > 0)
        {
            *val = (char*)ud_stra_new(*val);
            ++val;
        }
        arr->type = ud_arr_type_arr();
    }
}

ud_bool ud_stra_arr_to_char_p_arr(ud_arr *arr)
{
    if (!arr) ud_ut_error("Array can't be null");
    ud_arr_type *arr_type = arr->type;
    if (arr_type == ud_arr_type_char()) return true;
    else if (arr_type == ud_arr_type_arr())
    {
        ud_bool elem_are_stra = true;
        ud_arr **val = (ud_arr**)arr->val;
        size_t len = arr->len;
        ud_ut_count len_tmp = len;
        while (len_tmp-- > 0) if (!ud_stra_arr_to_char_p_arr(*val++)) elem_are_stra = false;
        if (elem_are_stra)
        {
            char *val_tmp;
            val = (ud_arr**)arr->val;
            while (len-- > 0)
            {
                val_tmp = ud_ut_malloc(sizeof(char) * ((*val)->len + 1));
                val_tmp[(*val)->len] = '\0';
                ud_mem_cpy(val_tmp, (*val)->val, (*val)->len * sizeof(char));
                ud_arr_free(*val);
                *val++ = (ud_arr*)val_tmp;
            }
            arr->type = ud_arr_type_char_p();
        }
    }
    return false;
}