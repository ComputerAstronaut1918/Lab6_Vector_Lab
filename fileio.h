/*************************
* @file 
* @brief  
* @author Harley Soto
* @date 11/03/26
*
* @version 2.0
*************************/
#ifndef  FILEIO_H
#define FILEIO_H

#define FILE_OK				0
#define FILE_OPEN_ERROR		-1 /* Descriptor for File Error*/
#define FILE_MEMORY_ERROR	-2
#define FILE_WRITE_ERROR		-3

int loadvectors(const char *fname, int *loaded, int *skipped, int *firstbad);

int savevectors(const char *fname, int *saved);

#endif