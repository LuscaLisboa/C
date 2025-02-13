CC = x86_64-w64-mingw32-gcc
CFLAGS = -I"C:/msys64/mingw64/include" -I"C:/msys64/mingw64/include/freetype2"
LDFLAGS = -L"C:/msys64/mingw64/lib"
LIBS = -lmingw32 -lglew32 -lglfw3 -lopengl32 -lgdi32 -lfreetype -lkernel32 -lmsvcrt

SOURCES = main.c rccShader.c rText.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = main.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del $(OBJECTS) $(EXECUTABLE)