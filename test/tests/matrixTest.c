#include "unity.h"
#include "../../src/helper/matrix.h"


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testMatrixCreation() {
    Matrix4 matrix4 = {
            {1, 2, 3, 4},
            {5.5f, 6.5f, 7.5f},
            {9, 10, 11, 12},
            {13.5f, 14.5f, 15.5f, 16.5f}
    };

    TEST_ASSERT_TRUE(equalF32(matrix4[0][0],1));
    TEST_ASSERT_TRUE(equalF32(matrix4[0][3],4));
    TEST_ASSERT_TRUE(equalF32(matrix4[1][0],5.5f));
    TEST_ASSERT_TRUE(equalF32(matrix4[1][2], 7.5f));
    TEST_ASSERT_TRUE(equalF32(matrix4[2][2], 11));
    TEST_ASSERT_TRUE(equalF32(matrix4[3][0],13.5));
    TEST_ASSERT_TRUE(equalF32(matrix4[3][2], 15.5f));

}

void testMatrixMul(){
    Matrix4 a = {
            {1,2,3,4},
            {5,6,7,8},
            {9,8,7,6},
            {5,4,3,2}
    };

    Matrix4 b = {
            {-2,1,2,3},
            {3,2,1,-1},
            {4,3,6,5},
            {1,2,7,8}
    };

    Matrix4 c;

    mulMatrix4(a,b,c);

    Matrix4 res = {
            {20,22,50,48},
            {44,54,114,108},
            {40,58,110,102},
            {16,26,46,42},
    };

    TEST_ASSERT_TRUE(equalMatrix4(res,c));
}