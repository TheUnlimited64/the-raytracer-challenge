/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);

extern void tearDown(void);

extern void testEquality(void);

extern void testAddition(void);

extern void testSubtractionOfPoints(void);

extern void testSubtractionVectorFromPoint(void);

extern void testSubtractionOfVector(void);

extern void testNegation(void);

extern void testMulScalarTuple(void);

extern void testDivScalarTuple(void);

extern void testNormalization(void);

extern void testMagnitudeOfNormalizedVector(void);

extern void testCrossTuple(void);


/*=======Test Reset Option=====*/
void resetTest(void);

void resetTest(void) {
    tearDown();
    setUp();
}


/*=======MAIN=====*/
int asd(void) {
    UnityBegin("test/tests/testTuple.c");
    RUN_TEST(testEquality, 1);
    RUN_TEST(testAddition, 2);
    RUN_TEST(testSubtractionOfPoints, 2);
    RUN_TEST(testSubtractionVectorFromPoint, 2);
    RUN_TEST(testSubtractionOfVector, 2);
    RUN_TEST(testMulScalarTuple, 2);
    RUN_TEST(testDivScalarTuple, 2);
    RUN_TEST(testNormalization, 2);
    RUN_TEST(testMagnitudeOfNormalizedVector, 2);
    RUN_TEST(testNegation, 2);
    RUN_TEST(testCrossTuple,1);

    return (UnityEnd());
}