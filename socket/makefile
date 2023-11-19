CC = gcc
CFLAGS = -Wall
BIN_DIR = bin

all: directories ip_addresses showip

directories: ${BIN_DIR}

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

ip_addresses: ip_addresses.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/ip_addresses ip_addresses.c

showip: showip.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/showip showip.c

clean:
	rm -rf $(BIN_DIR)