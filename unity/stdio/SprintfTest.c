#include "unity_fixture.h"
#include "stdio.h"
#include "string.h"

TEST_SETUP(sprintf)
{
}

TEST_TEAR_DOWN(sprintf)
{
}

TEST(sprintf, NoFormatOperations)
{
  char output[5];
  TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
  TEST_ASSERT_EQUAL_STRING("hey", output);
}

TEST(sprintf, NoFormatOperations2)
{
  char output[5] = "";
  TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
  TEST_ASSERT_EQUAL_STRING("hey", output);
}

TEST(sprintf, InsertString)
{
  char output[20] = "";
  TEST_ASSERT_EQUAL(12, sprintf(output, "Hello %s\n", "World"));
  TEST_ASSERT_EQUAL_STRING("Hello World\n", output);
}

TEST(sprintf, NoFormatOperations3)
{
  //NoFormatOperation2 do not guard againt sprintf 
  //writing past the string terminator.

  char output[5];
  memset(output, 0xaa, sizeof output);
  TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
  TEST_ASSERT_EQUAL_STRING("hey", output);
  //check the that the character after the terminationg null
  //is not changed.
  TEST_ASSERT_BYTES_EQUAL(0xaa, output[4]);
}


