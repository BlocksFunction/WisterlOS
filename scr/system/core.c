void printf(const char *text, char color);
void cls(char color);
void CHlt(void);
void ErrorScreen(char *ErrorInfo, char *ErrorCode);

char Username[15];

int FBlock() {
  cls(0x17);
  printf("Wisterl System is Loaded\n", 0x17);
  printf("--------------------------\n", 0x17);
  printf("Developer:\n", 0x17);
  printf("    BlocksFunction\n", 0x17);
  printf("---------------------------\n", 0x17);
  printf("Enter \"B\" to login\n", 0x17);
  CHlt();
  return 0;
}