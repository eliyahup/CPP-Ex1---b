#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement p with b,f ,and y with i") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "happi") == string("happy"));
    CHECK(find(text, "habbi") == string("happy"));
    CHECK(find(text, "hapbi") == string("happy"));
    CHECK(find(text, "habpi") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
    CHECK(find(text, "hafby") == string("happy"));
    CHECK(find(text, "habfy") == string("happy"));
    CHECK(find(text, "hapfi") == string("happy"));
    CHECK(find(text, "hafbi") == string("happy"));
    CHECK(find(text, "habfi") == string("happy"));
    CHECK(find(text, "hafpi") == string("happy"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "hAppi") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HaPPI") == string("Happi"));
    CHECK(find(text, "HAPpI") == string("Happi"));
}

TEST_CASE("Test replacement v with w and i with y and lower-case and upper-case") {
    string text = "xxx worry yyy";
    CHECK(find(text, "vorry") == string("worry"));
    CHECK(find(text, "worri") == string("worry"));
    CHECK(find(text, "vorri") == string("worry"));
    CHECK(find(text, "Worry") == string("worry"));
    CHECK(find(text, "woRry") == string("worry"));
    CHECK(find(text, "woRRy") == string("worry"));
    CHECK(find(text, "Worry") == string("worry"));
    CHECK(find(text, "WorrI") == string("worry"));
    CHECK(find(text, "worrI") == string("worry"));
    CHECK(find(text, "wOrrI") == string("worry"));
}

TEST_CASE("Test Dond vorri be haffy") {
    string text = "Dond vorri be haffy";
    CHECK(find(text, "dont") == string("Dond"));
    CHECK(find(text, "dunt") == string("Dond"));
    CHECK(find(text, "dond") == string("Dond"));
    CHECK(find(text, "dund") == string("Dond"));
    CHECK(find(text, "be") == string("be"));
    CHECK(find(text, "BE") == string("be"));
    CHECK(find(text, "bE") == string("be"));
    CHECK(find(text, "Be") == string("be"));
    CHECK(find(text, "haffy") == string("haffy"));
    CHECK(find(text, "happy") == string("haffy"));
}

TEST_CASE("cpp is language software") {
    string text = "cpp is language software";
    CHECK(find(text, "CPP") == string("cpp"));
    CHECK(find(text, "cpf") == string("cpp"));
    CHECK(find(text, "cpp") == string("cpp"));
    CHECK(find(text, "is") == string("is"));
    CHECK(find(text, "yz") == string("is"));
    CHECK(find(text, "iz") == string("is"));
    CHECK(find(text, "langoage") == string("language"));
    CHECK(find(text, "lanjuage") == string("language"));
    CHECK(find(text, "lanjoage") == string("language"));
    CHECK(find(text, "languaje") == string("language"));
    CHECK(find(text, "langoaje") == string("language"));
    CHECK(find(text, "lanjuaje") == string("language"));
    CHECK(find(text, "lANguage") == string("language"));
    CHECK(find(text, "langUAge") == string("language"));
    CHECK(find(text, "software") == string("software"));
    CHECK(find(text, "zoftware") == string("software"));
    CHECK(find(text, "soptware") == string("software"));
    CHECK(find(text, "sobtware") == string("software"));
    CHECK(find(text, "zoptware") == string("software"));
    CHECK(find(text, "zobtware") == string("software"));
    CHECK(find(text, "softvare") == string("software"));
    CHECK(find(text, "zoftvare") == string("software"));
    CHECK(find(text, "soptvare") == string("software"));
    CHECK(find(text, "zoptvare") == string("software"));
    CHECK(find(text, "sobtvare") == string("software"));
    CHECK(find(text, "zobtvare") == string("software"));
}

TEST_CASE("Test replacement of c and k and q") {
    string text = "xxx cookie yyy";
    CHECK(find(text, "cookie") == string("cookie"));
    CHECK(find(text, "coocie") == string("cookie"));
    CHECK(find(text, "cooqie") == string("cookie"));
    CHECK(find(text, "kookie") == string("cookie"));
    CHECK(find(text, "koocie") == string("cookie"));
    CHECK(find(text, "kooqie") == string("cookie"));
    CHECK(find(text, "qookie") == string("cookie"));
    CHECK(find(text, "qoocie") == string("cookie"));
    CHECK(find(text, "qooqie") == string("cookie"));
}

TEST_CASE("Test replacement of c and k and q when the is the end of text with upper case") {
    string text = "xxx yyy cookie";
    CHECK(find(text, "cOokie") == string("cookie"));
    CHECK(find(text, "coOcie") == string("cookie"));
    CHECK(find(text, "cOoqie") == string("cookie"));
    CHECK(find(text, "koOkie") == string("cookie"));
    CHECK(find(text, "kOocie") == string("cookie"));
    CHECK(find(text, "koOqie") == string("cookie"));
    CHECK(find(text, "qOokie") == string("cookie"));
    CHECK(find(text, "qoOcie") == string("cookie"));
    CHECK(find(text, "qOoqie") == string("cookie"));
}

TEST_CASE("Test replacement of i and y and upper case") {
    string text = "cookie zzz yyy";
    CHECK(find(text, "cookYe") == string("cookie"));
    CHECK(find(text, "cookye") == string("cookie"));
    CHECK(find(text, "cookie") == string("cookie"));
    CHECK(find(text, "cookiE") == string("cookie"));
    CHECK(find(text, "cooKie") == string("cookie"));
    CHECK(find(text, "Cookie") == string("cookie"));
    CHECK(find(text, "COOKie") == string("cookie"));
    CHECK(find(text, "COOKIE") == string("cookie"));
    CHECK(find(text, "COOKIe") == string("cookie"));
    CHECK(find(text, "cooKIE") == string("cookie"));
    CHECK(find(text, "CooKYE") == string("cookie"));
    CHECK(find(text, "COOKYe") == string("cookie"));
    CHECK(find(text, "COOKYE") == string("cookie"));
    CHECK(find(text, "COOKYe") == string("cookie"));
}



