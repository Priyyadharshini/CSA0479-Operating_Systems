#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
 	Char *filename;
 	Struct stat fs;
 	Int r;
 	If( argc<2 )
	{
 		Puts(“Filename required”);
 		Exit(1);
	}
 	Filename = argv[1];
 	Printf(“Obtaining permission mode for ‘%s’:\n”,filename);
 	R = stat(filename,&fs);
 	If( r==-1 )
	{
 		Fprintf(stderr,”File error\n”);
 		Exit(1);
	}
 	Printf(“Permission bits: %X\n”,fs.st_mode); 
}
