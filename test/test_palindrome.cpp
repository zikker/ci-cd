#include <gtest/gtest.h>
#include "../palindrome.h"
#include <drogon/drogon.h>
#include <drogon/HttpAppFramework.h>
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>

using namespace drogon;
using namespace testing;

// Вспомогательная функция из main.cpp
bool check_palindrome(const std::string &a);

// Копия функции-обработчика
void ispalindrome(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, const std::string &number);

// ----------------------
// Тест функции логики
// ----------------------

TEST(PalindromeLogicTest, PositiveCases) {
    EXPECT_TRUE(check_palindrome("121"));
    EXPECT_TRUE(check_palindrome("12321"));
    EXPECT_TRUE(check_palindrome("1"));
    EXPECT_TRUE(check_palindrome("0"));
}

TEST(PalindromeLogicTest, NegativeCases) {
    EXPECT_FALSE(check_palindrome("123"));
    EXPECT_FALSE(check_palindrome("10"));
    EXPECT_FALSE(check_palindrome("123456"));
}

// ----------------------
// Тест HTTP-обработчика
// ----------------------

TEST(PalindromeHttpTest, PalindromeResponse) {
    auto req = HttpRequest::newHttpRequest();
    std::string number = "121";

    ispalindrome(req, [number](const HttpResponsePtr &resp) {
        EXPECT_EQ(resp->statusCode(), k200OK);
        EXPECT_EQ(resp->getBody(), number + " is palindrome");
    }, number);
}

TEST(PalindromeHttpTest, NotPalindromeResponse) {
    auto req = HttpRequest::newHttpRequest();
    std::string number = "123";

    ispalindrome(req, [number](const HttpResponsePtr &resp) {
        EXPECT_EQ(resp->statusCode(), k200OK);
        EXPECT_EQ(resp->getBody(), number + " is not palindrome");
    }, number);
}