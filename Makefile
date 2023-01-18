all: clean build
build:
	@gcc main.c -o fsize
install:
	@mv -v fsize /usr/local/bin
uninstall:
	@rm -rf /usr/local/bin/fsize
clean:
	@rm -rf fsize
