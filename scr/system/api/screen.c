char *displayBuf = (char *)0xb8000;
unsigned int i = 0;

void cls() {
  const unsigned int total = 80 * 25 * 2;
  while (i < total) {
    displayBuf[i++] = ' ';
    displayBuf[i++] = 0x04;
  }
  i = 0;
}

void printf(const char *text) {
  for (; '\0' != *text;) {
    displayBuf[i++] = *(text++);
    displayBuf[i++] = 0x03;
  }
  // i += 80 - (80 - i);
}

