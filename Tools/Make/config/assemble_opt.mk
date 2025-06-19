# SVN-Id: $Id: assemble_opt.mk 52032 2017-01-17 13:19:54Z ostwal01 $
# SVN-Url: $HeadURL: http://debesvn001/kostal/lk_ae_internal/LK/Eclipse/ProjectTemplate/trunk/Tools/Make/config/assemble_opt.mk $

######################################################################
#
# MAKEFILE TEMPLATE AEP2
#
# See /doc for detailed documentation
#
# Assembler related options. 
#
# This is a user configuration file and intended to be modified.
#
######################################################################


# Assembler executable
# Example:
#   ASM = $(COMPILER_PATH)/arm-none-eabi-gcc.exe
ASM = $(COMPILER_PATH)/arm-none-eabi-gcc.exe

# Assembler options common for all build modes
AFLAGS_COMMON = -c -x assembler-with-cpp -g3 -mcpu=cortex-m4 	\
				-mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nano.specs	\
				--sysroot="D:\Compiler\32-bit\ArmGcc_V10_3\arm-none-eabi\lib"	\
			    -r -l ${ListDir}/$(basename $@).lst
			    

# Assembler options specific to build mode 'release'.
AFLAGS_RELEASE = ${AFLAGS_COMMON}

# Assembler options specific to build mode 'debug'.
AFLAGS_DEBUG = ${AFLAGS_COMMON}

