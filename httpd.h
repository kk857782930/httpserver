typedef unsigned short u_short;

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>

#define ISspace(x) isspace((int)(x))

#define SERVER_STRING "Server: jdbhttpd/0.1.0\r\n"
#define S_IFMT		__S_IFMT
#define S_IFDIR	__S_IFDIR


void  accept_request(int);
void  bad_request(int);
void  cat(int, FILE *);
void  cannot_execute(int);
void  error_die(const char *);
void  execute_cgi(int, const char *, const char *, const char *);
int   get_line(int, char *, int);
void  headers(int, const char *);
void  not_found(int);
void  serve_file(int, const char *);
int   startup(u_short *);
void  unimplemented(int);
void  send_json_response(int client, const char *json);
void  send_error_response(int client, int code, const char *message);
char* process_lamp_command(int handle, const char *time_str,int brightness);
void  handle_lamp_request(int client, const char *method, const char *query_string);


