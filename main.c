#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char byte;
    char *buf[32];

    int i;
    for(i=0;i<32;i++) {
        buf[i] = 0;
    }

    int fd = open("/dev/usbtmc0", O_RDWR);

    //char *command  = "VOLT:DC:RANG 7\n";
    //char *command  = "MEAS:DIOD?\n";
    char *command = "VOLT:DC:RANG?\n";
    int so = sizeof(command);

    write(fd, command,  13);
    //write(fd, command2, 18);

    ssize_t size = read(fd, &buf, 32);

    char x = buf[0];
    char y = buf[1];

    printf("Read byte %d %d | %c %c\n", x, y , buf[0], buf[1]);
    printf("Size %d\n", size);

    return 0;
}
