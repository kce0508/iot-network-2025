#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

void error_handling(const char *msg);

int main()
{
    int serv_sock, clnt_sock;
    char request[BUF_SIZE];
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;

    char webpage[] = "HTTP/1.1 200 OK\r\n"
        "Server: Linux Web Server\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n\r\n"
        "<!DOCTYPE html>\r\n"
        "<html><head><title> My Web Page </title>\r\n"
        "<style>body {background-color: #FFFF00 }</style></head>\r\n"
        "<body><center><h1>Hello world!!</h1><br>\r\n"
        "<img src=\"Sylvanian.jpg\"></center></body></html>\r\n";

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(8080); // 브라우저 접속 포트

    if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");

    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    printf("웹서버 실행 중... 브라우저에서 http://<IP>:8080 으로 접속해보세요\n");

    clnt_adr_sz = sizeof(clnt_adr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

    read(clnt_sock, request, BUF_SIZE - 1);
    printf("요청 메시지 수신:\n%s\n", request);

	if (strstr(request, "GET /Sylvanian.jpg") != NULL) {
		FILE *img = fopen("Sylvanian.jpg", "rb");
		if(img == NULL) {
			error_handling("Image file open failed");
		}

		char img_header[] =
			"HTTP/1.1 200 OK\r\n"
			"Content-Type: image/jpeg\r\n\r\n";
		write(clnt_sock, img_header, strlen(img_header));

		char img_buf[BUF_SIZE];
		int read_cnt;
		while ((read_cnt = fread(img_buf, 1, BUF_SIZE, img)) > 0) {
			write(clnt_sock, img_buf, read_cnt);
		}
		fclose(img);
	}
    // GET 또는 POST 처리
    else if (strncmp(request, "GET", 3) == 0 || strncmp(request, "POST", 4) == 0) {
        write(clnt_sock, webpage, strlen(webpage));
    } else {
        char notfound[] = "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n";
        write(clnt_sock, notfound, strlen(notfound));
    }

    close(clnt_sock);
    close(serv_sock);
    return 0;
}

void error_handling(const char *msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
