/*
	For info of printf replacements in Windows, check out
	C/C++ Language and Standard Libraries > C Run-Time Library Reference > Alphabetical Function Reference
	https://msdn.microsoft.com/en-us/library/1kt27hek.aspx
*/

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int CDECL MessageBoxPrintf(TCHAR *szCaption, TCHAR *szFormat, ...)
{
	TCHAR szBuffer[1024];
	va_list pArgList;
	
	va_start(pArgList, szFormat);
	vsnprintf(szBuffer, sizeof(szBuffer) / sizeof(TCHAR), szFormat, pArgList);
	//snprintf(szBuffer, sizeof(szBuffer) / sizeof(TCHAR), szFormat, pArgList);
	va_end(pArgList);

	return MessageBox(NULL, szBuffer, szCaption, MB_OK);
}

int WINAPI WinMain(HINSTANCE hInstance, 
		HINSTANCE hPrevInstance,
		PSTR szCmdLine, 
		int iCmdShow)
{
	int cxScreen, cyScreen;
	
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);
	
	MessageBoxPrintf(TEXT("ScrnSize"), TEXT("The screen is\n%d by %d pixels"), cxScreen, cyScreen);
	
	// If this source is encoded as UTF-8, Traditional Chinese characters don't look normal.
	// This source should be encoded as ANSI.
	MessageBoxPrintf(TEXT("螢幕大小尺寸"), TEXT("螢幕大小尺寸為\n%d by %d 畫素"), cxScreen, cyScreen);
	
	return 0 ;
}
