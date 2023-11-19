CC = gcc
CFLAGS = -Wall -lrt

TARGET1 = shm_write
TARGET2 = shm_read
BINDIR = bin

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(TARGET1).c
	$(CC) $(CFLAGS) -o $(BINDIR)/$(TARGET1) $(TARGET1).c

$(TARGET2): $(TARGET2).c
	$(CC) $(CFLAGS) -o $(BINDIR)/$(TARGET2) $(TARGET2).c

clean:
	rm -f $(BINDIR)/$(TARGET1) $(BINDIR)/$(TARGET2)