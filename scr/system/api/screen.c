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

  for (int now = 0; '\0' != *text;) {
    if (*text == '\n')
    {
      i += 160 - now * 2;
      text++;
    } else {
      displayBuf[i++] = *(text++);
      displayBuf[i++] = 0x03;
      now++;
    }
  }
}