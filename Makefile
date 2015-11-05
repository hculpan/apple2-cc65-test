PLATFORM=apple2enh
PGM=adder
AC=java -jar c:/users/usucuha/bin/AppleCommander-1.3.5.jar

CC65_HOME=c:/users/usucuha/retrocomputing/cc65/bin

$(PGM): $(PGM).c $(PGM).po
	$(CC65_HOME)/cl65 -t $(PLATFORM) -O $(PGM).c
	$(AC) -d $(PGM).po $(PGM)
	$(AC) -cc65 $(PGM).po $(PGM) BIN < $(PGM)

all: $(PGM) $(PGM).po

$(PGM).po:
#	$(AC) -pro140 $(PGM).po $(PGM)
	cp prodos-raw/blank.po ./$(PGM).po
	$(AC) -p $(PGM).po PRODOS SYS < prodos-raw/PRODOS
	$(AC) -p $(PGM).po BASIC.SYSTEM SYS < prodos-raw/BASIC.SYSTEM
	$(AC) -p $(PGM).po A2E.HI.TGI BIN <prodos-raw/a2e.hi.tgi

clean:
	rm -f $(PGM)
	rm -f *.o

clean-disk:
	rm -f $(PGM).po

clean-all: clean clean-disk
