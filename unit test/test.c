#include <ud_string.h>
#include <ud_array.h>
#include <ud_string_array.h>
#include <assert.h>

void ud_stra_test_tmp(void)
{
    ud_arr *a = ud_stra_new("a");
    ud_arr *b = ud_stra_new("b");
    ud_arr *abc = ud_stra_new("abc");
    ud_arr *def = ud_stra_new("def");
    ud_arr *abcdef = ud_stra_new("abcdef");
    ud_arr *aaaaaa = ud_stra_new("aaaaaa");

    ud_ut_test(ud_stra_chr(abc, 'a') == 0);
    ud_ut_test(ud_stra_chr(abc, 'b') == 1);
    ud_ut_test(ud_stra_chr(abc, 'c') == 2);
    ud_ut_test(ud_stra_chr(abc, 0) == -1);
    ud_ut_test(ud_stra_chr(abc, 'd') == -1);
    ud_ut_test(a != ud_stra_dup(a));
    ud_ut_test(!ud_stra_cmp(a, ud_stra_dup(a)) == !ud_mem_cmp(a->val, ud_stra_dup(a)->val, 2) && !ud_stra_cmp(a, ud_stra_dup(a)));
    ud_ut_test(!ud_stra_cmp(a, ud_stra_new("a")));
    ud_ut_test(ud_stra_dup(NULL) == NULL); // exits with error
    ud_ut_test(!ud_stra_cmp(NULL, NULL));
    ud_ut_test(ud_stra_cmp(a, b) == -1);
    ud_ut_test(ud_stra_cmp(b, a) == 1);
    ud_ut_test(ud_stra_cmp(a, abc) < 0);
    ud_ut_test(ud_stra_cmp(abc, a) > 0);
    ud_ut_test(ud_stra_cmp(NULL, abc) < 0);
    ud_ut_test(ud_stra_cmp(abc, NULL) > 0);
    ud_ut_test(!ud_stra_cmp(abc, ud_stra_new("abc")));
    ud_ut_test(!ud_stra_ncmp(abc, a, 1));
    ud_ut_test(!ud_stra_ncmp(a, abc, 1));
    ud_ut_test(!ud_stra_ncmp(abcdef, abc, 3));
    ud_ut_test(!ud_stra_ncmp(abcdef, a, 1));
    ud_ut_test(ud_stra_ncmp(NULL, NULL, 0) == 0);
    ud_ut_test(!ud_stra_cmp(ud_stra_ndup(abcdef, 3), abc));
    ud_ut_test(!ud_stra_cmp(ud_stra_ndup(abcdef, 4), ud_stra_new("abcd")));
    ud_ut_test(!ud_stra_cmp(ud_stra_ndup(abcdef, 1000), abcdef));
    ud_ut_test(!ud_stra_cmp(ud_stra_ndup(abcdef, 0), abcdef));
    ud_ut_test(!ud_stra_cmp(ud_stra_ndup(NULL, 0), NULL));
    ud_ut_test(!ud_stra_cmp(ud_stra_ndup(NULL, 100), NULL));
    ud_ut_test(!ud_stra_cmp(ud_stra_fill('a', 6), aaaaaa));
    ud_ut_test(!ud_stra_cmp(ud_stra_fill('0', 6), ud_stra_new("000000")));
    ud_ut_test(!ud_stra_cmp(ud_stra_fill(0, 0), ud_stra_new("")));
    ud_ut_test(!ud_mem_cmp(ud_stra_fill(0, 6)->val, ud_stra_new("\0\0\0\0\0\0")->val, 6));
    ud_ut_test(!ud_stra_cmp(ud_stra_cat(abc, def), abcdef));
    ud_ut_test(!ud_stra_cmp(ud_stra_cat(NULL, abc), abc));
    ud_ut_test(!ud_stra_cmp(ud_stra_cat(abc, NULL), abc));
    ud_ut_test(ud_stra_cat(NULL, NULL) == NULL);
    ud_ut_test(!ud_stra_cmp(ud_stra_sub(abcdef, 0, 3), abc));
    ud_ut_test(!ud_stra_cmp(ud_stra_sub(abcdef, 3, 6), def));
    ud_ut_test(!ud_stra_cmp(ud_stra_sub(abcdef, 3, 100), def));
    ud_ut_test(!ud_stra_cmp(ud_stra_sub(abcdef, 3, 0), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_sub(abcdef, 10, 10), ud_stra_new("")));
    ud_ut_test(ud_stra_sub(NULL, 0, 1000) == NULL);
    ud_ut_test(!ud_stra_cmp(ud_stra_join(ud_arr_set(ud_arr *, ud_stra_new("a"), ud_stra_new("b"), ud_stra_new("c"), ud_stra_new("d"), ud_stra_new("e"), ud_stra_new("f")), ","), ud_stra_new("a,b,c,d,e,f")));
    ud_ut_test(!ud_stra_cmp(ud_stra_join(ud_arr_set(ud_arr *, ud_stra_new("a"), ud_stra_new("b"), ud_stra_new("c"), ud_stra_new("d"), ud_stra_new("e"), ud_stra_new("f")), NULL), ud_stra_new("abcdef")));
    ud_ut_test(!ud_stra_cmp(ud_stra_join(ud_arr_set(ud_arr *, ud_stra_new("a")), NULL), ud_stra_new("a")));
    ud_ut_test(!ud_stra_cmp(ud_stra_join(NULL, ","), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_join(NULL, NULL), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_join(ud_arr_set(ud_arr *, ud_stra_new("a"), ud_stra_new("b"), ud_stra_new("c"), ud_stra_new("d"), ud_stra_new("e"), ud_stra_new("f")), ","), ud_stra_new("a,b,c,d,e,f")));
    ud_ut_test(!ud_stra_cmp(ud_stra_join(ud_arr_set(ud_arr *, ud_stra_new("a"), ud_stra_new("b"), ud_stra_new("c"), ud_stra_new("d"), ud_stra_new("e"), ud_stra_new("f")), "FOO"), ud_stra_new("aFOObFOOcFOOdFOOeFOOf")));
    ud_ut_test(!ud_stra_cmp(ud_stra_join(ud_arr_set(ud_arr *, ud_stra_new("FOO"), ud_stra_new("FOO")), "FOO"), ud_stra_new("FOOFOOFOO")));
    printf("\n");
    // ud_arr *vjoin1 = ud_stra_vjoin(",", a, b, abc);
    // ud_arr *ret1 = ud_stra_new("a,b,abc");
    // ud_ut_test(!ud_stra_cmp(vjoin1, ret1));
    // ud_arr *vjoin2 = ud_stra_vjoin(",", NULL);
    // ud_ut_test(!ud_stra_cmp(vjoin2, NULL));
    // ud_arr *vjoin3 = ud_stra_vjoin("FOO", ud_stra_new("FOO"), ud_stra_new("FOO"));
    // ud_arr *ret3 = ud_stra_new("FOOFOOFOO");
    // ud_ut_test(!ud_stra_cmp(vjoin3, ret3));
    // ud_arr *vjoin4 = ud_stra_vjoin(",", NULL, NULL, NULL);
    // ud_ut_test(!ud_stra_cmp(vjoin4, NULL));
    // ud_arr *vjoin5 = ud_stra_vjoin(NULL, ud_stra_new("a"), ud_stra_new("b"), ud_stra_new("c"), ud_stra_new("d"));
    // ud_arr *ret5 = ud_stra_new("abcd");
    // ud_ut_test(!ud_stra_cmp(vjoin5, ret5));
    // ud_arr *vjoin6 = ud_stra_vjoin(NULL, NULL, NULL);
    // ud_ut_test(!ud_stra_cmp(vjoin6, NULL));
    ud_ut_test(ud_stra_len(NULL) == 0);
    ud_ut_test(ud_stra_len(ud_stra_new("a")) == 1);
    ud_ut_test(ud_stra_len(ud_stra_new("a\0\0")) == 1);
    ud_ut_test(ud_stra_len(ud_stra_new("abcdefghijklmnopqrstuvwxyz")) == 26);
    ud_ut_test(ud_stra_len(ud_stra_new("")) == 0);
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("foo")), ud_stra_new("foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\"foo\"")), ud_stra_new("foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\"\"")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\"\"\"\"")), ud_stra_new("\"\"")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\'foo\'")), ud_stra_new("foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\'\'")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\'\'\'\'")), ud_stra_new("\'\'")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(NULL), NULL));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\"foo")), ud_stra_new("\"foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\"")), ud_stra_new("\"")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\"\"foo\"")), ud_stra_new("\"foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\"\"\"")), ud_stra_new("\"")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\'foo")), ud_stra_new("\'foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\'")), ud_stra_new("\'")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\'\'foo\'")), ud_stra_new("\'foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_escape(ud_stra_new("\'\'\'")), ud_stra_new("\'")));
    ud_ut_test(ud_stra_len(NULL) == 0);
    ud_ut_test(ud_stra_len(ud_stra_new("a")) == 1);
    ud_ut_test(ud_stra_len(ud_stra_new("a\0\0")) == 1);
    ud_ut_test(ud_stra_len(ud_stra_new("abcdefghijklmnopqrstuvwxyz")) == 26);
    ud_ut_test(ud_stra_len(ud_stra_new("")) == 0);
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("foo")), ud_stra_new("foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\nfoo\n")), ud_stra_new("foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\n\n")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\n\n\n\n")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\tfoo\t")), ud_stra_new("foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\t\t")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\t\t\t\t")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(NULL), NULL));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\nfoo")), ud_stra_new("foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\n")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\n\nfoo\n")), ud_stra_new("foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\n\n\n")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\tfoo")), ud_stra_new("foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\t")), ud_stra_new("")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\t\tfoo\t")), ud_stra_new("foo")));
    ud_ut_test(!ud_stra_cmp(ud_stra_whitespace(ud_stra_new("\t\t\t")), ud_stra_new("")));
    
    // ud_arr *split = "aFOObFOOcdcdecFOOdwqdFOFOOFO";
    // ud_arr **splitted = ud_stra_split(split, "FOO");
    // ud_arr **splitted_verif = ud_arr_set(char *, "a", "b", "cdcdec", "dwqdFO", "FO");
    // ud_arr **splitted2 = ud_stra_split("abc", " ");

    // for (ud_ut_count i = 0; i < 5; ++i)
    //     ud_ut_dtest(!ud_stra_cmp(splitted->val[i], splitted_verif->val[i]), "[%zu] %s %s", i, splitted->val[i], splitted_verif->val[i]);
    // ud_ut_test(ud_stra_split(NULL, "a") == NULL);
    // ud_ut_test(ud_ptr_len(splitted2) == 1);
    // ud_ut_test(!ud_stra_cmp(splitted2[0], abc));
    // ud_ut_test(1 && ud_stra_split("abc", NULL)); // should exit with ud_ut_error
}

