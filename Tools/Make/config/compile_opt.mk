# SVN-Id: $Id: compile_opt.mk 52032 2017-01-17 13:19:54Z ostwal01 $
# SVN-Url: $HeadURL: http://debesvn001/kostal/lk_ae_internal/LK/Eclipse/ProjectTemplate/trunk/Tools/Make/config/compile_opt.mk $

######################################################################
#
# MAKEFILE TEMPLATE AEP2
#
# See /doc for detailed documentation
#
# Compiler related options. 
#
# This is a user configuration file and intended to be modified.
#
######################################################################

# Compiler executable
CC = $(COMPILER_PATH)/arm-none-eabi-gcc.exe

# Compiler options common to all build modes.
CFLAGS_COMMON =-std=c99 -Og -fno-jump-tables -funsigned-char	\
				-g -pedantic -Wall -Wextra -c -fmessage-length=0	\
				-funsigned-bitfields -ffunction-sections -D__VFP_FP__=1 -D__SOFTFP__=0	\
				-fdata-sections -fno-common -Wunused -Wstrict-prototypes	\
				-Wsign-compare -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16	\
				--specs=nano.specs -fmax-include-depth=2000	\
				--sysroot="D:\Compiler\32-Bit\ArmGccV10.3\arm-none-eabi\lib"
				      
# Compiler options specific to 'debug' build mode.
CFLAGS_DEBUG  = ${CFLAGS_COMMON} -g -DLK_DEBUG

#Compiler options specific to 'release' build mode.
CFLAGS_RELEASE = ${CFLAGS_COMMON}

######################################################################
# Compiler defines
######################################################################

# List of defines
#
# The -D option has to be omitted here since it is programmatically
# added to each string afterwards
CC_DEFLIST = DEV_ERROR_DETECT	\
			DISABLE_MCAL_INTERMODULE_ASR_CHECK	\
			__VFP_FP__
			
			
       
######################################################################
# Dependency Check
######################################################################

ifneq (${DEP_CHECK_GNU}, ON)
# GNU Dependency check is disabled.
#
# If capable, target compiler may carry out this task on 
# single source compile.
# Example: IAR compiler:
#   CC_DEP_CHECK = "--dependencies=m ${DepFilePattern}"
# Example: GNU compiler:
#   CC_DEP_CHECK = "-MM -E -MT ${DepFilePattern} -MF ${DepFilePattern}"  
CC_DEP_CHECK = 
else
# GNU Dependency check is enabled and executed automatically with the
# correct options.
endif


######################################################################
# G N U   D E F I N E S
#
# CC_DEFINES_GNU is passed to GNU compiler call for dependency
# retrieval. You may add here definitions specific to your target
# compiler, like __CTC__ for Tasking compiler. As default, the common
# CC_DEFINES are assigned here.
#
# Example:
#   CC_DEFINES_GNU = ${CC_DEFINES} -D__CTC__
######################################################################
CC_DEFLIST_GNU = ${CC_DEFLIST}
