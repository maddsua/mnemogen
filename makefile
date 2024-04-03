CFLAGS			=	-Wall -Werror -std=c++20

TEMP_DATA_DIR	=	var

BIP39_FILE		=	$(TEMP_DATA_DIR)/bip39.txt
PIB39_REMOTE	=	https://raw.githubusercontent.com/bitcoin/bips/cf0b529e78860fa2d4fe77944091aa98c5e04624/bip-0039/english.txt
BIP39_BINARY	=	bip39tokens.res

BINRES_TARGET	=	$(if $(filter $(OS),Windows_NT),pe-x86-64,elf64-x86-64)

CLEAN_GLOBS		=	*.o *.exe *.a *.dll *.so *.res var
CLEAN_COMMAND	=	$(if $(filter $(OS),Windows_NT),del /S /F /Q $(CLEAN_GLOBS),rm -rf $(CLEAN_GLOBS))

TEXT_BINS		=	text.help.res

BUILD_APP_DEPS	=	$(BIP39_BINARY) $(TEXT_BINS) args.o random.o text.o tokens.o main.o

PROGRAM_EXT		=	$(if $(filter $(OS),Windows_NT),.exe,)

.PHONY: all all-before all-after action-custom
all: all-before app all-after

clean: action-custom
	$(CLEAN_COMMAND)

$(BIP39_FILE):
	-mkdir $(TEMP_DATA_DIR)
	wget $(PIB39_REMOTE) -O $(BIP39_FILE)

$(BIP39_BINARY): $(BIP39_FILE)
	objcopy --input-target binary --output-target $(BINRES_TARGET) --binary-architecture i386:x86-64 $(BIP39_FILE) $(BIP39_BINARY)

text.help.res: src/text/help.txt
	objcopy --input-target binary --output-target $(BINRES_TARGET) --binary-architecture i386:x86-64 src/text/help.txt text.help.res

args.o: src/args.cpp
	g++ -c $(CFLAGS) src/args.cpp -o args.o

random.o: src/random.cpp
	g++ -c $(CFLAGS) src/random.cpp -o random.o

tokens.o: src/tokens.cpp
	g++ -c $(CFLAGS) src/tokens.cpp -o tokens.o

text.o: src/text.cpp
	g++ -c $(CFLAGS) src/text.cpp -o text.o

main.o: src/main.cpp
	g++ -c $(CFLAGS) src/main.cpp -o main.o

app: $(BUILD_APP_DEPS)
	g++ -s $(BUILD_APP_DEPS) -static -o mnemogen$(PROGRAM_EXT)

bip39.test: test/bip39.test.cpp bip39tokens.res tokens.o
	g++ bip39tokens.res tokens.o test/bip39.test.cpp -o bip39.test$(PROGRAM_EXT)
