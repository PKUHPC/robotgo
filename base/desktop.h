#pragma once
#ifndef DESKTOP_H
#define DESKTOP_H

if defined(IS_WINDOWS)
	#include <stdio.h>
	#include <windows.h>

    static HDESK _lastKnownInputDesktop = NULL;

    HDESK syncThreadDesktop() {
        HDESK hDesk = OpenInputDesktop(DF_ALLOWOTHERACCOUNTHOOK, FALSE, GENERIC_ALL);
        if (!hDesk) {
            DWORD err = GetLastError();
            printf("Failed to Open Input Desktop [0x%08X]\n", err);
            CloseDesktop(hDesk);
            return NULL;
        }

        if (hDesk == NULL || hDesk == INVALID_HANDLE_VALUE) {
            printf("Invalid desktop handle obtained.");
            CloseDesktop(hDesk);
            return NULL;
        }

        if (!SetThreadDesktop(hDesk)) {
            DWORD err = GetLastError();
            printf("Failed to sync desktop to thread [0x%08X]\n", err);
            CloseDesktop(hDesk);
            return NULL;
        }

        CloseDesktop(hDesk);

        return hDesk;
    }
#endif
