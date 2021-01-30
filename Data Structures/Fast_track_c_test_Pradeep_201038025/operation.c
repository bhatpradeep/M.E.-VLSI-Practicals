#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"header.h"
#include <string.h>

int writing_into_file(int iteration)
{

    FILE *fpointer;
    int i = 1;
    int j;
    
    while (i<=iteration) 
    {
        char to_open[32];
        snprintf(to_open, 32, "file%d.txt", i);

        if ((fpointer = fopen(to_open, "w")) == NULL)
        {
            return 0;
            break;
        }

        for(j=0; j<=i;j++)
        {
          fprintf(fpointer,"%d ", j); // Use of fprintf() function
        }

        fclose(fpointer); // close the file after work is done

        i++;
    }
    
    return 1;
}

int reading_from_file(int iteration)
{

     char character;
     FILE *fpointer;
     char b;
     int i = 1;
     while (i<=iteration) 
     {
          char to_open[32];
          
          snprintf(to_open, 32, "file%d.txt", i);
          printf("\nfile%d.txt : ", i);
        
          if ((fpointer = fopen(to_open, "r")) == NULL)
          {
                 return 0;
                 break;
          }

         while (fscanf(fpointer, "%c", &b) > 0)
         {
                printf("%c ",b);
         }

         fclose(fpointer); // close the file after work is done

         i++;
     }
 
     
     return 1;
}



int rewrite_the_files(int iteration)
{
    FILE *f_read_temp, *f_write_temp, *f_read, *f_write, *f_read_first, *f_write_last; 
 
    char c;
    int k=1; 
    
    char to_open[32];
    char to_open1[32];
    char to_open_last[32];
        
    f_read_first = fopen("file1.txt", "r");
   
    if (f_read_first == NULL) 
	{ 
		printf("Cannot open file %s \n", to_open); 
		exit(0); 
	} 
	
	
	f_write_temp = fopen("file_temp.txt", "w");
    c = fgetc(f_read_first); 
    
    
	while (c != EOF) 
	{ 
		fputc(c, f_write_temp); 
		c = fgetc(f_read_first); 
	} 

	
	fclose(f_read_first); 
	fclose(f_write_temp);
    

    snprintf(to_open_last, 32, "file%d.txt", iteration);
    
    while (k<iteration) 
    {

        
        snprintf(to_open, 32, "file%d.txt", k+1);
        snprintf(to_open1, 32, "file%d.txt", k);


        f_read = fopen(to_open, "r"); 
	
	    
	    if (f_read == NULL) 
	    { 
		          printf("Cannot open file %s \n", to_open); 
		          exit(0); 
	    } 

	// Open another file for writing 
	    f_write = fopen(to_open1, "w"); 
	    if (f_write == NULL) 
	    { 
		          printf("Cannot open file %s \n", to_open1); 
		          return 0;
		          exit(0); 
	    } 

	// Read contents from file 
	    c = fgetc(f_read); 
	    
	    while (c != EOF) 
	    { 
		         fputc(c, f_write); 
		         c = fgetc(f_read); 
	    } 

	//printf("\nContents copied to %s", filename); 

	   fclose(f_read); 
	   fclose(f_write); 

        k++;
    }
    
    f_write_last = fopen(to_open_last, "w"); 
    
    if (f_write_last == NULL) 
	{ 
		printf("Cannot open file %s \n", to_open_last); 
		return 0;
		exit(0); 
	} 
	
	f_read_temp = fopen("file_temp.txt", "r");
	c = fgetc(f_read_temp); 
	
	while (c != EOF) 
	{ 
		fputc(c, f_write_last); 
		c = fgetc(f_read_temp); 
	} 
	
	fclose(f_read_temp);
	fclose(f_write_last);
	
	remove("file_temp.txt");

    
  
    return 1;


}

int delete_files(int iteration)
{
     int i = 1;
     while (i<=iteration) 
     {
          char to_open[32];
          
          snprintf(to_open, 32, "file%d.txt", i);
          
          
          remove(to_open);
          
         i++;
     }
    return 1;
}
