#include <stdio.h>
#include <stdlib.h>

#include <nginx.h>
#include <ngx_core.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "defines.h"

int main (int argc, char *argv[])
{
    CU_pSuite suite_libngxcore;
    char *verbose_s;
    int verbose;

    if (CU_initialize_registry() != CUE_SUCCESS) {
        return 1;
    }

    suite_libngxcore = CU_add_suite("libngxcore", NULL, NULL);

    /* string */
    CU_add_test(suite_libngxcore, "string_test001", string_test001);

    /* array */
    CU_add_test(suite_libngxcore, "array_test001", array_test001);

    /* pool */
    CU_add_test(suite_libngxcore, "pool_test001", pool_test001);

    /* time */
    CU_add_test(suite_libngxcore, "time_test001", time_test001);

    /* list */
    CU_add_test(suite_libngxcore, "list_test001", list_test001);

    /* parse */
    CU_add_test(suite_libngxcore, "parse_test001", parse_test001);

    /* version */
    CU_add_test(suite_libngxcore, "version_test001", version_test001);

    /* regex */
    CU_add_test(suite_libngxcore, "regex_test001", regex_test001);

    /* base64 */
    CU_add_test(suite_libngxcore, "base64_test001", base64_test001);

    /* crc32 */
    CU_add_test(suite_libngxcore, "crc32_test001", crc32_test001);

    /* md5 */
    CU_add_test(suite_libngxcore, "md5_test001", md5_test001);

    /* sha1 */
    CU_add_test(suite_libngxcore, "sha1_test001", sha1_test001);

    verbose_s = getenv("VERBOSE");
    verbose = (verbose_s == NULL) ? 0 : verbose_s[0] == '1';
    if (verbose) {
        CU_basic_set_mode(CU_BRM_VERBOSE);
    }

    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
