# *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
# ** Copyright UCAR (c) 1992 - 2010 
# ** University Corporation for Atmospheric Research(UCAR) 
# ** National Center for Atmospheric Research(NCAR) 
# ** Research Applications Laboratory(RAL) 
# ** P.O.Box 3000, Boulder, Colorado, 80307-3000, USA 
# ** 2010/10/7 23:12:34 
# *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
###########################################################################
#
# Makefile for the DsAccess module of the didss library
#
# Nancy Rehak, RAP, NCAR, Boulder, Co, USA, 80307
#
# November 2000
#
###########################################################################

include $(RAP_MAKE_INC_DIR)/rap_make_macros

TARGET_FILE = ../libdidss.a

LOC_INCLUDES = -I../include
LOC_CFLAGS =

HDRS = \
	../include/didss/DsAccess.hh \
	../include/didss/DsAccessFile.hh \
	../include/didss/IPAddress.hh

CPPC_SRCS = \
	DsAccess.cc \
	DsAccessFile.cc \
	IPAddress.cc

#
# general targets
#

include $(RAP_MAKE_INC_DIR)/rap_make_lib_module_targets

#
# local targets
#

depend: depend_generic

# DO NOT DELETE THIS LINE -- make depend depends on it.
