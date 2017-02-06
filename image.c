#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
  int fd = open("image.ppm", O_CREAT | O_WRONLY, 0644);

  char buffer[20];
  char header[] = "P3 512 512 255\n";
  write(fd, header, strlen(header));
  int i = 0;
  int j = 0;
  int r = 0;
  int g = 0;
  int b = 0;
  while(i < 512){
    while(j < 512){
      r = 255-j%256;
      g = j%256;
      b = i%256;
      snprintf(buffer,sizeof(buffer), "%d %d %d\n",r,g,b);
      
      write(fd, buffer,strlen(buffer));
      j++;
    }
    i++;
    j=0;
  }
  return 0;
 
}
