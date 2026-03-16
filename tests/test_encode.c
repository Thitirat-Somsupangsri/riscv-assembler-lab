#include <assert.h>

#include "encode.h"

int main(void) {
    assert(encode_r(0x33, 0x0, 0x00, 1, 2, 3) == 0x003100b3u);
    assert(encode_i(0x13, 0x0, 1, 0, 5) == 0x00500093u);
    assert(encode_s(0x23, 0x2, 2, 1, 8) == 0x00112423u);
    assert(encode_b(0x63, 0x0, 1, 2, 8) == 0x00208463u);
    assert(encode_j(0x6F, 1, 16) == 0x010000efu);
    assert(imm_fits_signed(2047, 12) == 1);
    assert(imm_fits_signed(2048, 12) == 0);
    assert(imm_is_aligned(8, 2) == 1);
    assert(imm_is_aligned(3, 2) == 0);
    return 0;
}
