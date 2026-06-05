#include <gtest/gtest.h>

TEST(Failure, no_arg)
{
	int status = system("./replace");

    EXPECT_TRUE(WIFEXITED(status));
    EXPECT_EQ(WEXITSTATUS(status), 1);
}

TEST(Failure, too_many_arg)
{
	int status = system("./replace test_files/file.txt lol kek hihi");

    EXPECT_TRUE(WIFEXITED(status));
    EXPECT_EQ(WEXITSTATUS(status), 1);
}

TEST(Failure, file_without_read_permission)
{
	int status = system("./replace test_files/file.txt lol kek");

    EXPECT_TRUE(WIFEXITED(status));
    EXPECT_EQ(WEXITSTATUS(status), 1);
}

TEST(Failure, non_existing_file)
{
	int status = system("./replace hello.txt hello world");

    EXPECT_TRUE(WIFEXITED(status));
    EXPECT_EQ(WEXITSTATUS(status), 1);
}

TEST(Normal, empty_strings)
{
	int status = system("./replace test_files/empty_strings.txt \"\" \"\"");

    EXPECT_TRUE(WIFEXITED(status));
    EXPECT_EQ(WEXITSTATUS(status), 0);
}
TEST(Normal, replace_spaces)
{
	int status = system("./replace test_files/replace_spaces.txt \" \" really");

    EXPECT_TRUE(WIFEXITED(status));
    EXPECT_EQ(WEXITSTATUS(status), 0);
}

TEST(Normal, no_extension_in_provided_file)
{
	int status = system("./replace test_files/no_extension_in_provided_file \" \" really");

    EXPECT_TRUE(WIFEXITED(status));
    EXPECT_EQ(WEXITSTATUS(status), 0);
}
