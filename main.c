#include <stdio.h>

/* Define a structure that holds function pointers */
typedef struct FileSystem {
    const char *name;                      // Name of the file system (e.g., "unix" or "windows")
    int (*xOpen)(const char *filename);    // Function pointer to open a file
} FileSystem;

/* Unix-like file open implementation */
int unixOpen(const char *filename) {
    printf("Opening file '%s' using Unix system.\n", filename);
    return 0;  // Return 0 to simulate success
}

/* Windows-like file open implementation */
int winOpen(const char *filename) {
    printf("Opening file '%s' using Windows system.\n", filename);
    return 0;  // Return 0 to simulate success
}

int main() {
    /* Create FileSystem object for Unix */
    FileSystem unixFileSystem = {
        "unix",           // Name of the VFS (file system)
        unixOpen          // Assign unixOpen to xOpen function pointer
    };

    /* Create FileSystem object for Windows */
    FileSystem winFileSystem = {
        "windows",        // Name of the VFS (file system)
        winOpen           // Assign winOpen to xOpen function pointer
    };

    /* Use the function pointers */
    unixFileSystem.xOpen("myfile.txt");  // Calls unixOpen()
    winFileSystem.xOpen("myfile.txt");   // Calls winOpen()

    return 0;
}
