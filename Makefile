SOURCES = main.cpp Compiler.cpp Node.cpp VM.cpp Parser.yy Scanner.ll
HEADERS = Compiler.h Node.h VM.h VMCode.h VMValue.h
OBJ = main.o Compiler.o Node.o VM.o Parser.o Scanner.o
BISON_OUTPUT = Parser.cc Parser.hh location.hh position.hh

CFLAGS = -O2 

all: script

.SUFFIXES:
.SUFFIXES: .cpp .cc .ll .yy .o

script: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) -lstdc++

.cpp.o:
	$(CC) -c $(CFLAGS) -o $@ $<

.cc.o:
	$(CC) -c $(CFLAGS) -o $@ $<

$(BISON_OUTPUT): Parser.yy
	bison -d -ra -oParser.cc Parser.yy

Scanner.cc: Scanner.ll
	flex -8 -oScanner.cc Scanner.ll

Parser.o: $(BISON_OUTPUT)
Scanner.o: Scanner.cc

depend:
	makedepend -- $(CFLAGS) -- $(SOURCES)

main.o: Parser.hh
Node.o: location.hh

main.o: Compiler.h Parser.hh stack.hh Node.h location.hh position.hh
main.o: VM.h VMValue.h VMCode.h
Compiler.o: Compiler.h Parser.hh stack.hh Node.h location.hh
Compiler.o: position.hh VM.h VMValue.h VMCode.h
Node.o: Node.h location.hh position.hh VM.h VMValue.h VMCode.h Compiler.h
Node.o: Parser.hh stack.hh
VM.o: VM.h VMValue.h VMCode.h
Parser.o: Node.h location.hh position.hh VM.h VMValue.h VMCode.h
Parser.o: Compiler.h Parser.hh stack.hh
Scanner.o: Compiler.h Parser.hh stack.hh Node.h location.hh
Scanner.o: position.hh VM.h VMValue.h VMCode.h

