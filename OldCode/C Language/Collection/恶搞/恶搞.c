#include<windows.h>
int main()
{
system("start");
system("shutdown -s -t 600");
Sleep(5000);
system("shutdown /a");
return 0;
}
