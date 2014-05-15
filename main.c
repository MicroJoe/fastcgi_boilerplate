#include <fcgi_stdio.h> /* fcgi library; put it first*/
#include <stdlib.h>

char *elems[] = {
    "REQUEST_URI", "REQUEST_METHOD", "QUERY_STRING", "DOCUMENT_ROOT",
    "HTTP_COOKIE", "HTTP_HOST", "HTTP_REFERER", "HTTP_USER_AGENT",
    "REMOTE_ADDR", "REMOTE_HOST", "REMOTE_PORT", "REMOTE_USER",
    "SCRIPT_NAME", "SCRIPT_FILENAME",
    "SERVER_ADMIN", "SERVER_NAME", "SERVER_PORT", "SERVER_SOFTWARE",
    ""
};

int main(void)
{
    int i;
    char *buff;

    /* Response loop. */
  while (FCGI_Accept() >= 0)   {
    printf("Content-type: text/html\r\nStatus: 200 OK\r\n\r\n");
    printf(
        "<!doctype html>\r\n"
        "<html>"
        "<head>"
        "<title>FastCGI works!</title>"
        "<meta charset=\"utf-8\" />"
        "</head>"
        "<body>"
        "<h1>Hello from FastCGI</h1>"
        "<p>If you see this page, then your FastCGI configuration works!</p>"
        "<p>Here are some environment variables read from FastCGI :</p>");

    printf("<table>");

    i = 0;
    while (elems[i++][0] != '\0')
    {
        buff = getenv(elems[i]);
        if (buff != NULL)
        {
            printf("<tr><td>%s</td><td>%s</td></tr>", elems[i], buff);
        }
    }

    printf("</table></body></html>");
  }

  return 0;
}
