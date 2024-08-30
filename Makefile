# Naziv izlaznog fajla
TARGET = filozofi

# Naziv fajla sa kodom
SRCS = program.c

# C kompajler
CC = gcc

# Opcije za kompajler
CFLAGS = -Wall -pthread

# Pravilo za kreiranje izvršnog fajla
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Pravilo za čišćenje kompajliranih fajlova
clean:
	rm -f $(TARGET)

