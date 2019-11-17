#include "gtest/gtest.h"
#include "possible_parentheses.h"

void showResult(std::list<std::string> & result) {
    for (std::list<std::string>::iterator i = result.begin(); i!=result.end(); ++i) {
        printf("%s\n", (*i).c_str());
    }
};
TEST(test_recursive, 0) {
    std::list<std::string> result;
    possibleParenthesis(0, result);
    ASSERT_TRUE(result.empty());

// homework: add verification
}
TEST(test_recursive, 1) {
    std::list<std::string> result;
    possibleParenthesis(1, result);
    std::list<std::string> result1 {"{}"};
    ASSERT_EQ(result,result1);

}

TEST(test_recursive, 2) {
    std::list<std::string> result;
    possibleParenthesis(2, result);
    std::list<std::string> result1 {"{}{}","{{}}"};
    ASSERT_EQ(result,result1);
    // homework: add verification
}

TEST(test_recursive, 3) {
    std::list<std::string> result;
    possibleParenthesis(3, result);
    std::list<std::string> result1 {"{}{}{}","{}{{}}","{{}}{}","{{}{}}","{{{}}}"};
    ASSERT_EQ(result,result1);
    // homework: add verification
}

// and more
