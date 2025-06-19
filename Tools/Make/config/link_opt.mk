# SVN-Id: $Id: link_opt.mk 52032 2017-01-17 13:19:54Z ostwal01 $
# SVN-Url: $HeadURL: http://debesvn001/kostal/lk_ae_internal/LK/Eclipse/ProjectTemplate/trunk/Tools/Make/config/link_opt.mk $

######################################################################
#
# MAKEFILE TEMPLATE AEP2
#
# See /doc for detailed documentation
#
# Linker related options. 
#
# This is a user configuration file and intended to be modified.
#
######################################################################

# Linker executable
# Example:
#   LD = $(COMPILER_PATH)/bin/xlink.exe
LD = ${COMPILER_PATH}/arm-none-eabi-gcc.exe

# Linker options common for all build modes.
LDFLAGS_COMMON =-T"${BaseDir}/Tools/Make/config/STM32F407VGTX_FLASH.ld"	\
				-Xlinker --gc-sections -n -mcpu=cortex-m4 -mthumb	\
				-mfloat-abi=hard -mfpu=fpv4-sp-d16 -specs=nano.specs	\
				--sysroot="D:\Compiler\32-Bit\ArmGccV10.3\arm-none-eabi\lib"	\
				-Wl,-Map=${BinDir}/target_$(BUILDMODE).map
		

#LDFLAGS_COMMON =-L"D:\ArmGcc_V10_3\ArmGcc_V10_3\arm-none-eabi\lib\libc.a"
#LDFLAGS_COMMON =-L"D:\ArmGcc_V10_3\ArmGcc_V10_3\arm-none-eabi\lib\libg.a"
#LDFLAGS_COMMON =-L"D:\ArmGcc_V10_3\ArmGcc_V10_3\arm-none-eabi\lib\libm.a"
#LDFLAGS_COMMON =-L"D:\ArmGcc_V10_3\ArmGcc_V10_3\arm-none-eabi\lib\libnosys.a"
#LDFLAGS_COMMON =-L"D:\ArmGcc_V10_3\ArmGcc_V10_3\arm-none-eabi\lib\libg_nano.a"
#LDFLAGS_COMMON =-L"D:\ArmGcc_V10_3\ArmGcc_V10_3\arm-none-eabi\lib\libgloss-linux.a" 
#LDFLAGS_COMMON =-L"D:\ArmGcc_V10_3\ArmGcc_V10_3\arm-none-eabi\lib\librdimon-v2m.a"
#LDFLAGS_COMMON =-L"\ArmGcc_V10_3\ArmGcc_V10_3\arm-none-eabi\lib\librdimon.a"

# Linker options specific to 'release' build mode.
LDFLAGS_RELEASE = ${LDFLAGS_COMMON}

# Linker options specific to 'debug' build mode.
LDFLAGS_DEBUG   = ${LDFLAGS_COMMON} -g
