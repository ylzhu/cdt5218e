#
# Makefile
# Author£ºCdt_ZhengJH

.SUFFIXES:
.PHONY:		force
.PHONY:		all clean depends bak debug tar

sinclude	../Makefile.sutl
GOAL		= libcdt1028drv.a
INCLUDE_DIR	= -I. -I../ -I../h -I../ir_vfd -I../nav/ -I../dsp3 -I../setup -Idrv/ -Iinc/

#
# generic flags
#
CFLAGS_SUPPORT	=
CFLAGS_SIM	=
CFLAGS_COMPILE	= -ffunction-sections
#CFLAGS_COMPILE	= $(CFLAGS_SUPPORT) $(CFLAGS_SIM)

#
# Sources
#
		
SOURCES	= \
		cdt1028drv.c \
		
SOURCES_TMP = $(notdir $(SOURCES))
		
DEPENDS_C	= \
		$(addprefix MIPS/,$(SOURCES_TMP:.c=.d))

DEPENDS		= $(DEPENDS_C)

OBJS		= $(DEPENDS:.d=.o)
ASMS		= $(DEPENDS:.d=.s))
DISASMS		= $(DEPENDS:.d=.dis))

#SUBDIR = inc 
#
# main target
#
all:	$(GOAL)
	@$(ECHO) \"$(GOAL) made\"


#
#
#
$(GOAL): MIPS $(OBJS) force
	@$(ECHO) \"update library..\" 
#cp drv/mips/*.o ./mips/
	@$(ECHO) \"ar -cr $(OBJS)\"
	@$(XAR) -cr $(GOAL) $(OBJS)
	
$(OBJS)	: $(SOURCES)

#
#
#
ifneq ($(MAKECMDGOALS),clean)
sinclude	$(DEPENDS)
endif


