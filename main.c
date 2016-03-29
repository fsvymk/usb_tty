#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char byte;
    char *buf[1024];

    int fd = open("/dev/usbtmc0", O_RDWR);

    char *command  = "VOLT:DC:RANG 7\n";
    char *command2 = "VOLT:DC:RANG?\n";
    int so = sizeof(command);

    write(fd, command,  18);
    //write(fd, command2, 18);

    ssize_t size = read(fd, &buf, 512);
    printf("Read byte %c\n", byte);
    printf("Size %d\n", size);

    return 0;
}
