#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include"util.h"
using namespace std;
//取进程ID
DWORD GetProcessID(wchar_t *FileName)
{
    HANDLE hProcess;
    PROCESSENTRY32 pe;
    BOOL bRet;
    //进行进程快照
    hProcess = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    pe.dwSize = sizeof(PROCESSENTRY32W);
    //开始进程查找
    bRet = ::Process32First(hProcess, &pe);
    //循环比较，得出ProcessID
    while (bRet)
    {
        if (wcscmp(FileName, pe.szExeFile) == 0)
            return pe.th32ProcessID;
        else
            bRet = ::Process32Next(hProcess, &pe);
    }
    return 0;
}
//正常
void goLand(THREAD_DATA* pThreadData){
    DWORD Buffer = 0;
    DWORD My_New = 1099431936;
    ReadProcessMemory(pThreadData->GameHandle, LPVOID(0x2081928), &Buffer, sizeof(DWORD), NULL);
    WriteProcessMemory(pThreadData->GameHandle, LPVOID(Buffer + (0X1FC)), &My_New, sizeof(DWORD), NULL);
}

//飞天
DWORD WINAPI fly(LPVOID lpParameter)
{
    DWORD Buffer = 0;
    DWORD My_New = 1132068864;
    THREAD_DATA* pThreadData = (THREAD_DATA*)lpParameter;
    while(1){
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(0x2081928), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(pThreadData->GameHandle, LPVOID(Buffer + (0X1FC)), &My_New, sizeof(DWORD), NULL);
    }
    return 0L;
}

//遁地
DWORD WINAPI down(LPVOID lpParameter)
{
    DWORD Buffer = 0;
    DWORD My_New = 3279552512;
    THREAD_DATA* pThreadData = (THREAD_DATA*)lpParameter;
    while(1){
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(0x2081928), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(pThreadData->GameHandle, LPVOID(Buffer + (0X1FC)), &My_New, sizeof(DWORD), NULL);
    }
    return 0L;
}

//无限子弹
DWORD WINAPI bullet(LPVOID lpParameter)
{
    DWORD Buffer = 0;
    DWORD My_New = 30;
    THREAD_DATA* pThreadData = (THREAD_DATA*)lpParameter;
    while(1){
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(0x2081928), &Buffer, sizeof(DWORD), NULL);
        DWORD Base=Buffer+(0x7C);
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        Base=Buffer+(0x5EC);
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(pThreadData->GameHandle, LPVOID(Buffer +(0xCC)), &My_New, sizeof(DWORD), NULL);
    }
    return 0L;
}


//锁血
DWORD WINAPI blood(LPVOID lpParameter)
{
    DWORD Buffer = 0;
    DWORD My_New = 1120403456;
    THREAD_DATA* pThreadData = (THREAD_DATA*)lpParameter;
    while(1){
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(0x2081928), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(pThreadData->GameHandle, LPVOID(Buffer + (0x1E0)), &My_New, sizeof(DWORD), NULL);
    }
    return 0L;
}

//无后座力
DWORD WINAPI recoil(LPVOID lpParameter)
{
    DWORD Buffer = 0;
    DWORD My_New1 = 0;
    DWORD My_New2 = 30;
    THREAD_DATA* pThreadData = (THREAD_DATA*)lpParameter;
    while(1){
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(0x2081928), &Buffer, sizeof(DWORD), NULL);
        DWORD Base=Buffer+(0x7C);
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        Base=Buffer+(0x5EC);
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(pThreadData->GameHandle, LPVOID(Buffer +(0x100)), &My_New1, sizeof(DWORD), NULL);
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(0x2081928), &Buffer, sizeof(DWORD), NULL);
        Base=Buffer+(0x7C);
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        Base=Buffer+(0x5EC);
        ReadProcessMemory(pThreadData->GameHandle, LPVOID(Base), &Buffer, sizeof(DWORD), NULL);
        WriteProcessMemory(pThreadData->GameHandle, LPVOID(Buffer +(0xEC)), &My_New2, sizeof(DWORD), NULL);
    }
    return 0L;
}


//穿墙
void wall(THREAD_DATA* pThreadData){
    std::cout<<"wall"<<endl;
    DWORD Buffer = 0;
    DWORD My_New = 3;

    ReadProcessMemory(pThreadData->GameHandle, LPVOID(0x2081928), &Buffer, sizeof(DWORD), NULL);
    WriteProcessMemory(pThreadData->GameHandle, LPVOID(Buffer + (0X2C4)), &My_New, sizeof(DWORD), NULL);
}

void goback(THREAD_DATA* pThreadData){
    DWORD Buffer = 0;
    DWORD My_New = 0;

    ReadProcessMemory(pThreadData->GameHandle, LPVOID(0x2081928), &Buffer, sizeof(DWORD), NULL);
    WriteProcessMemory(pThreadData->GameHandle, LPVOID(Buffer + (0X2C4)), &My_New, sizeof(DWORD), NULL);
}

//int main()
//{
//    THREAD_DATA threadData;

//    threadData.GameHandle = OpenProcess(PROCESS_ALL_ACCESS, 1, GetProcessID(L"cstrike.exe"));
//    HANDLE Thread_fly = CreateThread(NULL, 0, fly, &threadData, 0, NULL);
//    HANDLE Thread_down = CreateThread(NULL, 0, down, &threadData, 0, NULL);
     //HANDLE Thread_bullet = CreateThread(NULL, 0, bullet, &threadData, 0, NULL);
    //    goLand(&threadData);
//    HANDLE Thread_blood = CreateThread(NULL, 0, blood, &threadData, 0, NULL);
//    HANDLE Thread_recoil = CreateThread(NULL, 0, recoil, &threadData, 0, NULL);
//       goback(&threadData);
//    while(1){};
//    return 0;
//}









