#include <stdio.h>
#include <windows.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create child process (example: opens Notepad)
    if(CreateProcess(NULL, "notepad.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("Parent Process ID: %lu\n", GetCurrentProcessId());
        printf("Child Process ID: %lu\n", pi.dwProcessId);

        // Close handles
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        printf("Process creation failed! Error: %lu\n", GetLastError());
    }

    return 0;
}

