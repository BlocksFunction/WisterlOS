#include <stdint.h>
static inline void outB(uint16_t port, uint8_t data)
{
    asm volatile( "outB %b0, %w1" : : "a"(data), "Nd"(port));
}

static inline void outSW(uint16_t port, const char* addr, uint32_t wordCnt)
{
    asm volatile("cld; rep outsw" : "+S"(addr), "+c"(wordCnt) : "d"(port));
}
static inline uint8_t inb(uint16_t port)
{
    uint8_t data;
    asm volatile("inb %w1, %b0" : "=a"(data) : "Nd"(port));
}

static inline void insw(uint16_t port, void* addr, uint32_t wordCnt)
{
    asm volatile("cld;rep insw" : "+D"(addr), "+c"(wordCnt) : "d"(port) : "memory");
}