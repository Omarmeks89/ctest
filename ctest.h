#ifndef _CTEST_H
#define _CTEST_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PASSED "PASSED"
#define FAILED "FAILED"
#define EXPECTED "EXPECTED: "
#define GOT "GOT: "
#define LINE_STR "LINE: "

/* extension for floating point */
#define EPSILON "EPS.: "

/* section of spaces and
 * puctuation symbols. */
#define SINGLE_SPACE " "
#define COMMA_SPACE ", "
#define SINGLE_POINT "."

/* brackets */
#define SQR_BRACKET_OPEN "["
#define SQR_BRACKET_CLOSE "]"

#define RND_BRACKET_OPEN "("
#define RND_BRACKET_CLOSE ")"

/* special symbols and
 * formatting symbols */
#define FNAME_OFFSET "%-32s"
#define LINE_NO_FMT "%6d"
#define TEST_STATUS_OFFSET "%32s"
#define TEST_STATUS_OFFSET_DBL "%8s"

#ifndef INT32_FMT_TEMPL
#  define INT32_FMT_TEMPL "%8d"
#endif

#ifndef INT64_FMT_TEMPL
#  define INT64_FMT_TEMPL "%16ld"
#endif

#ifndef DBL_FMT_TEMPL
#  define DBL_FMT_TEMPL "%10.6lf"
#endif

#ifndef DBL_EPS_TOLERANCE
#  define DBL_EPS_TOLERANCE "%10.9lf"
#endif

#ifndef PTR_FMT_TEMPL
#  define PTR_FMT_TEMPL "%8p"
#endif

#define _T_EOL "\n"

/* macro-template for passed test message 
 * Params:
 *   __type: format string with arg type
 *           that used in 'printf' function.
 *           Example:
 *             - '%6d'
 *
 * Returns:
 *   Joined literal with format directives. */
#define _PASS_MSG(__type) (             \
        FNAME_OFFSET                    \
        SINGLE_SPACE                    \
        SQR_BRACKET_OPEN                \
        EXPECTED                        \
        __type                          \
        COMMA_SPACE                     \
        GOT                             \
        __type                          \
        SQR_BRACKET_CLOSE               \
        TEST_STATUS_OFFSET              \
        SINGLE_POINT                    \
        _T_EOL)

/* macro-template for failed test message 
 * Params:
 *   __type: format string with arg type
 *           that used in 'printf' function.
 *           Example:
 *             - '%6d'
 *
 * Returns:
 *   Joined literal with format directives. */
#define _FAIL_MSG(__type) (             \
        FNAME_OFFSET                    \
        SINGLE_SPACE                    \
        RND_BRACKET_OPEN                \
        LINE_STR                        \
        LINE_NO_FMT                     \
        RND_BRACKET_CLOSE               \
        SINGLE_SPACE                    \
        SQR_BRACKET_OPEN                \
        EXPECTED                        \
        __type                          \
        COMMA_SPACE                     \
        GOT                             \
        __type                          \
        SQR_BRACKET_CLOSE               \
        TEST_STATUS_OFFSET              \
        SINGLE_POINT                    \
        _T_EOL)

/* macro-template for passed test message 
 * (use with floating point values).
 * Params:
 *   __type:    format string with arg type
 *              that used in 'printf' function.
 *              Example:
 *                - '%6d'
 *
 *   __eps_tol: epsilon tolerance for
 *              additional result control.
 *              (use DBL_e_X macro)
 *
 * Returns:
 *   Joined literal with format directives. */
#define _PASS_MSG_DBL(__type, __eps_tol) (          \
        FNAME_OFFSET                                \
        SINGLE_SPACE                                \
        SQR_BRACKET_OPEN                            \
        EXPECTED                                    \
        __type                                      \
        COMMA_SPACE                                 \
        GOT                                         \
        __type                                      \
        COMMA_SPACE                                 \
        EPSILON                                     \
        __eps_tol                                   \
        SQR_BRACKET_CLOSE                           \
        TEST_STATUS_OFFSET_DBL                      \
        SINGLE_POINT                                \
        _T_EOL)

/* macro-template for fail test message 
 * (use with floating point values).
 * Params:
 *   __type:    format string with arg type
 *              that used in 'printf' function.
 *              Example:
 *                - '%6d'
 *
 *   __eps_tol: epsilon tolerance for
 *              additional result control.
 *              (use DBL_e_X macro)
 *
 * Returns:
 *   Joined literal with format directives. */
#define _FAIL_MSG_DBL(__type, __eps_tol) (          \
        FNAME_OFFSET                                \
        SINGLE_SPACE                                \
        RND_BRACKET_OPEN                            \
        LINE_STR                                    \
        LINE_NO_FMT                                 \
        RND_BRACKET_CLOSE                           \
        SINGLE_SPACE                                \
        SQR_BRACKET_OPEN                            \
        EXPECTED                                    \
        __type                                      \
        COMMA_SPACE                                 \
        GOT                                         \
        __type                                      \
        COMMA_SPACE                                 \
        EPSILON                                     \
        __eps_tol                                   \
        SQR_BRACKET_CLOSE                           \
        TEST_STATUS_OFFSET_DBL                      \
        SINGLE_POINT                                \
        _T_EOL)

