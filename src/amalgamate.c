int main() {
    include("begin.c");
        include("balz.c");
        include("bcm_bwt.c");
        include("bcm.c");
        include("crush.c");
        include("deflate.c");
        include("lz4x.c");
        include("lzma.c");
        include("lzp1.c");
        include("lzrw3a.c");
        include("lzss.c");
        include("ppp.c");
        include("raw.c");
        include("ulz.c");
        include("zip.c");
        include("tar.c");
        include("pak.c");
        include("vfs.c");
        include("dir.c");
    include("end.c");
}

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int include( const char *file ) {
#ifdef _WIN32
    char cmd[256] = {0}, *cat = "type", *echoln = "echo.";
#else
    char cmd[256] = {0}, *cat = "cat", *echoln = "echo";
#endif
    struct stat st = {0};
    if( stat(file, &st) < 0 ) {
        snprintf( cmd, 256, "echo #include \"%s\" /* amalgamate: warning: cannot find file */ && %s", file, echoln );
        return system( cmd ), fprintf(stderr, "Warning: cannot find '%s'\n", file), -1;
    } else {
        snprintf( cmd, 256, "echo #line 1 \"%s (amalgamated)\" && %s %s && %s", file, cat, file, echoln );
        return system( cmd );
    }
}
