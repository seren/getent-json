CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS=-ljson-c
SOURCES=src/getent-json.c \
				src/getent_passwd.c \
				src/getent_group.c \
				src/getent_shadow.c \
				src/getent_gshadow.c \
				src/getent_hosts.c \
				src/getent_aliases.c \
				src/getent_protocols.c \
				src/getent_services.c \
				src/getent_rpc.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=bin/getent-json

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p bin
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f src/*.o bin/getent-json
