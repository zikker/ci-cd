#pragma once

#include <string>
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>

bool check_palindrome(const std::string &a);

void ispalindrome(
    const drogon::HttpRequestPtr &request,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback,
    const std::string &number
);