#include "linux-ex/cdecl.h"

int PRE_CDECL asm_main( void ) POST_CDECL;

int
main()
{
    int res_status;
    res_status = asm_main();
    return res_status;
}
