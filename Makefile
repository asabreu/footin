GDBM_DIR=/usr/local/Cellar/gdbm/1.12
CFLAGS+=-I$(GDBM_DIR)/include
LDFLAGS+=-L$(GDBM_DIR)/lib -lgdbm

CFLAGS+=-Wall -Werror -std=gnu99 -O2 

TARGETS=footin
OBJS=action.o storage.o display.o countries.o stats.o 

all: $(TARGETS)

clean:
	$(RM) $(TARGETS)
	$(RM) $(OBJS)

footin: $(OBJS) footin.o
	$(CC) -o $@ $^ $(LDFLAGS) 

.PHONY: all clean
