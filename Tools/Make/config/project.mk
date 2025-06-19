# SVN-Id: $Id: project.mk 52032 2017-01-17 13:19:54Z ostwal01 $
# SVN-Url: $HeadURL: http://debesvn001/kostal/lk_ae_internal/LK/Eclipse/ProjectTemplate/trunk/Tools/Make/config/project.mk $

######################################################################
#
# MAKEFILE TEMPLATE AEP2
#
# See /doc for detailed documentation
#
# User configuration file: Project-specific settings to the make
# process.
######################################################################


######################################################################
# Definition of tool paths.
#
# All variables ending in _PATH shall only contain the tool root
# directory and never end in ".../bin" or similar.
#
# You can override these variables by setting environment variables
# with the same name.
######################################################################

# Path to compiler executable
#
# Example:
#   COMPILER_PATH     = "C:/Programme/IAR Systems/EW_v3.10a/m16c"
#   COMPILER_INC_PATH = ${COMPILER_PATH}\inc
COMPILER_PATH ?= "D:/ArmGcc_V10_3/ArmGcc_V10_3/bin"
COMPILER_INC_PATH =

# Path to QA-C installation.
QAC_PATH           ?= C:/Tools/PRQA/QAC-7.2-F

# Path to SlikSVN installation.
SVN_PATH           ?= C:/Tools/SlikSvn

# Path to Tessy installation. 
TESSY_PATH         ?= c:/Tools/Razorcat/TESSY_3.2


######################################################################
# Conditional build settings
######################################################################

# List the available build modes for your project.
#
# If you add a build mode "mymode" here, you must also define these
# variables:
# - CFLAGS_MYMODE (in compile_opt.mk)
# - ASMFLAGS_MYMODE (in assemble_opt.mk)
# - LDFLAGS_MYMODE (in link_opt.mk)
# - TARGET_MYMODE (below)
#
# Default value:
#  BUILDMODES=release debug
#
BUILDMODES=release debug

# Name of the target file specific to each build mode.
#
# Please specify target for each build mode.
# Example:
#   TARGET_DEBUG=debug.out
#   TARGET_RELEASE=release.hex
#   
TARGET_RELEASE=${BinDir}/target_${BUILDMODE}.elf
TARGET_DEBUG=${BinDir}/output_${BUILDMODE}.elf


######################################################################
# Path settings
#
# The working directory for the make process is Tools/Make. BaseDir is
# defined relative to point to the project root.
######################################################################

# Location of the source files.
#
# Default value:
#   SourceDir = ${BaseDir}/Source
SourceDir = ${BaseDir}/Source

# Location of all result files.
#
# Default value:
#   TargetDir = ${BaseDir}/Target
TargetDir = ${BaseDir}/Target

# File extension of assembler files
#
# Usually needs to be updated when using a IAR toolchain.
#
# Default value:
#   ASM_SRC_EXT = .s
ASM_SRC_EXT = .s


######################################################################
# Definition of control macros                                 
######################################################################

# Source list generation
#
# AUTO_SRC_LIST = ON turns on automatic source list retrieving,
# filtering and deletion functionality. Any other value turns it off.
AUTO_SRC_LIST = ON

# Dependency calculation
#
# DEP_CHECK_GNU = ON: turns on GNU compiler dependency retrieval as
# 2nd step of target compiler invocation. Any other value turns it
# off.
DEP_CHECK_GNU = ON


######################################################################
# Project specific build targets
#
# Example: Definition of targets sequencing basic targets      
######################################################################

.PHONY: all_rebuild
all_rebuild: checktools_BASIC checktools_COMPILER
	$(MAKE) clean
	$(MAKE) cleanlists
	$(MAKE) preparelists
	$(MAKE) all

.PHONY: all_integration
all_integration: checktools_SVNVERSION
	@echo "Rebuild integration for build mode '${BUILDMODE}'."
	$(MAKE) all_rebuild
        # add some special tasks for integration/release build purpose
        # e.g copying results to special locations for svn handling
        # or merging of hexfiles, starting build for main + sub + fbl etc.
	$(MAKE) print_info


######################################################################
# Project specific extension points
#
# Example: Creating addtional .hex/.elf files, modify dependency
# files, etc.
######################################################################

# Compiler call
pre_compile_extension =
post_compile_extension =

# Assembler call
pre_assemble_extension =
post_assemble_extension =

# Linker call
pre_link_extension =
post_link_extension =
