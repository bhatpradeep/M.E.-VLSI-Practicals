/* Write a C program to create 50 files with names filei.txt (ie. file1.txt to file50.txt) which contains numbers from 0 to i (file1.txt contains 0 and 1 , file2.txt contains 0, 1 and 2 etc). Each number is separated by white single space.

Contents of filei.txt should be copied to file(i-1).txt and file1.txt should be copied to file50.txt 
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "header.h"
#include <string.h>

int main()
{
    
    assert(writing_into_file(50)==1);                        // writing the elements into different files from file-1 to file-50
    
    
   //printf("\nInitial file contents:\n");
   //assert(reading_from_file(50)==1);                     // reading the elements from the written files
    
    
    assert(rewrite_the_files(50)==1);                     //rewriting the files 
    
    
   // printf("\nAfter rewriing:\n");
   // assert(reading_from_file(50)==1);                   // reading from overridden files

   //assert(delete_files(50)==1);                         // deleting 50 files
    return 0;
}

