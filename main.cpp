 #include "mbed.h"
 #include "SDFileSystem.h"
                                                                    //Create an SDFileSystem object
SDFileSystem sd(P0_23, P0_25, P0_24, P0_22, "sd");                          // Pins voor de SD kaartlezer
 
 int main()
 {
      //Perform a write test
      printf("\nWriting to SD card...");
      FILE *fp = fopen("/sd/sdtest.txt", "w");
      if (fp != NULL) {
          fprintf(fp, "We're writing to an SD card!");
          fclose(fp);
          printf("success!\n");
      } else {
          printf("failed!\n");
      }
 
      //Perform a read test
      printf("Reading from SD card...");
      fp = fopen("/sd/sdtest.txt", "r");
      if (fp != NULL) {
          char c = fgetc(fp);
          if (c == 'W')
              printf("success!\n");
          else
              printf("incorrect char (%c)!\n", c);
          fclose(fp);
      } else {
          printf("failed!\n");
     }
     while(1){}
  }