#include <stdio.h>
#include <windows.h>
#include <string.h>

#define MAX_FOLDERS 100
#define MAX_NAME 256

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void copyFileWithProgress(const char *source, const char *destination)
{
    if (!CopyFile(source, destination, FALSE))
    {
        setColor(12);
        printf("Failed to copy %s\n", source);
    }
    else
    {
        setColor(10);
        printf("Copied %s\n", source);
    }
    setColor(7);
}

void copyFolderFiles(const char *folderPath, const char *targetFolder)
{
    WIN32_FIND_DATA findFileData;
    char searchPath[MAX_NAME];
    snprintf(searchPath, MAX_NAME, "%s\\*.*", folderPath);

    HANDLE hFind = FindFirstFile(searchPath, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        printf("No files found in %s\n", folderPath);
        return;
    }

    int fileCount = 0;
    do
    {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
            !(findFileData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) &&
            !(findFileData.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM))
            fileCount++;
    } while (FindNextFile(hFind, &findFileData) != 0);
    FindClose(hFind);

    hFind = FindFirstFile(searchPath, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE)
        return;

    int currentFile = 0;
    do
    {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
            !(findFileData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) &&
            !(findFileData.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM))
        {
            char sourceFile[MAX_NAME];
            char targetFile[MAX_NAME];
            snprintf(sourceFile, MAX_NAME, "%s\\%s", folderPath, findFileData.cFileName);
            snprintf(targetFile, MAX_NAME, "%s\\%s", targetFolder, findFileData.cFileName);

            copyFileWithProgress(sourceFile, targetFile);

            currentFile++;
            printf("[");
            int progress = (currentFile * 20) / fileCount;
            for (int i = 0; i < 20; i++)
                printf(i < progress ? "#" : " ");
            printf("] %d%%\r", (currentFile * 100) / fileCount);
            fflush(stdout);
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
    printf("\n");
}

const char *asciiArt =
    " _                          \n"
    "| |__   __ ___  _____  ___ \n"
    "| '_ \\ / _` \\ \\/ / _ \\/ _ \\\n"
    "| | | | (_| |>  <  __/  __/\n"
    "|_| |_|\\__,_/_/\\_\\___|\\___|\n";

void printASCII()
{
    setColor(11);
    printf("%s", asciiArt);
    setColor(7);

    setColor(14);
    printf("made by hax\ngithub: https://github.com/6hax\n\n");
    setColor(7);
}

int main()
{
    printASCII();

    char skinsDir[MAX_NAME];
    GetCurrentDirectory(MAX_NAME, skinsDir);
    strcat(skinsDir, "\\skins");

    const char *csModelsFolder = "C:\\Jogos\\CS Revo\\CS 1.6\\cstrike\\models";

    WIN32_FIND_DATA findFileData;
    char searchPath[MAX_NAME];
    snprintf(searchPath, MAX_NAME, "%s\\*.*", skinsDir);

    HANDLE hFind = FindFirstFile(searchPath, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        setColor(12);
        printf("No skin folders found in skins/!\n");
        setColor(7);
        return 1;
    }

    char folders[MAX_FOLDERS][MAX_NAME];
    int folderCount = 0;

    do
    {
        if ((findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
            strcmp(findFileData.cFileName, ".") != 0 &&
            strcmp(findFileData.cFileName, "..") != 0)
        {
            strcpy(folders[folderCount], findFileData.cFileName);
            folderCount++;
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);

    printf("Available skin folders:\n");
    for (int i = 0; i < folderCount; i++)
    {
        setColor(14);
        printf("[%d] ", i + 1);
        setColor(10);
        printf("%s\n", folders[i]);
    }
    setColor(7);

    int choice;
    printf("\nSelect a skin folder (number): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > folderCount)
    {
        setColor(12);
        printf("Invalid choice!\n");
        setColor(7);
        return 1;
    }

    char selectedFolder[MAX_NAME];
    snprintf(selectedFolder, MAX_NAME, "%s\\%s", skinsDir, folders[choice - 1]);

    printf("\nCopying skins from %s...\n\n", folders[choice - 1]);
    copyFolderFiles(selectedFolder, csModelsFolder);

    setColor(11);
    printf("\nDone! Skins updated!\n");
    setColor(7);

    return 0;
}
