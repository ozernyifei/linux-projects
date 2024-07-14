
#include "fcgi_stdio.h"
#include <stdlib.h>

int main(int argc, char* const argv[] )

{
    while(FCGI_Accept() >= 0)
    {
        printf("Content-type: text/html\r\n\r\n<TITLE>fastcgi</TITLE>\n<H1>Fastcgi: Hello world.</H1>\n");
    }
    return 0;

}