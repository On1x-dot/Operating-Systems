#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main() {
    const char* archivo = "test.txt";
    const char* banner = 
        "[Virus instalado]";
    int fd = open(archivo, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) return 1;

    write(fd, banner, strlen(banner));
    close(fd);
    return 0;


}