int main(void)
{
    // ud_arr *a = ud_arr_set(char, 'a');
    // ud_arr *abc = ud_arr_set(char, 'a', 'b', 'c');
    // ud_arr *de = ud_arr_set(char, 'd', 'e');
    // ud_arr *aaaaa = ud_arr_set(char, 'a', 'a', 'a', 'a', 'a');
    // ud_arr *abcde = ud_arr_set(char, 'a', 'b', 'c', 'd', 'e');
    // ud_arr *abzde = ud_arr_set(char, 'a', 'b', 'z', 'd', 'e');
    // ud_arr *abade = ud_arr_set(char, 'a', 'b', 'a', 'd', 'e');
    // ud_arr *null = ud_arr_set(char, 'a');
    // null->val = NULL;
    // null->len = 0;

    // ud_ut_time("%s", "Starting tests...");
    // // Basic tests
    // assert(ud_stra_cmp(abade, abzde) == 'a' - 'z');
    // assert(ud_stra_cmp(abcde, abcde) == 0);
    // assert(ud_stra_cmp(null, abcde) == -1);
    // assert(ud_stra_cmp(ud_stra_dup(abcde), abcde) == 0);
    // assert(ud_stra_chr(null, 'a') == -1);
    // assert(ud_stra_chr(abcde, 'a') == 0);
    // assert(ud_stra_chr(abcde, 'c') == 2);
    // assert(ud_stra_chr(abcde, 'f') == -1);
    // assert(!ud_stra_cmp(ud_stra_fill('a', 5), aaaaa));
    // assert(!ud_stra_cmp(ud_stra_join(abc, de), abcde));
    // assert(!ud_stra_cmp(ud_stra_sub(abcde, 0, 3), abc));
    // assert(!ud_stra_cmp(ud_stra_sub(abcde, 3, 2), de));
    // assert(!ud_stra_cmp(ud_stra_ctoa('a'), a));
    // assert(!ud_stra_cmp(ud_stra_vjoin("test", "b", "mdr", "allo"), ud_arr_new(sizeof(char), 13, "testbmdrallo")));
    // ud_ut_time("%s", "All tests passed.");
    // ud_arr *test21 = ud_stra_vjoin(NULL, "test", "A");
    // ud_arr_print(test21);

    // printf("%zd\n", UD_ARGS_LEN(int, 1, 2, 3));
    // // return 0;
    // char value[] = ",,2,";
    // ud_arr  *str = ud_arr_new(sizeof(char), 4, value);
    // ud_arr_print(str, char, "%c");
    // ud_arr  *splitted = ud_str_split(str, ",");
    // // printf("splitted len = %zd\n", splitted->len);
    // ud_arr *before_test =  ud_arr_init(sizeof(char), 0);
    // printf("splitted:\n");
    // ud_arr_print(splitted, char, "|%c| ");
    // printf("before_test:\n");
    // ud_arr_print(before_test, char, "|%c| ");
    // // ud_arr *test = ud_arr_init(0, 2);
    // printf("add real = %p\n", splitted);
    // printf("auto:\n");
    // ud_arr *test = ud_arr_set(ud_arr*, splitted, before_test);
    // // printf("auto len = %zd\n", test->len);
    // // ud_arr **val = (ud_arr**)test->val;
    // // printf("elemt1 len = %zd\n", val[0]->len);
    // // ud_arr_print(val[0], char, "|%c| ");

    // ud_arr_print(test, char, "|%c| ");
    // // ud_arr_rfree(test);

    // test = ud_arr_init(0, 2);
    // ud_arr **val = (ud_arr**)test->val;
    // val[0] = before_test;
    // val[1] = splitted;
    // printf("manual:\n");
    // ud_arr_print(test, char, "|%c| ");
    // ud_arr_rfree(test);
    // // ud_arr *test_set = ud_arr_set(int, 2, 3);
    // // ud_arr_print(test_set, int, "%d ");

    // ud_stra_test_tmp();

    // ud_arr *test_join_in = ud_arr_tset(ud_arr*, ud_arr_type_arr(), ud_stra_snew("salut"), ud_stra_snew("ca va"));
    ud_arr *test_join_in = ud_arr_set(ud_arr*, ud_stra_snew("salut"), ud_stra_snew("ca va"), ud_stra_snew("oui"));
    ud_arr_print(test_join_in);
    ud_arr *test_join = ud_stra_fjoin(test_join_in, ", ");
    // ud_arr_print(test_join_in);
    ud_arr_print(test_join);
    // ud_arr_free(test_join_in);
    ud_arr_free(test_join);

    char *str = ud_str_dup("ccss12,123;1234,12345ccss");
    ud_arr *test = ud_arr_new(char, ud_str_len(str), str);
    ud_arr *splitted = ud_stra_vrsplit(test, ";", ",");
    ud_arr_free(test);
    ud_arr_print(splitted);
    // ud_stra_vtrim(splitted, "cc", "ss");
    ud_arr *splitted_cpy = ud_stra_vctrim(splitted, "cc", "ss");
    // ud_arr *splitted_cpy = ud_arr_cpy(splitted);
    // ud_arr_print(splitted);
    // ud_stra_vtrim(splitted_cpy, "cc", "ss");
    ud_arr_print(splitted_cpy);
    ud_arr_free(splitted_cpy);

    printf("test join\n");
    ud_arr *test_join_split = ud_stra_vrjoin(splitted, ";", ",");

    printf("test join\n");
    ud_arr_print(test_join_split);
    ud_arr_print(splitted);

    // printf("test = |%s|\n", (char*)test_join_split->val);
    ud_arr_free(splitted);
    ud_arr_free(test_join_split);
    // ud_ut_free(str);

    // ud_arr *joined = ud_stra_vrjoin(splitted, ";", ",");
    // ud_arr_print(joined);
    ud_arr *str2 = ud_stra_snew("salut");
    ud_arr *splitted2 = ud_stra_split(str2, NULL);
    ud_arr_print(splitted2);
    ud_arr *joined2 = ud_stra_join(splitted2, "");
    ud_arr_print(joined2);
    ud_arr_free(splitted2);
    ud_arr_free(joined2);
    ud_arr_free(str2);

    // ud_arr_print(ud_stra_set('c', 'a'));
    
    // ud_arr *test_vjoin = ud_stra_vjoin(",", "salut", "ca va");
    // ud_arr_print(test_vjoin);
    // ud_arr_free(test_vjoin);

    // ud_arr_free(joined);
    // ud_arr_free(splitted);
    printf("TEST CONVERTER\n");
    ud_arr *c1 = ud_arr_set(ud_arr*, ud_stra_snew("test"), ud_stra_snew("test2"), ud_stra_snew("test3"));
    ud_arr *c2 = ud_arr_set(ud_arr*, ud_stra_snew("test"), ud_stra_snew("test2"), ud_stra_snew("test3"));
    ud_arr *mainc = ud_arr_set(ud_arr*, c1, c2);
    ud_arr_print(mainc);
    ud_stra_arr_to_char_p_arr(mainc);
    printf("CONVERTED\n");
    ud_arr_print(mainc);
    printf("BACK\n");
    ud_stra_arr_from_char_p_arr(mainc);
    ud_arr_print(mainc);
    ud_arr_free(mainc);
    return 0;
}