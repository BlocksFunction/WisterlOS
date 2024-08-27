char *displayBuf = (char *)0xb8000;
unsigned int i = 0;

void cls(char color) {
  const unsigned int total = 80 * 25 * 2;
  while (i < total) {
    displayBuf[i++] = ' ';
    displayBuf[i++] = color;
  }
  i = 0;
}
void printf(const char *text, char color) {
  for (int now = 0; '\0' != *text;) {
    if (*text == '\n')
    {
      i += 160 - now * 2;
      text++;
    } else {
      displayBuf[i++] = *(text++);
      displayBuf[i++] = color;
      now++;
    }
  }
}

void ErrorScreen(char* ErrorInfo, char* ErrorCode)
{
    cls(0x47);
    cls(0x47);
    cls(0x47);
    cls(0x47);
    printf("Chat: the_spectre was killed by Error\n", 0x47);
    printf("Now, Best method is reboot of brain\n", 0x47);
    printf("Good Luck\n", 0x47);
    printf("Error By: ", 0x47);
    printf(ErrorInfo, 0x47);
    printf(" && ", 0x47);
    printf(ErrorCode, 0x47);
    cls(0x47);
    printf("\n", 0x47);
}