
#ifndef PROSECUTOR_H
#define PROSECUTOR_H
#define PROSECUTIR_DEBUG
#ifdef PROSECUTIR_DEBUG
#include <iostream>
#endif
#include <tchar.h>

#include <Windows.h>

namespace prcutor {

	BOOL detect_loaded_dll(LPCSTR pdll_name);

	BOOL detect_timing_();

	BOOL detect_sleeping_pass();

	BOOL wine_registry_key();

	BOOL detect_freespace();


	BOOL detect_num_vm();
	/*
		social
	*/
	BOOL detect_mouse_siat();


};

#endif
