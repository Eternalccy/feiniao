#include <stdio.h>
#include <windows.h>
#include <tchar.h>

BOOL UpDatePrivilege()
{
HANDLE hToken;
TOKEN_PRIVILEGES tkp;
if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
{
return(FALSE);
}
LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tkp.Privileges[0].Luid);
tkp.PrivilegeCount = 1;
tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
if (GetLastError() != ERROR_SUCCESS)
return FALSE;
return TRUE;
}


int m_tb()
{
TCHAR *pTitleName=TEXT("Demo");
HWND hWnd=NULL;
HICON hIcon=NULL;
SetConsoleTitle(pTitleName); hWnd=FindWindow(NULL,pTitleName);
if (hWnd)
{
hIcon=(HICON)LoadImage(NULL,TEXT("tb.ico"),IMAGE_ICON,16,16,LR_DEFAULTSIZE|LR_DEFAULTCOLOR|LR_LOADFROMFILE);//更改ico文件名字
if (hIcon)
{
SendMessage(hWnd,WM_SETICON,(WPARAM)ICON_BIG,(LPARAM)hIcon);
SendMessage(hWnd,WM_SETICON,(WPARAM)ICON_SMALL,(LPARAM)hIcon);
}
} //以下是你要写的代码。
getchar();
return 0;
}