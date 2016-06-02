/*
	HelloWorld.c -- Displays "Hello, Windows!" in a message box
*/

#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, 
		HINSTANCE hPrevInstance,
		PSTR szCmdLine, 
		int iCmdShow)
{
	MessageBox (NULL, TEXT("Hello, Windows!"), TEXT("HelloWorld"), MB_OK);
	
	return 0 ;
}
