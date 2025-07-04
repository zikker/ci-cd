#include "palindrome.h"

bool check_palindrome(const std::string &a) {
    int n = std::stoi(a);
    int t = n;
    int rev = 0;

    while (t > 0) {
        int dig = t % 10;
        rev = rev * 10 + dig;
        t /= 10;
    }

    return n == rev;
}

void ispalindrome(const drogon::HttpRequestPtr &request,
                  std::function<void(const drogon::HttpResponsePtr &)> &&callback,
                  const std::string &number)
{
    bool flag = check_palindrome(number);
    auto resp = drogon::HttpResponse::newHttpResponse();
    resp->setStatusCode(drogon::k200OK);
    resp->setContentTypeCode(drogon::CT_TEXT_HTML);
    if (flag) {
        resp->setBody(number + " is palindrome");
    } else {
        resp->setBody(number + " is not palindrome");
    }
    callback(resp);
}
