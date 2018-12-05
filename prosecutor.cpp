#include "prosecutor.h"

BOOL prcutor::detect_loaded_dll(LPCSTR pDllName) {
	HMODULE chDll = GetModuleHandle(pDllName);


	if (chDll) {
#ifdef PROSECUTIR_DEBUG
		std::cout <<  " - found" << std::endl;
#endif
		return TRUE;
	}
	else {
#ifdef PROSECUTIR_DEBUG
		std::cout <<  " - not found" << std::endl;
#endif
		return FALSE;
	}
}

BOOL prcutor::detect_freespace() {
	LPCSTR lpDirectoryName = NULL;
	ULARGE_INTEGER lpTotalNumberOfBytes;

	BOOL bStat = GetDiskFreeSpaceEx(lpDirectoryName, NULL, &lpTotalNumberOfBytes, NULL);
	if (bStat)
	{
		if (lpTotalNumberOfBytes.QuadPart < (30ULL * (1024ULL * (1024ULL * (1024ULL))))) {
#ifdef PROSECUTIR_DEBUG
			std::cout << "free space detect" << std::endl;
#endif
			return TRUE;
		}
		else {
#ifdef PROSECUTIR_DEBUG
			std::cout << "free space no detect" << std::endl;
#endif
			return FALSE;
		}
	}
}

BOOL prcutor::detect_timing_() {
	unsigned __int64 a, b, c;

	int i = 0;

	do
	{
		a = __rdtsc();

		GetProcessHeap();

		b = __rdtsc();

		CloseHandle(0);

		c = __rdtsc();

		if ((DWORD64(c) - DWORD64(b)) /
			(DWORD64(b) - DWORD64(a)) >= 10) {
#ifdef PROSECUTIR_DEBUG
			std::cout << "timing attack is good" << std::endl;
#endif
			return TRUE;
		}
		
		++i;
	} while (i < 10);
#ifdef PROSECUTIR_DEBUG
	std::cout << "timing attack not found" << std::endl;
#endif
	return FALSE;
}

BOOL prcutor::wine_registry_key() {
	HKEY phkResult = FALSE;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, _T("SOFTWARE\\Wine"), NULL, KEY_READ, &phkResult) == ERROR_SUCCESS)
	{
		RegCloseKey(phkResult);
#ifdef PROSECUTIR_DEBUG
		std::cout << "free space detect" << std::endl;
#endif
		return TRUE;
	}
#ifdef PROSECUTIR_DEBUG
	std::cout << "free space no detect" << std::endl;
#endif

}

BOOL prcutor::detect_num_vm() {
	PULONG procNum = (PULONG)(__readgsqword(0x60) + 0xB8);
	if (*procNum < 2) {
#ifdef PROSECUTIR_DEBUG
		std::cout << "low cores" << std::endl;
#endif
		return TRUE;
	}
	else {

#ifdef PROSECUTIR_DEBUG
		std::cout << "many cores" << std::endl;
#endif
		return FALSE;
	}
}

BOOL prcutor::detect_sleeping_pass() {

	DWORD c_begin = 0;
	DWORD c_end = 0;
	DWORD difference = 0;

	c_begin = GetTickCount();

	Sleep(100000);

	c_end = GetTickCount();

	difference = c_end - c_begin;

	if (difference > 99000) {
#ifdef PROSECUTIR_DEBUG
		std::cout << "debugger not found" << std::endl;
#endif
		return FALSE;
	}

	else {
#ifdef PROSECUTIR_DEBUG
		std::cout << "detect debugger" << std::endl;
#endif
		return TRUE;
	}
}

BOOL prcutor::detect_mouse_siat() {
	int count = 0;

	POINT mouse_coordinate1 = {};
	POINT mouse_coordinate2 = {};

	GetCursorPos(&mouse_coordinate1);

	Sleep(1500);

	GetCursorPos(&mouse_coordinate2);

	if ((mouse_coordinate1.x == mouse_coordinate2.x) &&
		(mouse_coordinate1.y == mouse_coordinate2.y))
		++count;

	GetCursorPos(&mouse_coordinate1);

	Sleep(1500);

	GetCursorPos(&mouse_coordinate2);

	if ((mouse_coordinate1.x == mouse_coordinate2.x) &&
		(mouse_coordinate1.y == mouse_coordinate2.y))
		++count;
	if (count > 0) {
#ifdef PROSECUTIR_DEBUG
		std::cout << "detect mouse timing" << std::endl;
#endif
		return TRUE;
	} 
	else {
		return FALSE;
	}
}