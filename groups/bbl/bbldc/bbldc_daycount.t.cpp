// bbldc_daycount.t.cpp                                               -*-C++-*-

#include <bbldc_daycount.h>

#include <bdls_testutil.h>

#include <bdlt_date.h>

#include <bsls_asserttest.h>

#include <bsl_cstdlib.h>     // atoi()
#include <bsl_iostream.h>

using namespace BloombergLP;
using namespace bsl;


// ============================================================================
//                              TEST PLAN
// ----------------------------------------------------------------------------
//                              Overview
//                              --------
// The component under test consists of static member functions that compute
// the day and year difference between two dates for a specified convention.
// The standard table-based test case implementation is used to verify the
// functionality of these methods.
// ----------------------------------------------------------------------------
// [ 1] int daysDiff(beginDate, endDate, convention);
// [ 2] double yearsDiff(beginDate, endDate, convention);
// ----------------------------------------------------------------------------
// [ 3] USAGE EXAMPLE
// ----------------------------------------------------------------------------

// ============================================================================
//                     STANDARD BDE ASSERT TEST FUNCTION
// ----------------------------------------------------------------------------

namespace {

int testStatus = 0;

void aSsErT(bool condition, const char *message, int line)
{
    if (condition) {
        cout << "Error " __FILE__ "(" << line << "): " << message
             << "    (failed)" << endl;

        if (0 <= testStatus && testStatus <= 100) {
            ++testStatus;
        }
    }
}

}  // close unnamed namespace

// ============================================================================
//               STANDARD BDE TEST DRIVER MACRO ABBREVIATIONS
// ----------------------------------------------------------------------------

#define ASSERT       BDLS_TESTUTIL_ASSERT
#define ASSERTV      BDLS_TESTUTIL_ASSERTV

#define LOOP_ASSERT  BDLS_TESTUTIL_LOOP_ASSERT
#define LOOP0_ASSERT BDLS_TESTUTIL_LOOP0_ASSERT
#define LOOP1_ASSERT BDLS_TESTUTIL_LOOP1_ASSERT
#define LOOP2_ASSERT BDLS_TESTUTIL_LOOP2_ASSERT
#define LOOP3_ASSERT BDLS_TESTUTIL_LOOP3_ASSERT
#define LOOP4_ASSERT BDLS_TESTUTIL_LOOP4_ASSERT
#define LOOP5_ASSERT BDLS_TESTUTIL_LOOP5_ASSERT
#define LOOP6_ASSERT BDLS_TESTUTIL_LOOP6_ASSERT

#define Q            BDLS_TESTUTIL_Q   // Quote identifier literally.
#define P            BDLS_TESTUTIL_P   // Print identifier and value.
#define P_           BDLS_TESTUTIL_P_  // P(X) without '\n'.
#define T_           BDLS_TESTUTIL_T_  // Print a tab (w/o newline).
#define L_           BDLS_TESTUTIL_L_  // current Line number

// ============================================================================
//                  NEGATIVE-TEST MACRO ABBREVIATIONS
// ----------------------------------------------------------------------------

#define ASSERT_SAFE_PASS(EXPR) BSLS_ASSERTTEST_ASSERT_SAFE_PASS(EXPR)
#define ASSERT_SAFE_FAIL(EXPR) BSLS_ASSERTTEST_ASSERT_SAFE_FAIL(EXPR)
#define ASSERT_PASS(EXPR)      BSLS_ASSERTTEST_ASSERT_PASS(EXPR)
#define ASSERT_FAIL(EXPR)      BSLS_ASSERTTEST_ASSERT_FAIL(EXPR)
#define ASSERT_OPT_PASS(EXPR)  BSLS_ASSERTTEST_ASSERT_OPT_PASS(EXPR)
#define ASSERT_OPT_FAIL(EXPR)  BSLS_ASSERTTEST_ASSERT_OPT_FAIL(EXPR)

// ============================================================================
//                  GLOBAL TYPEDEFS/CONSTANTS FOR TESTING
// ----------------------------------------------------------------------------

typedef bbldc::DayCount Obj;

const bbldc::DayCountConvention::Enum ACTUAL_360 =
                                       bbldc::DayCountConvention::e_ACTUAL_360;
const bbldc::DayCountConvention::Enum ACTUAL_365_FIXED =
                                 bbldc::DayCountConvention::e_ACTUAL_365_FIXED;
