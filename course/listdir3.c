#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int listdir(const char *filename)
{
    /* DIR:-opaque data type representing directory stream*/
    DIR *dp;
    /* dirent is a structure wich conatins information about a file like name, inode, offset etc*/
    struct dirent *dirp;
    char PATH[259] = {0};


    if ((dp = opendir(filename)) == NULL)
    {
        printf("cannot open directory error = %s\n",strerror(errno));
        exit(1);
    }
    while ((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n",dirp->d_name);
        if (dirp->d_type == DT_DIR)
        {
            if (strcmp(dirp->d_name,".") == 0 || strcmp(dirp->d_name,"..") == 0)
                continue;
            printf("%s%s\n",filename,dirp->d_name);
            snprintf(PATH,sizeof(PATH) - 1, "%s%s/",filename,dirp->d_name);
            listdir(PATH);
        }
        else
        {
            printf("%s%s\n",filename,dirp->d_name);
        }
        
    }
    closedir(dp);
    exit(0);
}


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("pleas prvide the directory to list");
        exit(1);
    }
    listdir(argv[1]);
    return 0;
}