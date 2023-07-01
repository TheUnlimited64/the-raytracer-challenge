#include "unity.h"
#include "../../src/helper/tuple.h"
#include "../../src/color.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testEquality(void) {
    Tuple a = {0, 0, 0, 0};
    Tuple b = {0, 0, 0, 0};
    TEST_ASSERT_TRUE(equalTuple(a, b));
}

void testAddition(void) {
    Tuple a = {3, -2, 5, 1};
    Tuple b = {-2, 3, 1, 0};
    Tuple expected = {1, 1, 6, 1};
    TEST_ASSERT_TRUE(equalTuple(addTuple(a, b), expected));
}

void testSubtractionOfPoints(void) {
    Tuple a = createPoint(3, 2, 1);
    Tuple b = createPoint(5, 6, 7);
    Tuple expected = createVector(-2, -4, -6);
    Tuple res = subTuple(a, b);
    TEST_ASSERT_TRUE(equalTuple(res, expected));
}

void testSubtractionVectorFromPoint(void) {
    Tuple a = createPoint(3, 2, 1);
    Tuple b = createVector(5, 6, 7);
    Tuple expected = createPoint(-2, -4, -6);
    Tuple res = subTuple(a, b);
    TEST_ASSERT_TRUE(equalTuple(res, expected));
}

void testSubtractionOfVector(void) {
    Tuple a = createVector(3, 2, 1);
    Tuple b = createVector(5, 6, 7);
    Tuple expected = createVector(-2, -4, -6);
    Tuple res = subTuple(a, b);
    TEST_ASSERT_TRUE(equalTuple(expected, res));
}

void testNegation(void) {
    Tuple a = {1, -2, 3, -4};
    Tuple expected = {-1, 2, -3, 4};
    Tuple res = negateTuple(a);
    TEST_ASSERT_TRUE(equalTuple(res, expected));
}

void testMulScalarTuple(void) {
    Tuple a = {1, -2, 3, -4};
    f32_t scalar = 3.5f;
    Tuple expected = {3.5f, -7, 10.5f, -14};
    Tuple res = mulScalarTuple(a, scalar);
    TEST_ASSERT_TRUE(equalTuple(res, expected));
}

void testDivScalarTuple(void) {
    Tuple a = {1, -2, 3, -4};
    f32_t scalar = 2;
    Tuple expected = {0.5f, -1, 1.5f, -2};
    Tuple res = divScalarTuple(a, scalar);
    TEST_ASSERT_TRUE(equalTuple(res, expected));
}

void testNormalization(void) {
    Tuple a = createVector(4, 0, 0);
    Tuple expected = createVector(1, 0, 0);
    Tuple res = normalizeTuple(a);
    TEST_ASSERT_TRUE(equalTuple(res, expected));
}

void testMagnitudeOfNormalizedVector(void) {
    Tuple a = createVector(1, 2, 3);
    Tuple normalized = normalizeTuple(a);
    f32_t magnitude = magnitudeTuple(normalized);

    TEST_ASSERT_TRUE(equalF32(magnitude, 1));
}

void testCrossTuple(void) {
    Tuple a = createVector(1, 2, 3);
    Tuple b = createVector(2, 3, 4);
    Tuple expected = createVector(-1, 2, -1);
    Tuple res = crossTuple(a, b);
    TEST_ASSERT_TRUE(equalTuple(res, expected));
    expected = divScalarTuple(expected, -1);
    res = crossTuple(b, a);
    TEST_ASSERT_TRUE(equalTuple(res, expected));
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testEquality);
    RUN_TEST(testAddition);
    RUN_TEST(testSubtractionOfPoints);
    RUN_TEST(testSubtractionVectorFromPoint);
    RUN_TEST(testSubtractionOfVector);
    RUN_TEST(testNegation);
    RUN_TEST(testMulScalarTuple);
    RUN_TEST(testDivScalarTuple);
    RUN_TEST(testNormalization);
    RUN_TEST(testMagnitudeOfNormalizedVector);
    RUN_TEST(testCrossTuple);
    return UNITY_END();
}