/* macro for set message about test pass.
 * Params:
 *   __type: format string with arg type
 *           that used in 'printf' function.
 *           Example:
 *             - '%6d';
 *   FN:     function name;
 *   E:      Expected value;
 *   G:      Got value. */
#define TEST_PASSED_MSG(__type, FN, E, G) (printf(_PASS_MSG(__type), #FN, E, G, PASSED))

/* macro for set message about test pass.
 * (use with floating point values).
 * Params:
 *   __type: format string with arg type
 *           that used in 'printf' function.
 *           Example:
 *             - '%6d';
 *   FN:     function name;
 *   E:      Expected value;
 *   G:      Got value;
 *   EPS:    current floating point tolerance. */
#define TEST_PASSED_MSG_DBL(__type, FN, E, G, EPS) (printf(_PASS_MSG_DBL(__type, DBL_EPS_TOLERANCE), \
                                                    #FN, E, G, EPS, PASSED))

/* macro for set message about test fail.
 * Params:
 *   __type: format string with arg type
 *           that used in 'printf' function.
 *           Example:
 *             - '%6d';
 *   FN:     function name;
 *   LN:    line no for found failed test case;
 *   E:      Expected value;
 *   G:      Got value. */
#define TEST_FAILED_MSG(__type, FN, LN, E, G) (printf(_FAIL_MSG(__type), #FN, LN, E, G, FAILED))

/* macro for set message about test fail.
 * (use with floating point values).
 * Params:
 *   __type: format string with arg type
 *           that used in 'printf' function.
 *           Example:
 *             - '%6d';
 *   FN:     function name;
 *   LN:    line no for found failed test case;
 *   E:      Expected value;
 *   G:      Got value;
 *   EPS:    current floating point tolerance. */
#define TEST_FAILED_MSG_DBL(__type, FN, LN, E, G, EPS) (printf(_FAIL_MSG_DBL(__type, DBL_EPS_TOLERANCE), \
                                                        #FN, LN, E, G, EPS, FAILED))

/* custom epsilons */
#define DBL_e_9 1e-9
#define DBL_e_8 1e-8
#define DBL_e_7 1e-7
#define DBL_e_6 1e-6
#define DBL_e_5 1e-5
#define DBL_e_4 1e-4
#define DBL_e_3 1e-3
#define DBL_e_2 1e-2
#define DBL_e_1 1e-1

/* type casting */
#define __eq_int32(a, b) ((int) a == (int) b)

#define __ne_int32(a, b) ((int) a != (int) b)

#define __eq_double64(a, b, eps) ((fabs((double) a - (double) b) <= (double) eps))

#define __ne_double64(a, b, eps) ((fabs((double) a - (double) b) > (double) eps))

#define __eq_null_ptr(a) ((void *) a == NULL)

#define __ne_null_ptr(a) ((void *) a != NULL)

#define LINE() (__LINE__)

/* TODO: separate success checks into own macro. */

