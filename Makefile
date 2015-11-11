PLATFORM=apple2enh
PGM=adder
AC=java -jar c:/users/usucuha/bin/AppleCommander-1.3.5.jar

CC65_HOME=c:/users/usucuha/retrocomputing/cc65/bin

$(PGM): $(PGM).c a2e.hi.o $(PGM).po
	$(CC65_HOME)/cl65 -t $(PLATFORM) --lib a2e.hi.o -O $(PGM).c
	$(AC) -d $(PGM).po $(PGM)
	$(AC) -cc65 $(PGM).po $(PGM) BIN < $(PGM)

all: $(PGM) $(PGM).po

a2e.hi.o:
	$(CC65_HOME)/co65 --code-label _a2e_hi prodos-raw/a2e.hi.tgi
	$(CC65_HOME)/ca65 prodos-raw/a2e.hi.s
	mv prodos-raw/a2e.hi.o .

$(PGM).po:
#	$(AC) -pro140 $(PGM).po $(PGM)
	cp prodos-raw/blank.po ./$(PGM).po
	$(AC) -p $(PGM).po PRODOS SYS < prodos-raw/PRODOS
	$(AC) -p $(PGM).po BASIC.SYSTEM SYS < prodos-raw/BASIC.SYSTEM
#	$(AC) -p $(PGM).po A2E.HI.TGI BIN <prodos-raw/a2e.hi.tgi

clean:
	rm -f $(PGM)
	rm -f *.o

clean-disk:
	rm -f $(PGM).po

clean-all: clean clean-disk
