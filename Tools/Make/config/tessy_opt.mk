# SVN-Id: $$Id: tessy_opt.mk 52032 2017-01-17 13:19:54Z ostwal01 $$
# SVN-Url: $$HeadURL: http://debesvn001/kostal/lk_ae_internal/LK/Eclipse/ProjectTemplate/trunk/Tools/Make/config/tessy_opt.mk $$

########################################################################################
#                                                                                      # 
#  MAKEFILE TEMPLATE AEP2.1                                                            # 
#  Extension makefile-include for Tessy Unit Testing                                   # 
#                                                                                      # 
#                                                                                      # 
#                                                                                      # 
#                                                                                      # 
#                                                                                      # 
########################################################################################

#This Include-Path is BEFORE all other Include-Path in configuration.xml 

TESSY_USER_INC_PATH = 

#==========================================================
# T E S S Y  D E F I N E S
#
# Note: CC_DEFINES_TESSY may define constants for Tessy
#       analysis & test execution. You may add here 
#       definitions controlling features impacting the
#       test execution. If Tessy tests are carried out
#       based on GNU compiler, you may specify here
#       target compiler intrinsic definitions (see QAC section)  
#==========================================================

CC_DEFLIST_TESSY = $(CC_DEFLIST) 
CC_DEFLIST_TESSY += MY_UNIT_TEST_OPTION

