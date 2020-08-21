#ifndef GAMMARAMP_H_
#define GAMMARAMP_H_
#include <Windows.h>
/*
CGammaRamp class

Encapsulates the Gamma Ramp API and changes the brightness of
the entire screen.

Written by Nir Sofer.
http://www.nirsoft.net

*/

class CGammaRamp
{
protected:
    HMODULE hGDI32;
    HDC hScreenDC;
    typedef BOOL(WINAPI* Type_GetDeviceGammaRamp)(HDC hDC, LPVOID lpRamp);
    typedef BOOL(WINAPI* Type_SetDeviceGammaRamp)(HDC hDC, LPVOID lpRamp);

    Type_GetDeviceGammaRamp pGetDeviceGammaRamp;
    Type_SetDeviceGammaRamp pSetDeviceGammaRamp;

public:

    CGammaRamp();
    ~CGammaRamp();
    BOOL LoadLibrary();
    void FreeLibrary();
    BOOL LoadLibraryIfNeeded();
    BOOL SetDeviceGammaRamp(HDC hDC, LPVOID lpRamp);
    BOOL GetDeviceGammaRamp(HDC hDC, LPVOID lpRamp);
    BOOL SetBrightness(HDC hDC, WORD wBrightness);  // ����
    BOOL SetBrightness(HDC hDC, int wR, int wG, int wB); // ��ɫ

};
#endif//#ifndef GAMMARAMP_H_