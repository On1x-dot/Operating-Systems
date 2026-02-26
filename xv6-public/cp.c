#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h" 

int
main(int argc, char *argv[])
{
  char buf[512];
  int fd_origen, fd_destino;
  int n;

  if(argc <= 2){
    printf(1, "Uso: cp origen destino\n");
    exit();
  }

  if((fd_origen = open(argv[1], O_RDONLY)) < 0){
    printf(1, "cp: no se pudo abrir %s\n", argv[1]);
    exit();
  }

  if((fd_destino = open(argv[2], O_WRONLY | O_CREATE)) < 0){
    printf(1, "cp: no se pudo crear %s\n", argv[2]);
    close(fd_origen);
    exit();
  }

  while((n = read(fd_origen, buf, sizeof(buf))) > 0){
    if(write(fd_destino, buf, n) != n){
      printf(1, "cp: error al escribir en %s\n", argv[2]);
      break;
    }
  }

  if(n < 0){
    printf(1, "cp: error al leer de %s\n", argv[1]);
  }

  close(fd_origen);
  close(fd_destino);

  exit();
}