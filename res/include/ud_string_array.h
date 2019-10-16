#ifndef UD_STRING_ARRAY_H
# define UD_STRING_ARRAY_H

// Lib
#include <ud_utils.h>
#include <ud_math.h>
#include <ud_array.h>

// Macro
# define ud_stra_dup(str)                   ud_stra_ndup(str, 0)
# define ud_stra_fdup(str)                  ud_stra_fndup(str, 0)
# define ud_stra_vjoin(sep, ...)            ud_stra_vjoin_ctr(UD_ARGS_LEN(char *, __VA_ARGS__), sep, 0, __VA_ARGS__)
# define ud_stra_vnjoin(sep, skip, ...)     ud_stra_vjoin_ctr(UD_ARGS_LEN(char *, __VA_ARGS__), sep, skip, __VA_ARGS__)
# define ud_stra_new(str)                   ud_arr_new(sizeof(char), ud_str_len(str), str)

# define ud_stra_vrsplit(str, ...)   	    ({ char *sep[] = {__VA_ARGS__, NULL}; ud_arr *splitted = ud_stra_rsplit(str, sep); splitted; })


// Structures  

// Prototypes
int                                         ud_stra_chr(ud_arr_char_a *str, char c);
int                                         ud_stra_cmp(ud_arr_char_a *s1, ud_arr_char_a *s2);
ud_arr_char_a                               *ud_stra_ctoa(char c);
ud_arr_char_a                               *ud_stra_ndup(ud_arr_char_a *str, size_t len);
ud_arr_char_a                               *ud_stra_fndup(ud_arr_char_a *str, size_t len);
ud_arr_char_a                               *ud_stra_fill(char c, size_t len);
ud_arr_char_a                               *ud_stra_fcat(ud_arr_char_a *head, ud_arr_char_a *tail);
ud_arr_char_a                               *ud_stra_fsub(ud_arr_char_a *str, size_t start, size_t len);
ud_arr_char_a                               *ud_stra_cat(ud_arr_char_a *head, ud_arr_char_a *tail);
ud_arr_char_a                               *ud_stra_sub(ud_arr_char_a *str, size_t start, size_t len);
size_t                                      ud_stra_len(ud_arr_char_a *str);
ud_arr_char_a                               *ud_stra_split(ud_arr_char_a *str, char *sep);
ud_arr                                      *ud_stra_rsplit(ud_arr *str, char **floor_sep);
ud_arr_char_a                               *ud_stra_vjoin_ctr(size_t args_len, char *sep, size_t skip, ...);

#endif