#include <string.h>
#include "assert.h"
#include "ap.h"
#include "fmt.h"

int
main(int argc, char *argv[])
{
    AP_T ap;
    const char *teststr;
    char *end;

    Fmt_register('D', AP_fmt);

    teststr = "GG";
    ap = AP_fromstr(teststr, 16, &end);
    assert(end == teststr);
    Fmt_print("ap(\"%s\", 16): %D\n", teststr, ap);

    teststr = "A";
    ap = AP_fromstr(teststr, 10, &end);
    assert(end == teststr);
    Fmt_print("ap(\"%s\", 10): %D\n", teststr, ap);

    if (argc > 1) {
        ap = AP_fromstr(argv[1], 10, &end);
        Fmt_print("ap(\"%s\", 10): %D\n", argv[1], ap);
    }

    return 0;
}
