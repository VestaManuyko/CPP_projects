#include <gtest/gtest.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>

int	runProgram(const char *path, char *const args[], const std::string &excpStr)
{
	int status = 0;
	std::string outStr;

	pid_t pid = fork();
	if (pid == -1)
		return 1;
	if (pid == 0)
	{
		int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			exit(1);
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			close(fd);
			exit(1);
		}
		close(fd);
		execve(path, args, NULL);
		exit(1);
	}
	waitpid(pid, &status, 0);
	std::ifstream outFile("output.txt");
	outFile.exceptions(std::ios::failbit | std::ios::badbit);
	std::stringstream buffer;
	buffer << outFile.rdbuf();
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 1)
			return 1;
	}
	outStr = buffer.str();
	if (outStr == excpStr)
		return 0;
	return 1;
}

int	runConversion(const std::string &literal, const std::string &expected)
{
	char *args[] = {const_cast<char *>("./converter"),
		const_cast<char *>(literal.c_str()), NULL};
	return runProgram("./converter", args, expected);
}

TEST(Converter, charData)
{
	try
	{
		char *args[] = {const_cast<char *>("./converter"), const_cast<char *>("r"), NULL};
		std::string excpStr = "char: 'r'\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		EXPECT_EQ(runProgram("./converter", args, excpStr), 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

TEST(Converter, intData)
{
	try
	{
		char *args[] = {const_cast<char *>("./converter"), const_cast<char *>("42"), NULL};
		std::string excpStr = "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n";
		EXPECT_EQ(runProgram("./converter", args, excpStr), 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

TEST(Converter, floatData)
{
	try
	{
		char *args[] = {const_cast<char *>("./converter"), const_cast<char *>("42.0f"), NULL};
		std::string excpStr = "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n";
		EXPECT_EQ(runProgram("./converter", args, excpStr), 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

TEST(Converter, doubleData)
{
	try
	{
		char *args[] = {const_cast<char *>("./converter"), const_cast<char *>("42.0"), NULL};
		std::string excpStr = "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n";
		EXPECT_EQ(runProgram("./converter", args, excpStr), 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

TEST(Converter, inf)
{
	try
	{
		char *args[] = {const_cast<char *>("./converter"), const_cast<char *>("inf"), NULL};
		std::string excpStr = "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n";
		EXPECT_EQ(runProgram("./converter", args, excpStr), 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

TEST(Converter, emptyLiteral)
{
	std::string expected = "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	EXPECT_EQ(runConversion("", expected), 0);
}

TEST(Converter, malformedLiteral)
{
	std::string expected = "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	EXPECT_EQ(runConversion("12f", expected), 0);
	EXPECT_EQ(runConversion("1.2.3", expected), 0);
	EXPECT_EQ(runConversion("1f2", expected), 0);
}

TEST(Converter, boundaryAndSignedIntegers)
{
	EXPECT_EQ(runConversion("+42", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"), 0);
	EXPECT_EQ(runConversion("-129", "char: impossible\nint: -129\nfloat: -129.0f\ndouble: -129.0\n"), 0);
	EXPECT_EQ(runConversion("2147483648", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"), 0);
}

TEST(Converter, nonDisplayableAndWhitespaceCharacters)
{
	EXPECT_EQ(runConversion("1", "char: not displayable\nint: 1\nfloat: 1.0f\ndouble: 1.0\n"), 0);
	EXPECT_EQ(runConversion(" ", "char: ' '\nint: impossible\nfloat: impossible\ndouble: impossible\n"), 0);
}

TEST(Converter, specialValues)
{
	EXPECT_EQ(runConversion("nan", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n"), 0);
	EXPECT_EQ(runConversion("nanf", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n"), 0);
	EXPECT_EQ(runConversion("-inff", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n"), 0);
	EXPECT_EQ(runConversion("inf", "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n"), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}