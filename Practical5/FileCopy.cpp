#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcltl.h>

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    std::cerr<<"Usage: ./main <src> <dest>\n";
    return -1;
  }

  char buf;
  ssize_t bytes;
  int fdSrc, fdDest;
  mode_t wrMode = 0777;

  if ((fdSrc = open(argv[1], O_RDONLY)) < 0)
  {
    std::cerr<<"Could not read\n"<<argv[1];
    return 2;
  }

  if ((fdDest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, wrMode)) < 0)
  {
    std::cerr<<"Could not write to\n"<<argv[2];
    return 2;
  }

  while ((bytes = read(fdSrc, &buf, 1)) > 0)
    write(fdDest, &buf, 1);

  if (bytes < 0)
  {
    std::cerr<<"Could not read contents of\n"<<argv[1];
    return 2;
  }

  if (bytes == 0)
    write(fdDest, "\n", 1);

  std::cout<<"Copied contents of\n"<<argv[1]<<"to"<<argv[2];

  close(fdSrc);
  close(fdDest);

  if ((fdDest = open(argv[2], O_RDONLY)) < 0)
  {
    std::cerr<<"Could not read\n"<<argv[2];
    return 2;
  }

  while ((bytes = read(fdSrc, &buf, 1)) > 0)
    printf("%c", buf);

  close(fdDest);

  return 0;
}