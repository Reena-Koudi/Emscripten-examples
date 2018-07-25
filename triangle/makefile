CC=emcc
SOURCES= ../../source/emscripten/main.cpp  ../../source/emscripten/GLApp.cpp  ../../source/emscripten/common/esUtil.cpp
CPPFLAGS=-I ../../source -I ../../source/emscripten -I ../../source/emscripten/common 
LDFLAGS=-O3 --llvm-opts 2 --llvm-lto 1
OUTPUT=GLApp.js

all: $(SOURCES) $(OUTPUT)

$(OUTPUT): $(SOURCES) 
	$(CC) $(SOURCES) $(CPPFLAGS) --bind -s MODULARIZE=1 -s USE_WEBGL2=1  -s EXPORT_NAME="'GLApp'" -s TOTAL_MEMORY=67108864 -s AGGRESSIVE_VARIABLE_ELIMINATION=1 -s ELIMINATE_DUPLICATE_FUNCTIONS=1 -s INLINING_LIMIT=1 -s NO_EXIT_RUNTIME=1 -s EXPORTED_FUNCTIONS="['_malloc','_free']" -std=c++11  $(LDFLAGS) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)
