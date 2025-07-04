#include <drogon/drogon.h>
#include "palindrome.h"

int main()
{
    drogon::app().addListener("0.0.0.0", 8080);
    drogon::app().registerHandler("/api/ispalindromenumber/{number}", &ispalindrome, {drogon::Get});
    drogon::app().run();
    return 0;
}