/* ASSERT_EQ_PTR_NULL check that pointer is eq to NULL */
#define ASSERT_EQ_PTR_NULL(RES, EXP, F_NAME, LINE)                      \
    {                                                                   \
        int success = 0;                                                \
        success = __eq_null_ptr(RES);                                   \
        if (success) {                                                  \
            TEST_PASSED_MSG(PTR_FMT_TEMPL, F_NAME, EXP, RES);           \
        } else {                                                        \
            TEST_FAILED_MSG(PTR_FMT_TEMPL, F_NAME, LINE, EXP, RES);     \
            abort();                                                    \
        }                                                               \

#define ASSERT_NE_PTR_NULL(RES, EXP, F_NAME, LINE)                      \
    {                                                                   \
        int success = 0;                                                \
        success = __ne_null_ptr(RES);                                   \
        if (success) {                                                  \
            TEST_PASSED_MSG(PTR_FMT_TEMPL, F_NAME, EXP, RES);           \
        } else {                                                        \
            TEST_FAILED_MSG(PTR_FMT_TEMPL, F_NAME, LINE, EXP, RES);     \
            abort();                                                    \
        }                                                               \

#define EXPECT_EQ_PTR_NULL(RES, EXP, F_NAME, STATE, LINE)               \
    {                                                                   \
        int success = 0;                                                \
        success = __eq_null_ptr(RES, EXP);                              \
        if (success) {                                                  \
            TEST_PASSED_MSG(PTR_FMT_TEMPL, F_NAME, EXP, RES);           \
        } else {                                                        \
            TEST_FAILED_MSG(PTR_FMT_TEMPL, F_NAME, LINE, EXP, RES);     \
        }                                                               \
        *STATE = success;                                               \
    }


/* ASSERT_EQ check that two args are equal
 * or will abort execution. */
#define ASSERT_EQ_INT32(RES, EXP, F_NAME, LINE)                         \
    {                                                                   \
        int success = 0;                                                \
        success = __eq_int32(RES, EXP);                                 \
        if (success) {                                                  \
            TEST_PASSED_MSG(INT32_FMT_TEMPL, F_NAME, EXP, RES);         \
        } else {                                                        \
            TEST_FAILED_MSG(INT32_FMT_TEMPL, F_NAME, LINE, EXP, RES);   \
            abort();                                                    \
        }                                                               \
    }

#define ASSERT_NE_INT32(RES, EXP, F_NAME, LINE)                         \
    {                                                                   \
        int success = 0;                                                \
        success = __ne_int32(RES, EXP);                                 \
        if (success) {                                                  \
            TEST_PASSED_MSG(INT32_FMT_TEMPL, F_NAME, EXP, RES);         \
        } else {                                                        \
            TEST_FAILED_MSG(INT32_FMT_TEMPL, F_NAME, LINE, EXP, RES);   \
            abort();                                                    \
        }                                                               \
    }

/* will not abort() routine execution, only
 * write to stderr about test failure or success. */
#define EXPECT_EQ_INT32(RES, EXP, F_NAME, STATE, LINE)                  \
    {                                                                   \
        int success = 0;                                                \
        success = __eq_int32(RES, EXP);                                 \
        if (success) {                                                  \
            TEST_PASSED_MSG(INT32_FMT_TEMPL, F_NAME, EXP, RES);         \
        } else {                                                        \
            TEST_FAILED_MSG(INT32_FMT_TEMPL, F_NAME, LINE, EXP, RES);   \
        }                                                               \
        *STATE = success;                                               \
    }

#define EXPECT_NE_INT32(RES, EXP, F_NAME, STATE, LINE)                  \
    {                                                                   \
        int success = 0;                                                \
        success = __ne_int32(RES, EXP);                                 \
        if (success) {                                                  \
            TEST_PASSED_MSG(INT32_FMT_TEMPL, F_NAME, EXP, RES);         \
        } else {                                                        \
            TEST_FAILED_MSG(INT32_FMT_TEMPL, F_NAME, LINE, EXP, RES);   \
        }                                                               \
        *STATE = success;                                               \
    }

/* assert to double */
#define ASSERT_EQ_DBL(RES, EXP, EPSILON, F_NAME, LINE)                  \
    {                                                                   \
        int success = 0;                                                \
        success = __eq_double64(RES, EXP, EPSILON);                     \
        if (success) {                                                  \
            TEST_PASSED_MSG_DBL(DBL_FMT_TEMPL, F_NAME, EXP, RES, EPSILON);           \
        } else {                                                        \
            TEST_FAILED_MSG_DBL(DBL_FMT_TEMPL, F_NAME, LINE, EXP, RES, EPSILON);     \
            abort();                                                    \
        }                                                               \
    }

#define ASSERT_NE_DBL(RES, EXP, EPSILON, F_NAME, LINE)                  \
    {                                                                   \
        int success = 0;                                                \
        success = __ne_double64(RES, EXP, EPSILON);                     \
        if (success) {                                                  \
            TEST_PASSED_MSG_DBL(DBL_FMT_TEMPL, F_NAME, EXP, RES, EPSILON);           \
        } else {                                                        \
            TEST_FAILED_MSG_DBL(DBL_FMT_TEMPL, F_NAME, LINE, EXP, RES, EPSILON);     \
            abort();                                                    \
        }                                                               \
    }

/* EXPECT waiting for pointer for test result */
#define EXPECT_EQ_DBL(RES, EXP, STATE, EPSILON, F_NAME, LINE)           \
    {                                                                   \
        int success = 0;                                                \
        success = __eq_double64(RES, EXP, EPSILON);                     \
        if (success) {                                                  \
            TEST_PASSED_MSG_DBL(DBL_FMT_TEMPL, F_NAME, EXP, RES, EPSILON);           \
        } else {                                                        \
            TEST_FAILED_MSG_DBL(DBL_FMT_TEMPL, F_NAME, LINE, EXP, RES, EPSILON);     \
        }                                                               \
        *STATE = success;                                               \
    }

#define EXPECT_NE_DBL(RES, EXP, STATE, EPSILON, F_NAME, LINE)           \
    {                                                                   \
        int success = 0;                                                \
        success = __ne_double64(RES, EXP, EPSILON);                     \
        if (success) {                                                  \
            TEST_PASSED_MSG_DBL(DBL_FMT_TEMPL, F_NAME, EXP, RES, EPSILON);           \
        } else {                                                        \
            TEST_FAILED_MSG_DBL(DBL_FMT_TEMPL, F_NAME, LINE, EXP, RES, EPSILON);     \
        }                                                               \
        *STATE = success;                                               \
    }

#endif /* _CTEST_H */
