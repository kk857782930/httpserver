all: httpd

httpd: httpd.c
	gcc -W -Wall -pthread -o httpd httpd.c cJSON.c

clean:
	rm -f httpd