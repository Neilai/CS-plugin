#ifndef UTIL
#define UTIL

#include <Windows.h>
typedef struct __THREAD_DATA
{
    HANDLE GameHandle ;
}THREAD_DATA;
DWORD GetProcessID(wchar_t *FileName);
void goLand(THREAD_DATA* pThreadData);
DWORD WINAPI fly(LPVOID lpParameter);
DWORD WINAPI down(LPVOID lpParameter);
DWORD WINAPI bullet(LPVOID lpParameter);
DWORD WINAPI blood(LPVOID lpParameter);
DWORD WINAPI recoil(LPVOID lpParameter);
void wall(THREAD_DATA* pThreadData);
void goback(THREAD_DATA* pThreadData);

#endif // UTIL


