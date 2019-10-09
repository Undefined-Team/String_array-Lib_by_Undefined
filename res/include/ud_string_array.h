#ifndef UD_STRING_ARRAY_H
# define UD_STRING_ARRAY_H

// Lib
#include <ud_utils.h>
#include <ud_math.h>
#include <ud_array.h>

// Macro
# define ud_str_is_white_space(c)   ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\v' || (c) == '\f' || (c) == '\0')
# define ud_stra_dup(str)           ud_stra_ndup(str, 0)
# define ud_stra_fdup(str)          ud_stra_fndup(str, 0)
# define ud_stra_vjoin(...)         ud_stra_vjoin_ctr(UD_ARGS_LEN(char *, __VA_ARGS__), __VA_ARGS__)

// Structures  

// Prototypes
int                                 ud_stra_chr(ud_arr *str, char c);
int                                 ud_stra_cmp(ud_arr *s1, ud_arr *s2);
ud_arr                              *ud_stra_ctoa(char c);
ud_arr                              *ud_stra_ndup(ud_arr *str, size_t len);
ud_arr                              *ud_stra_fndup(ud_arr *str, size_t len);
ud_arr                              *ud_stra_fill(char c, size_t len);
ud_arr                              *ud_stra_fjoin(ud_arr *head, ud_arr *tail);
ud_arr                              *ud_stra_fsub(ud_arr *str, size_t start, size_t len);
ud_arr                              *ud_stra_join(ud_arr *head, ud_arr *tail);
ud_arr                              *ud_stra_sub(ud_arr *str, size_t start, size_t len);
size_t                              ud_stra_len(ud_arr *str);
ud_arr                              *ud_stra_split(ud_arr *str, char *sep);
ud_arr                              *ud_stra_vjoin_ctr(size_t args_len, ...);

#endif