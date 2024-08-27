#include "../../include/cstd.h"
#include "../../include/idts.h"
#define idtDescCnt 0x81
#define picMCtrl 0x20
#define picMData 0x21
#define picSCtrl 0xa0
#define picSData 0xa1

static struct gateDesc idtMap[idtDescCnt];
extern intrHandler intr_main_table[idtDescCnt];
void printf(const char *text, char color);

char *intrName[idtDescCnt];
intrHandler idtTable[idtDescCnt];

static void intrHandlerGeneral(uint8_t Vect) {
  if (Vect == 0x27 || Vect == 0x2f)
    return;
  printf("--------Error--------", 0x47);
}