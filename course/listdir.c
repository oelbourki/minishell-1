#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    /* DIR:-opaque data type representing directory stream*/
    DIR *dp;
    /* dirent is a structure wich conatins information about a file like name, inode, offset etc*/
    struct dirent *dirp;

    if (argc != 2)
    {
        printf("pleas prvide the directory to list");
        exit(1);
    }
    if ((dp = opendir(argv[1])) == NULL)
    {
        printf("cannot open directory error = %s\n",strerror(errno));
        exit(1);
    }
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n",dirp->d_name);
    closedir(dp);
    exit(0);
}
