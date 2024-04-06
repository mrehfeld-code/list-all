#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

bool str_compare(const char* s1, const char* s2) {
    long max_len = 0;
    if(strlen(s1) <= strlen(s1))
        max_len = (signed)strlen(s1);
    else
        max_len = (signed)strlen(s2);

    for(long i = 0; i <= max_len; i++) {
        if(s1[i] != s2[i]) return false;
    } return true;
}

long file_count = 0, dir_count = 0;
bool runs_for_the_first_time = true;

int ReadDir(char* pwd) {
    if(pwd[strlen(pwd)-1] != '/') strcat(pwd, "/");

    DIR *folder;
    struct dirent *entry;

    folder = opendir(pwd);
    if(folder == NULL) {
        fprintf(stderr, "Unable to read directory %s!\n", pwd);
        return 1;
    }

    while((entry = readdir(folder))) {
        printf("%s%s\n", pwd, entry->d_name);
        if(entry->d_type == DT_DIR) {
            if(!str_compare(entry->d_name, "..") && !str_compare(entry->d_name, ".")) {
                char subdir[FILENAME_MAX];
                sprintf(subdir, "%s%s/", pwd, entry->d_name);
                ReadDir(subdir);
                //*subdir = (char*)NULL;
            } if(str_compare(entry->d_name, ".")) dir_count += 1;
        } else file_count += 1;
    }

    closedir(folder);

    return 0;
}

int main(int argc, char* argv[]) {
    if(argc < 1) return 1;

    if(argc < 2) ReadDir(getenv("PWD"));
    if(argc >= 2) ReadDir(argv[1]);

    printf("\nRead %d files and %d directories.\n", file_count, dir_count);

    return 0;
}
