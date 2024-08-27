#include "cstd.h"

struct gateDesc {
    uint16_t funcOffsetLowWord, selector;
    uint8_t dcount, attribute;
    uint16_t funcOffsetHighWord;
};
typedef void* intrHandler;