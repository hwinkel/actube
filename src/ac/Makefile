
include ../Config.mak
include ../Macros.mak

ifndef CC
        CC=gcc
endif
SYSARCH := $(shell uname -m)
ifndef ARCH
#        ARCH=$(SYSARCH)
	ARCH = $(shell $(CC) -dumpmachine)
endif

LDFLAGS+=-g -D_REENTRANT -L/usr/local/lib -L../capwap/$(ARCH) 

CFLAGS += -I$(OPENSSLINC) -Wall -g -O0 -D_REENTRANT -DIPV6 -I/usr/local/include -I../capwap  



LIBS+=-lcapwap
LIBS+=-lrt
ifdef WITH_GNUTLS

else
endif


#LIBS+=-lcrypto
LIBS+=-lpthread
LIBS+=-lconfuse
LIBS+=-lsqlite3
LIBS+=-ldl


ifeq ($(SSL_LIBRARY),GNUTLS)
CFLAGS+=-DWITH_GNUTLS
LIBS+=-lgnutls
else
CFLAGS+=-DWITH_OPENSSL
LIBS+=$(OPENSSLLIB)
endif

CFLAGS += -DWITH_CW_LOG
CFLAGS += -DWITH_CW_LOG_DEBUG
CFLAGS += -DWITH_RMAC_SUPPORT
CFLAGS += -DWITH_DTLS
CFLAGS += -DWITH_IPV6
#CFLAGS += -DWITH_LWAPP

RM = /bin/rm -f 

# list of generated object files for AC. 
AC_OBJS =   wtplist.o wtpman.o conf.o ac_main.o \
	    ac_interface.o \
	    socklist.o \
	    db.o \

AC_SRCS = $(AC_OBJS:.o=.c) 
AC_DEPS := $(AC_OBJS:.o=.d)

AC_NAME = actube

.PHONY: deps clean clean_libs libs

# top-level rule, to compile everything. 
all: $(AC_NAME) 

$(AC_NAME): $(AC_OBJS) 
	$(CC) $(AC_OBJS) $(CC_FLAGS) $(OPENSSL_INCLUDE) -o $(AC_NAME) $(LDFLAGS) $(LIBS) 


clean: 
	$(RM) $(AC_NAME) $(AC_OBJS) $(AC_DEPS)

clean_deps:
	$(AC_DEPS) 
	
deps: $(AC_SRC) 
	$(CC) -MD -E $(AC_SRCS) $(CFLAGS) >/dev/null

-include $(AC_DEPS)
