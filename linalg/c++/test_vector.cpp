#include <gtest/gtest.h>
#include <iostream>
#include "vector.h"

TEST(Vector, BasicAssertions)
{
    Vector<int> *vec_null = new Vector<int>;
    EXPECT_EQ(vec_null->size(), 0);
    delete vec_null;
    
    Vector<int> *vec_null0 = new Vector<int>();
    EXPECT_EQ(vec_null0->size(), 0);
    delete vec_null0;

    Vector<int> *vec = new Vector<int>(5);
    EXPECT_EQ(vec->size(), 5);
    
    Vector<int> vec1(5, 5);
    EXPECT_EQ(vec1.size(), 5);
    EXPECT_EQ(vec1[3], 5);

    Vector<int> vec2(5, 3);
    vec1 = vec2;
    EXPECT_EQ(vec1[3], 3);

}

int main(int argc, char **argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
