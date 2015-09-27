include ../Make.rule

LCFLAG = -g

all : MergeSortMain.o QuickSortMain.o SortMain.o dsmain.o myMain.o
		ls *.o

MergeSortMain.o : MergeSortMain.c
	$(CC) $(LCFLAG) $< -o $@ -L$(LIB_DIR) -lds

QuickSortMain.o : QuickSortMain.c
	$(CC) $(LCFLAG) $< -o $@ -L$(LIB_DIR) -lds

SortMain.o : SortMain.c
	$(CC) $(LCFLAG) $< -o $@ -L$(LIB_DIR) -lds

dsmain.o : dsmain.c
	$(CC) $(LCFLAG) $< -o $@ -L$(LIB_DIR) -lds

myMain.o : myMain.c
	$(CC) $(LCFLAG) $< -o $@ -L$(LIB_DIR) -lconversion

clean :
	$(RM) *.o 