const bbldc::DayCountConvention::Enum ISDA_ACTUAL_ACTUAL =
                               bbldc::DayCountConvention::e_ISDA_ACTUAL_ACTUAL;
const bbldc::DayCountConvention::Enum ISMA_30_360 =
                                      bbldc::DayCountConvention::e_ISMA_30_360;
const bbldc::DayCountConvention::Enum PSA_30_360_EOM =
                                   bbldc::DayCountConvention::e_PSA_30_360_EOM;
const bbldc::DayCountConvention::Enum SIA_30_360_EOM =
                                   bbldc::DayCountConvention::e_SIA_30_360_EOM;
const bbldc::DayCountConvention::Enum SIA_30_360_NEOM =
                                  bbldc::DayCountConvention::e_SIA_30_360_NEOM;

//=============================================================================
//                              MAIN PROGRAM
//-----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    int test = argc > 1 ? atoi(argv[1]) : 0;
    int verbose = argc > 2;
    int veryVerbose = argc > 3;

    cout << "TEST " << __FILE__ << " CASE " << test << endl;

    switch (test) { case 0:
      case 3: {
        // --------------------------------------------------------------------
        // USAGE EXAMPLE
        //   Extracted from component header file.
        //
        // Concerns:
        //: 1 The usage example provided in the component header file compiles,
        //:   links, and runs as shown.
        //
        // Plan:
        //: 1 Incorporate usage example from header into test driver, remove
        //:   leading comment characters, and replace 'assert' with 'ASSERT'.
        //:   (C-1)
        //
        // Testing:
        //   USAGE EXAMPLE
        // --------------------------------------------------------------------

        if (verbose) cout << endl
                          << "USAGE EXAMPLE" << endl
                          << "=============" << endl;

///Usage
///-----
// This section illustrates intended use of this component.
//
///Example 1: Computing Day-Count and Year-Fraction
///- - - - - - - - - - - - - - - - - - - - - - - -
// The following snippets of code illustrate how to use
// 'bbldcu::IsdaActualActual' methods.  First, create two 'bdlt::Dates' 'd1'
// and 'd2':
//..
    const bdlt::Date d1(2003, 10, 19);
    const bdlt::Date d2(2003, 12, 31);
//..
// Then, compute the day-count between these two dates according to the ISDA
// Actual/Actual convention:
//..
    const int daysDiff = bbldc::DayCount::daysDiff(
                              d1,
                              d2,
                              bbldc::DayCountConvention::e_ISDA_ACTUAL_ACTUAL);
    ASSERT(73 == daysDiff);
//..
// Finally, compute the year fraction between these two dates according to the
// ISDA Actual/Actual convention:
//..
    const double yearsDiff = bbldc::DayCount::yearsDiff(
                              d1,
                              d2,
                              bbldc::DayCountConvention::e_ISDA_ACTUAL_ACTUAL);
//  // Need fuzzy comparison since 'yearsDiff' is a double.  Expect
//  // '0.2 == yearsDiff'.
    ASSERT(0.1999 < yearsDiff);
    ASSERT(0.2001 > yearsDiff);
//..
      } break;
      case 2: {
        // --------------------------------------------------------------------
        // TESTING 'yearsDiff'
        //   Verify the method correctly computes the number of years between
        //   two dates for the provided convention.
        //
        // Concerns:
        //: 1 The 'yearsDiff' method produces the correct results for the
        //:   provided convention.
        //:
        //: 2 QoI: Asserted precondition violations are detected when enabled.
        //
        // Plan:
        //: 1 Specify a set S of {convention C, pairs of dates (d1, d2), and
        //:   their difference in years D}.  For the method under test, in a
        //:   loop over the elements of S, apply the method to dates having the
        //:   values d1 and d2 using convention C and confirm the result using
        //:   the value D with a fuzzy comparison (since the return value is a
        //:   floating point number).  (C-1)
        //:
        //: 2 Verify defensive checks are triggered for invalid values.  (C-2)
        //
        // Testing:
        //   double yearsDiff(beginDate, endDate, convention);
        // --------------------------------------------------------------------


        if (verbose) cout << endl
                          << "TESTING 'yearsDiff'" << endl
                          << "===================" << endl;

        {
            static const struct {
                int    d_lineNum;                       // source line number

                bbldc::DayCountConvention::Enum d_type; // convention to use

                int    d_year1;                         // beginDate year
                int    d_month1;                        // beginDate month
                int    d_day1;                          // beginDate day
                int    d_year2;                         // endDate year
                int    d_month2;                        // endDate month
                int    d_day2;                          // endDate day
                double d_numYears;                      // result # of years
            } DATA[] = {

    //                          - - -first - - -  - - - second - -
    //line  type                year  mnth  day  year  mnth  day  numYears
    //----  ------------------  ----  ----  ---  ----  ----  ---  --------
    { L_,   ACTUAL_360,         1993,   12,  15, 1993,   12,  31, 0.0444444 },
    { L_,   ACTUAL_360,         2003,    2,  28, 2004,    2,  29, 1.01667   },

    { L_,   ACTUAL_365_FIXED,   1993,   12,  15, 1993,   12,  31, 0.0438356 },
    { L_,   ACTUAL_365_FIXED,   2003,    2,  28, 2004,    2,  29, 1.00274   },

    { L_,   ISDA_ACTUAL_ACTUAL, 1993,   12,  15, 1993,   12,  31, 0.0438356 },
    { L_,   ISDA_ACTUAL_ACTUAL, 2003,    2,  28, 2004,    2,  29, 1.0023    },

    { L_,   ISMA_30_360,        1993,   12,  15, 1993,   12,  31, 0.0416667 },
    { L_,   ISMA_30_360,        2003,    2,  28, 2004,    2,  29, 1.00278   },

    { L_,   PSA_30_360_EOM,     1993,   12,  15, 1993,   12,  31, 0.0444444 },
    { L_,   PSA_30_360_EOM,     2003,    2,  28, 2004,    2,  29, 0.997222  },

    { L_,   SIA_30_360_EOM,     1993,   12,  15, 1993,   12,  31, 0.0444444 },
    { L_,   SIA_30_360_EOM,     2003,    2,  28, 2004,    2,  29, 1.0000    },

    { L_,   SIA_30_360_NEOM,    1993,   12,  15, 1993,   12,  31, 0.0444444 },
    { L_,   SIA_30_360_NEOM,    2003,    2,  28, 2004,    2,  29, 1.00278   },
            };

            const int NUM_DATA = sizeof DATA / sizeof *DATA;

            if (verbose) cout <<
                "\nTesting: 'yearsDiff(beginDate, endDate, type)'" << endl;

            // Ensure the test data differentiates each convention type.

            {
                for (int i = 0; i < NUM_DATA; ++i) {
                    const bbldc::DayCountConvention::Enum CONV1 =
                                                                DATA[i].d_type;
                    for (int j = i + 1; j < NUM_DATA; ++j) {
                        const bbldc::DayCountConvention::Enum CONV2 =
                                                                DATA[j].d_type;
                        if (CONV1 != CONV2) {
                            int hasUnique = 0;
                            for (int ii = 0; ii < NUM_DATA; ++ii) {
                                if (CONV1 == DATA[ii].d_type) {
                                  for (int jj = 0; jj < NUM_DATA; ++jj) {
                                      if (CONV2 == DATA[jj].d_type) {
                        //---------------^
                        if (DATA[ii].d_year1    == DATA[jj].d_year1 &&
                            DATA[ii].d_month1   == DATA[jj].d_month1 &&
                            DATA[ii].d_day1     == DATA[jj].d_day1 &&
                            DATA[ii].d_year2    == DATA[jj].d_year2 &&
                            DATA[ii].d_month2   == DATA[jj].d_month2 &&
                            DATA[ii].d_day2     == DATA[jj].d_day2 &&
                            DATA[ii].d_numYears != DATA[jj].d_numYears) {
                            hasUnique = 1;
                        }
                        //---------------v
                                      }
                                  }
                                }
                            }
                            if (!hasUnique && veryVerbose) {
                                bsl::cout << CONV1
                                          << " is not distinguished from "
                                          << CONV2 << bsl::endl;
                            }
                            LOOP2_ASSERT(CONV1, CONV2, hasUnique);
                        }
                    }
                }
            }

            int di;
            for (di = 0; di < NUM_DATA; ++di) {
                const int    LINE      = DATA[di].d_lineNum;
                const double NUM_YEARS = DATA[di].d_numYears;

                const bbldc::DayCountConvention::Enum CONV = DATA[di].d_type;

                bdlt::Date x(DATA[di].d_year1,
                             DATA[di].d_month1,
                             DATA[di].d_day1);

                const bdlt::Date& X = x;

                bdlt::Date y(DATA[di].d_year2,
                             DATA[di].d_month2,
                             DATA[di].d_day2);

                const bdlt::Date& Y = y;

                if (veryVerbose) {
                    T_ P_(X) P_(Y) P(CONV);
                    T_ T_ T_ T_ T_ T_ T_ P(NUM_YEARS);
                    T_ T_ T_ T_ T_ T_ T_;
                }

                const double RESULT = Obj::yearsDiff(X, Y, CONV);

                if (veryVerbose) { P(RESULT); }
                const double diff = NUM_YEARS - RESULT;
                LOOP3_ASSERT(LINE,
                             NUM_YEARS,
                             RESULT,
                             -0.00005 <= diff && diff <= 0.00005);
            }
        }

        { // negative testing
            bsls::AssertFailureHandlerGuard
                                          hG(bsls::AssertTest::failTestDriver);

            ASSERT_PASS(Obj::yearsDiff(
                                     bdlt::Date(1751, 1, 1),
                                     bdlt::Date(1751, 1, 1),
                                     bbldc::DayCountConvention::e_ACTUAL_360));

            ASSERT_FAIL(Obj::yearsDiff(
                                     bdlt::Date(1751, 1, 1),
                                     bdlt::Date(1752, 1, 1),
                                     bbldc::DayCountConvention::e_ACTUAL_360));

            ASSERT_FAIL(Obj::yearsDiff(
                                     bdlt::Date(1752, 1, 1),
                                     bdlt::Date(1753, 1, 1),
                                     bbldc::DayCountConvention::e_ACTUAL_360));

            ASSERT_PASS(Obj::yearsDiff(
                                     bdlt::Date(1753, 1, 1),
                                     bdlt::Date(1753, 1, 1),
                                     bbldc::DayCountConvention::e_ACTUAL_360));


            ASSERT_FAIL(Obj::yearsDiff(
                                     bdlt::Date(1752, 1, 1),
                                     bdlt::Date(1751, 1, 1),
                                     bbldc::DayCountConvention::e_ACTUAL_360));

            ASSERT_FAIL(Obj::yearsDiff(
                                     bdlt::Date(1753, 1, 1),
                                     bdlt::Date(1752, 1, 1),
                                     bbldc::DayCountConvention::e_ACTUAL_360));
        }
      } break;
      case 1: {
        // --------------------------------------------------------------------
        // TESTING 'daysDiff'
        //   Verify the method correctly computes the number of days between
        //   two dates for the provided convention.
        //
        // Concerns:
        //: 1 The 'daysDiff' method produces the correct results for the
        //:   provided convention.
        //
        // Plan:
        //: 1 Specify a set S of {convention C, pairs of dates (d1, d2), and
        //:   their difference in days D}.  For the method under test, in a
        //:   loop over the elements of S, apply the method to dates having the
        //:   values d1 and d2 using convention C and confirm the result using
        //:   the value D.  (C-1)
        //
        // Testing:
        //   int daysDiff(beginDate, endDate, convention);
        // --------------------------------------------------------------------

        if (verbose) cout << endl
                          << "TESTING 'daysDiff'" << endl
                          << "==================" << endl;

        {
            static const struct {
                int d_lineNum;                          // source line number

                bbldc::DayCountConvention::Enum d_type; // convention to use

                int d_year1;                            // beginDate year
                int d_month1;                           // beginDate month
                int d_day1;                             // beginDate day
                int d_year2;                            // endDate year
                int d_month2;                           // endDate month
                int d_day2;                             // endDate day
                int d_numDays;                          // result # of days
            } DATA[] = {

    //                          - - -first - - -  - - - second - -
    //line  type                year  month  day  year  month  day  numDays
    //----  ------------------  ----  -----  ---  ----  -----  ---  -------

    { L_,   ISDA_ACTUAL_ACTUAL, 1993,    12,  15, 1993,    12,  31,      16 },
    { L_,   ISDA_ACTUAL_ACTUAL, 2003,     2,  28, 2004,     2,  29,     366 },

    { L_,   ACTUAL_360,         1993,    12,  15, 1993,    12,  31,      16 },
    { L_,   ACTUAL_360,         2003,     2,  28, 2004,     2,  29,     366 },

    { L_,   ACTUAL_365_FIXED,   1993,    12,  15, 1993,    12,  31,      16 },
    { L_,   ACTUAL_365_FIXED,   2003,     2,  28, 2004,     2,  29,     366 },

    { L_,   ISMA_30_360,        1993,    12,  15, 1993,    12,  31,      15 },
    { L_,   ISMA_30_360,        2003,     2,  28, 2004,     2,  29,     361 },

    { L_,   SIA_30_360_EOM,     1993,    12,  15, 1993,    12,  31,      16 },
    { L_,   SIA_30_360_EOM,     2003,     2,  28, 2004,     2,  29,     360 },

    { L_,   SIA_30_360_NEOM,    1993,    12,  15, 1993,    12,  31,      16 },
    { L_,   SIA_30_360_NEOM,    2003,     2,  28, 2004,     2,  29,     361 },

    { L_,   PSA_30_360_EOM,     1993,    12,  15, 1993,    12,  31,      16 },
    { L_,   PSA_30_360_EOM,     2003,     2,  28, 2004,     2,  29,     359 },
            };

            const int NUM_DATA = sizeof DATA / sizeof *DATA;

            if (verbose) cout <<
                "\nTesting: 'daysDiff(beginDate, endDate, type)'" << endl;

            // Ensure the test data differentiates each convention type.  Note:
            // this part of the test is getting inappropriate as we add more
            // conventions, some of which count days identically.

            {
                for (int i = 0; i < NUM_DATA; ++i) {
                    const bbldc::DayCountConvention::Enum CONV1 =
                                                                DATA[i].d_type;
                    for (int j = i + 1; j < NUM_DATA; ++j) {
                        const bbldc::DayCountConvention::Enum CONV2 =
                                                                DATA[j].d_type;
                        if (CONV1 != CONV2) {
                            if (CONV1 == ACTUAL_360 ||
                                CONV1 == ACTUAL_365_FIXED ||
                                CONV2 == ACTUAL_360 ||
                                CONV2 == ACTUAL_365_FIXED) {
                                continue;
                            }

                            int hasUnique = 0;
                            for (int ii = 0; ii < NUM_DATA; ++ii) {
                                if (CONV1 == DATA[ii].d_type) {
                                  for (int jj = 0; jj < NUM_DATA; ++jj) {
                                      if (CONV2 == DATA[jj].d_type) {
                        //---------------^
                        if (DATA[ii].d_year1   == DATA[jj].d_year1 &&
                            DATA[ii].d_month1  == DATA[jj].d_month1 &&
                            DATA[ii].d_day1    == DATA[jj].d_day1 &&
                            DATA[ii].d_year2   == DATA[jj].d_year2 &&
                            DATA[ii].d_month2  == DATA[jj].d_month2 &&
                            DATA[ii].d_day2    == DATA[jj].d_day2 &&
                            DATA[ii].d_numDays != DATA[jj].d_numDays) {
                            hasUnique = 1;
                        }
                        //---------------v
                                      }
                                  }
                                }
                            }
                            if (!hasUnique && veryVerbose) {
                                bsl::cout << CONV1
                                          << " is not distinguished from "
                                          << CONV2 << bsl::endl;
                            }
                            LOOP2_ASSERT(CONV1, CONV2, hasUnique);
                        }
                    }
                }
            }

            int di;
            for (di = 0; di < NUM_DATA ; ++di) {
                const int LINE     = DATA[di].d_lineNum;
                const int NUM_DAYS = DATA[di].d_numDays;

                const bbldc::DayCountConvention::Enum CONV = DATA[di].d_type;

                bdlt::Date x(DATA[di].d_year1,
                             DATA[di].d_month1,
                             DATA[di].d_day1);

                const bdlt::Date& X = x;

                bdlt::Date y(DATA[di].d_year2,
                             DATA[di].d_month2,
                             DATA[di].d_day2);

                const bdlt::Date& Y = y;

                if (veryVerbose) {
                    T_ P_(X) P_(Y) P(CONV);
                    T_ T_ T_ T_ T_ T_ T_ P(NUM_DAYS);
                    T_ T_ T_ T_ T_ T_ T_;
                }

                const int RESULT = Obj::daysDiff(X, Y, CONV);

                if (veryVerbose) { P(RESULT); }
                LOOP_ASSERT(LINE, NUM_DAYS == RESULT);
            }
        }
      } break;
      default: {
        cerr << "WARNING: CASE `" << test << "' NOT == FOUND." << endl;
        testStatus = -1;
      }
    }

    if (testStatus > 0) {
        cerr << "Error, non-zero test status = " << testStatus << "." << endl;
    }
    return testStatus;
}

// ----------------------------------------------------------------------------
// Copyright 2015 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
