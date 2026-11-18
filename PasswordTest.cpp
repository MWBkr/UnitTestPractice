/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_repeating_leading_characters)
{
        Password my_password;
        int actual = my_password.count_leading_characters("GGGGGGGGGGrgkgh3819gdjshgekqoir");
        ASSERT_EQ(10, actual);
}

TEST(PasswordTest, empty_string)
{
        Password my_password;
        int actual = my_password.count_leading_characters("");
        ASSERT_EQ(0, actual);
}

TEST(PasswordTest, leading_number)
{
        Password my_password;
        int actual = my_password.count_leading_characters("7777$@sbgti");
        ASSERT_EQ(4, actual);
}

TEST(PasswordTest, leading_special_character)
{
        Password my_password;
        int actual = my_password.count_leading_characters("#######kbhggkj385ubf");
        ASSERT_EQ(7, actual);
}


TEST(PasswordTest, empty_string_ul)
{
        Password my_password;
        int actual = my_password.has_mixed_case("");
        ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_lower)
{
        Password my_password;
        int actual = my_password.has_mixed_case("ahbgkjgjskjebf");
        ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_upper)
{
        Password my_password;
        int actual = my_password.has_mixed_case("TDOGNRFEFBN");
        ASSERT_EQ(false, actual);
}

TEST(PasswordTest, upper_and_lower)
{
        Password my_password;
        int actual = my_password.has_mixed_case("ARneu4592%$#");
        ASSERT_EQ(true, actual);
}

TEST(PasswordTest, no_letters)
{
        Password my_password;
        int actual = my_password.has_mixed_case("!15^*#6%3&%3@7^8&");
        ASSERT_EQ(false, actual);
}

TEST(PasswordTest, same_letter)
{
        Password my_password;
        int actual = my_password.has_mixed_case("gG");
        ASSERT_EQ(true, actual);
}


