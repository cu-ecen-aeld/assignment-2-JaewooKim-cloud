#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER); // Open a connection to the system logger

    if (argc != 3) {
        syslog(LOG_ERR, "Error: Two arguments are required.");
        closelog(); // Close the connection to the system logger
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];
    syslog(LOG_DEBUG, "Writing \"%s\" to \"%s\"", writestr, writefile);

    char directory_path[256]; // Adjust the buffer size as needed
    strncpy(directory_path, writefile, sizeof(directory_path));
    char *last_slash = strrchr(directory_path, '/');
    if (last_slash != NULL) {
        *last_slash = '\0';
    }

    if (mkdir(directory_path, 0777) != 0 && errno != EEXIST) {
        syslog(LOG_ERR, "Failed to create directory path");
        closelog();
        return 1;
    }

    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Failed to open file");
        closelog();
        return 1;
    }
    fclose(file);

    file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Failed to open file for writing");
        closelog();
        return 1;
    }
    if (fputs(writestr, file) == EOF) {
        syslog(LOG_ERR, "Failed to write to file");
        fclose(file);
        closelog();
        return 1;
    }
    fclose(file);

    struct stat file_info;
    if (stat(writefile, &file_info) != 0) {
        syslog(LOG_ERR, "Failed to get file information");
        closelog();
        return 1;
    }

    syslog(LOG_INFO, "File created or overwritten successfully at: %s", writefile);
    closelog(); // Close the connection to the system logger

    return 0;
}