########################################################################################
#                                                                                      #
#  MAKEFILE TEMPLATE AEP2.1                                                            #
#  Extension makefile for Tessy Unit Testing                                           #
#                                                                                      #
#  Contained general settings are intended to be kept                                  #
#  clean from any project specific modifications. Thus,                                #
#  it shouldn't be changed by the user.                                                #
#                                                                                      #
########################################################################################

########################################################################################
# USER settings 			                                                           #
########################################################################################

#projectname will be in the reports
TessyProjectName       =Tessy_project
# testcollection name will be in the reports
#CAUTION: no spaces after this Name
TessyCollectionName    =${BUILDDERIVAT}

#use the variant variable in this path (no absulute path),
#will be used for normal import and SVN Check
restorepath = ../Tessy/backup/${BUILDDERIVAT}

requirementspath = ../Tessy/backup/${BUILDDERIVAT}/requirements

#path of stubfolder
#all header with same name are delted from generated Header_Files folder
#CAUTION: folder and subfolder have to be included seperat in tessy_opt.mk for configuration file
stubpath = ../Tessy/Stubs

#define your own test, use tessy_clean_up_usr_tbs to clean up testobjects to template
#CAUTION: Jenkins need a test execution and overview report (one or more)
#TessyUsrTbs = $(TessyPrj)/batch_test_usr.tbs

##############      OPTIONS                  ###########################################

# copy_header == ON --> automatic copy of all header in header_filtered into a folder for Tessy Include
#						whenever tessy_sync is executed
TESSY_COPY_HEADER=ON

# test_one_by_one == ON --> automatic test and create Overview Report for each module
#							not one for all
TEST_ONE_BY_ONE =ON

# import_requirements == ON --> automatic import all requirements from requirementspath
#
IMPORT_REQUIREMENTS = ON

##############      ADVANCED OPTIONS         ###########################################

# svn_check_import == ON --> automatic check svn for changes since the last import and
#							 only import the added and changed .tmb-files (may be not work properly)
SVN_CHECK_IMPORT=ON

# HTTP-Timeout for time consuming actions
# in sec => 3600 = 1h
# 			86400 = 1d
TESSY_CMD_TIMEOUT=86400

# auto disconnect == ON --> automatic disconnect in advance of any connect
TESSY_AUTO_DISCONNECT=ON

# auto sync == ON --> Tessy environment config is synchronized whenever preparelists are
#                     updated (not useful in combination with header_copy on)
TESSY_AUTO_SYNC=OFF

# test_all == ON --> automatic test all modules
#					 there is no programm to do not all test
TEST_ALL =ON

########################################################################################
# Basic settings and macros: VARIABLEDEFINITION                                        #
########################################################################################

TessyEnv 			   = "GNU GCC Eclipse CDT (Default)"
TessyProjectPath       = $(BaseDirAbs)/Tools/Tessy
TessyConfigFile        = $(BaseDirAbs)/Tools/Tessy/config/default_configuration.xml

SED_FILTER_DRIVE       = s/\\/\\\([a-zA-Z]\\\)\\//\\\1:\\//
ConvertDrive           = $(shell echo $(1) | $(SEDBIN) -e $(SED_FILTER_DRIVE) )
#BaseDirAbs             = $(call ConvertDrive, $(abspath $(BaseDir)))
BaseDirAbs             = $(realpath $(BaseDir))

COMMA                  = ,
# produce a 'SPACE' literal
SPACE                  =
SPACE                  +=
# define a macro to insert separator in space separated string list
insert-separator       = $(subst $(SPACE),$1,$(strip $2))

# define restorelist variable
# to restore not all: set here each module path seperatet by \ and newline after it e.g.:
#restorelist = ../../Tests/Example.tmb\
#			   ../../Tests/Example2.tmb
restorelist 			= $(wildcard $(restorepath)/*.tmb)

requirementslist		= $(wildcard $(requirementspath)/*.xml)

stublist 				= $(shell ls $(stubpath) | egrep -o "[A-z,0-9,_,\-]*\.h")

# define revision-numbers
ifneq ($(wildcard ${TessyPrj}/lists/OldRevisionNumber.txt),)
oldrevnum 			= $(shell cat $(TessyPrj)/lists/OldRevisionNumber.txt)
else
oldrevnum 			=
endif

ifneq ($(wildcard ${TessyPrj}/lists/NewRevisionNumber.txt),)
newrevnum 			= $(shell cat $(TessyPrj)/lists/NewRevisionNumber.txt)
else
newrevnum 			=
endif

# Derive list of comma separated include paths to be transfered to Tessy configuration
TessyIncludes          = $(abspath $(IncludePaths))

# set user path
TessyIncludesRoot     = $(subst \\,\/, $(TESSY_USER_INC_PATH))

ifeq ($(TESSY_COPY_HEADER),ON)
	TessyIncludesRoot      += $$(PROJECTROOT)/Tools/Tessy/Header_Files
else
# replace absolute paths where feasible with Tessy project root var
	TessyIncludesRoot      += $(strip $(subst $(BaseDirAbs),$$(PROJECTROOT),$(TessyIncludes)))
endif
TessyIncludesRootSep   = $(subst /,\/, $(call insert-separator,$(COMMA),$(TessyIncludesRoot)))

# Derive list of comma separated preprocessor definitions to be transfered to Tessy configuration
CC_DEFINES_TESSY       = $(strip $(call insert-separator,$(COMMA),$(CC_DEFLIST_TESSY)))

#checking if a GUI_IS_ON.txt file is existing
#(global variable) [is set in tessy_batch and deleted in tessy_batch2]
ifneq ($(wildcard ${TessyPrj}/lists/GUI_IS_ON.txt),)
TESSY_GUI_ON 			= ON
else
TESSY_GUI_ON 			= OFF
endif

ifeq ($(CI_SERVER),ON)
#international LINK
BuildLinkWithSpace=http://debejenk002.de.kostal.int/
#add the ending of the national Link
BuildLinkWithSpace +=$(shell echo ${BUILD_URL} | egrep -o "job.*")
BuildLinkWithSpace +=artifact/
#delete Spaces
BuildLink = $(subst $(SPACE),,$(BuildLinkWithSpace))
#escape the slashes for the SED command
BuildLinkSED = $(subst /,\/,$(BuildLink))
JobName = ${JOB_NAME}
JobNameSED = $(subst /,\/,$(JobName))
endif

########################################################################################
# special target to publish Tessy project name, need by CI to open Tessy targeting the #
# right project.                                                                       #
########################################################################################

.PHONY: tessy_prepare_ci
tessy_prepare_ci:
	echo "-p $(TessyProjectName)" > ${SrcListDir_Tessy}/TessyProjectName.txt

########################################################################################
# target expressing dependency of environment configuration to headerlist and          #
# tessy compiler options                                                               #
########################################################################################

$(TessyConfigFile): ${SrcListDir}/headerlist.mk tessy_opt.mk
ifeq ($(TESSY_AUTO_SYNC),ON)
	$(MAKE) tessy_sync
endif

########################################################################################
# target to copy all relevant Header into one folder                                   #
########################################################################################
header_copy:
	@echo Creating new folder: Header_Files
	if [ -d ../Tessy/Header_Files]; \
	then \
		rm -rf ../Tessy/Header_Files; \
	fi; \
	mkdir -p ../Tessy/Header_Files
	@echo Copy all headers from  header_filtered list
	$(foreach file,$(header_filtered), cp $(file) ../Tessy/Header_Files;)
	@echo Removing the files named like stub files
	$(foreach file,$(stublist), rm ../Tessy/Header_Files/$(file);)

########################################################################################
# target transferring of project include-paths and preprocessor defines                #
# to Tessy Environment configuration file                                              #
########################################################################################

tessy_sync: checktools_BASIC
ifeq ($(TESSY_COPY_HEADER),ON)
	@echo copy on
	$(MAKE) header_copy
endif
	@echo Forwarding compiler defines to Tessy environment configuration
	$(SEDBIN) -e 's/<property type="String"*.*/<property type="String" name="Compiler Defines" value="$(CC_DEFINES_TESSY)" flags="0x90040049"\/>/' \
	                  $(TessyPrj)/config/default_configuration.xml > tessy_env_temp.xml
	mv -f tessy_env_temp.xml $(TessyPrj)/config/default_configuration.xml

	@echo Forwarding include paths to Tessy environment configuration
	$(SEDBIN) -e 's/<property type="Directory"*.*/<property type="Directory" name="Compiler Includes" value="$(TessyIncludesRootSep)" flags="0x90040049"\/>/' \
	                  -e 's/\//\\/g' -e 's/<\\/<\//g' -e 's/\\>/\/>/g' $(TessyPrj)/config/default_configuration.xml > tessy_env_temp.xml
	mv -f tessy_env_temp.xml $(TessyPrj)/config/default_configuration.xml

	@echo Setting project name in tessy.pdbx
	$(SEDBIN) -e 's/name=*.*/name="$(TessyProjectName)"/' \
	                  $(TessyPrj)/tessy.pdbx > $(TessyPrj)/tessy_tmp.pdbx
	 mv -f $(TessyPrj)/tessy_tmp.pdbx $(TessyPrj)/tessy.pdbx
	@echo Setting configuration in tessy.pdbx
	$(SEDBIN) -e 's/configuration=*.*/configuration="$$(PROJECTROOT)\\Tools\\Tessy\\config\\default_configuration.xml"/' \
	                  $(TessyPrj)/tessy.pdbx > $(TessyPrj)/tessy_tmp.pdbx
	 mv -f $(TessyPrj)/tessy_tmp.pdbx $(TessyPrj)/tessy.pdbx

########################################################################################
# central sequence handling Tessy batch processing         						       #
########################################################################################

.PHONY: tessy_batch
tessy_batch: checktools_BASIC checktools_TESSY
	@echo Starting Tessy batchtest sequence

	mkdir -p ../Tessy/lists

	rm -f $(TessyPrj)/lists/GUI_IS_ON.*

	@echo Starting Tessy instance headless
	${TESSYD_BIN} --dont-breakaway-from-job -t 180 --file $(TessyPrj)/tessy.pdbx;\
	RET=$$?;\
	if [ $$RET -ne "0" ]; \
	then echo .; echo "GUI is maybe running ?!"; \
	echo ON >> ${TessyPrj}/lists/GUI_IS_ON.txt; \
	fi

ifneq ($(TESSY_AUTO_DISCONNECT),)
	$(TESSY_BIN) disconnect
endif

	@echo connecting Tessy instance
	$(TESSY_BIN) connect;\
	RET=$$?;\
	if [ $$RET -ne "0" ];\
	then echo .; echo "tessycmd.exe return code $$RET indicates tool problem.";\
	exit $$RET;\
	fi

	@echo selecting project $(TessyProjectName)
	$(TESSY_BIN) select-project $(TessyProjectName);\
	RET=$$?;\
	if [ $$RET -ne "0" ];\
	then echo .; echo "tessycmd.exe return code $$RET indicates tool problem.";\
	exit $$RET;\
	fi

	@echo select Testcollection
	$(TESSY_BIN) new-test-collection $(TessyCollectionName);\
	RET=$$?;\
	if [ $$RET -ne "0" ];\
	then $(TESSY_BIN) select-test-collection $(TessyCollectionName); RET=$$?;\
	exit $$RET;\
	fi
ifeq ($(IMPORT_REQUIREMENTS),ON)
	$(foreach reqfile,$(requirementslist),\
		$(TESSY_BIN) -t $(TESSY_CMD_TIMEOUT) import-requirement-document -file $(realpath $(reqfile)) -commit;\
	)
endif


ifeq ($(SVN_CHECK_IMPORT),ON)
	@echo SVN_CHECK_IMPORT
	$(MAKE) svn_check_import
else
	@echo importing Modules
	$(foreach restorefile,$(restorelist),\
		$(TESSY_BIN) -t $(TESSY_CMD_TIMEOUT) restore-module -test-collection $(realpath $(restorefile));\
		RET=$$?;if [ $$RET -eq "0" ];then echo success $(restorefile);else echo error $(restorefile);fi;\
	)
endif


#	clean modulelist file
	rm -f $(TessyPrj)/lists/TESSY_modulelist.*

#	prepare modulelist file
	$(TESSY_BIN) list-modules -test-collection >> $(TessyPrj)/lists/TESSY_modulelist.txt
#	execute next (new) target to refresh moudulelist variable
	$(MAKE) tessy_batch2

tessy_batch2:
#	refresh modulelist
	$(eval modulelist = $(shell cat $(TessyPrj)/lists/TESSY_modulelist.txt))

ifeq ($(SVN_CHECK_IMPORT),ON)
#check if any module changed
ifneq ($(wildcard ${TessyPrj}/lists/svn_changed_module.txt),)
	$(eval svn_modulelist = $(shell cat $(TessyPrj)/lists/svn_changed_module.txt))

	@echo selecting envrivorment for modules from svn list
	$(foreach module,$(svn_modulelist),\
				$(TESSY_BIN) select-module -test-collection $(module); \
				$(TESSY_BIN) -t $(TESSY_CMD_TIMEOUT) set-environment "GNU GCC Eclipse CDT (Default)";\
				RET=$$?;if [ $$RET -eq "0" ];then echo success $(module);else echo error $(module);fi;\
	)
else
#if no change tmb list is there select environment for all from modulelist
ifeq ($(wildcard ${TessyPrj}/lists/svn_changed_tmb.txt),)
	@echo selecting envrivorment
	$(foreach module,$(modulelist), \
				$(TESSY_BIN) select-module -test-collection $(module); \
				$(TESSY_BIN) -t $(TESSY_CMD_TIMEOUT) set-environment "GNU GCC Eclipse CDT (Default)";\
				RET=$$?;if [ $$RET -eq "0" ];then echo success $(module);else echo error $(module);fi;\
	)
endif
endif
else
	@echo selecting envrivorment
	$(foreach module,$(modulelist), \
				$(TESSY_BIN) select-module -test-collection $(module); \
				$(TESSY_BIN) -t $(TESSY_CMD_TIMEOUT) set-environment "GNU GCC Eclipse CDT (Default)";\
				RET=$$?;if [ $$RET -eq "0" ];then echo success $(module);else echo error $(module);fi;\
	)
endif



ifeq ($(TEST_ONE_BY_ONE),ON)
	@echo running batchtest with generate test_batch.tbs
	$(MAKE) tessy_test_one_by_one
else
#	tessy sync generates a batch_test.tbs-file with rigth testcollection name
	$(MAKE) tessy_sync_tbs

	$(TESSY_BIN) -t $(TESSY_CMD_TIMEOUT) exec-test ${TessyProjectPath}/batch_test.tbs;
endif
	$(SEDBIN) -e 's/<testcollection name=*.*/<testcollection name="$(TessyCollectionName)"\/>/' \
	                  $(TessyPrj)/batch_test_HTML_report.tbs > $(TessyPrj)/batch_test.tbs
	$(TESSY_BIN) -t $(TESSY_CMD_TIMEOUT) exec-test ${TessyProjectPath}/batch_test.tbs;

ifeq ($(CI_SERVER),ON)
#searching for absolute path in html report and replace it with an internet link
	$(SEDBIN) -e 's/file.*$(JobNameSED)/$(BuildLinkSED)/g' \
					  $(TessyPrj)/report/TESSY_OverviewReport.html > TESSY_OverviewReport_temp.html
	mv -f TESSY_OverviewReport_temp.html $(TessyPrj)/report/TESSY_OverviewReport.html
endif

ifneq ($(TESSY_GUI_ON),ON)
	@echo shutting down Tessy instance
	${TESSYD_BIN} shutdown;\
	RET=$$?;\
	if [ $$RET -ne "0" ];\
	then echo .; echo "tessyd.exe return code $$RET indicates tool problem.";\
	exit $$RET;\
	fi
else
	rm -f ${TessyPrj}/lists/GUI_IS_ON.*
endif

tessy_sync_tbs:
	$(eval modulelist = $(shell cat $(TessyPrj)/lists/TESSY_modulelist.txt))
	@echo tbs sync
ifeq ($(TEST_ALL),ON)
#set testcollection name
	$(SEDBIN) -e 's/<testcollection name=*.*/<testcollection name="$(TessyCollectionName)"\/>/' \
	                  $(TessyPrj)/batch_test_tpl.tbs > $(TessyPrj)/batch_test.tbs
else
#set testcollection name
	$(SEDBIN) -e 's/<testcollection name=*.*/<testcollection name="$(TessyCollectionName)">/' \
	                  $(TessyPrj)/batch_test_tpl.tbs > $(TessyPrj)/batch_test.tbs
#set testcollection ending
	$(SEDBIN) -e '/<testcollection name=*.*/a \	\	</testcollection>' \
					  $(TessyPrj)/batch_test.tbs > batch_test_temp.tbs;
	mv -f batch_test_temp.tbs $(TessyPrj)/batch_test.tbs
#set elements to test to the modules from the modulelist
	$(foreach module,$(modulelist),\
		$(SEDBIN) -e '/<\/testcollection>/i \	\	\	<module name="$(module)"/>' $(TessyPrj)/batch_test.tbs > batch_test_temp.tbs; \
		mv -f batch_test_temp.tbs $(TessyPrj)/batch_test.tbs;\
	)
endif

tessy_test_one_by_one:
	$(eval modulelist = $(shell cat $(TessyPrj)/lists/TESSY_modulelist.txt))
#set testcollection name
	$(SEDBIN) -e 's/<testcollection name=*.*/<testcollection name="$(TessyCollectionName)">/' \
	                  $(TessyPrj)/batch_test_tpl.tbs > $(TessyPrj)/batch_test.tbs
	$(SEDBIN) -e '/<testcollection name=*.*/a \	\	</testcollection>' \
					  $(TessyPrj)/batch_test.tbs > batch_test_temp.tbs;
	mv -f batch_test_temp.tbs $(TessyPrj)/batch_test.tbs

#generate one template module element
	$(SEDBIN) -e '/<\/testcollection>/i \	\	\	<module name="template"/>'\
					   $(TessyPrj)/batch_test.tbs > batch_test_temp.tbs
	mv -f batch_test_temp.tbs $(TessyPrj)/batch_test.tbs
#go over all elements from module list and replace modulename (and report name) for each element
	$(foreach module,$(modulelist),\
			$(SEDBIN) -e 's/<module name=*.*/<module name="$(module)"\/>/' \
					$(TessyPrj)/batch_test.tbs > batch_test_temp.tbs; \
			mv -f batch_test_temp.tbs $(TessyPrj)/batch_test.tbs; \
			$(SEDBIN) -e 's/<option key="reportFileNamePattern" value="TESSY_OverviewReport_*.*/<option key="reportFileNamePattern" value="TESSY_OverviewReport_$(module)"\/>/' \
					$(TessyPrj)/batch_test.tbs > batch_test_temp.tbs; \
			mv -f batch_test_temp.tbs $(TessyPrj)/batch_test.tbs; \
			$(SEDBIN) -e 's/<option key="reportFileNamePattern" value="TESSY_RequirementExecutionCoverageReport_*.*/<option key="reportFileNamePattern" value="TESSY_RequirementExecutionCoverageReport_$(module)"\/>/' \
					$(TessyPrj)/batch_test.tbs > batch_test_temp.tbs; \
			mv -f batch_test_temp.tbs $(TessyPrj)/batch_test.tbs; \
			$(SEDBIN) -e 's/<requirement name="InternalSpecification_*.*/<requirement name="InternalSpecification_$(module)"\/>/' \
					$(TessyPrj)/batch_test.tbs > batch_test_temp.tbs; \
			mv -f batch_test_temp.tbs $(TessyPrj)/batch_test.tbs; \
			$(TESSY_BIN) -t $(TESSY_CMD_TIMEOUT) exec-test ${TessyProjectPath}/batch_test.tbs;\
			RET=$$?;if [ $$RET -eq "0" ];then echo success testing $(module);else echo error $(module);fi;\
			$(MAKE) tessy_shutdown;\
			$(MAKE) tessy_start;\
	)

svn_check_import:

#checking if a Old-Revision Number is there
ifeq ($(oldrevnum),)
	@echo no old revision number, importing all from restore path

	@echo importing Modules
	$(foreach restorefile,$(restorelist),\
			$(TESSY_BIN) -t $(TESSY_CMD_TIMEOUT) restore-module -test-collection $(realpath $(restorefile));\
			RET=$$?;if [ $$RET -eq "0" ];then echo success $(restorefile);else echo error $(restorefile);fi;\
	)
#put HEAD-Revision number in file OldRevisionNumber.txt
	$(SVN_BIN) info -r HEAD | grep Revision | egrep -o "[0-9]+" >> $(TessyPrj)/lists/OldRevisionNumber.txt

else
#	clean file
	rm -f $(TessyPrj)/lists/NewRevisionNumber.*
#put HEAD revision number in file NewRevisionNumber.txt
	$(SVN_BIN) info -r HEAD | grep Revision | egrep -o "[0-9]+" >> $(TessyPrj)/lists/NewRevisionNumber.txt
#run a new target to refresh variables
	$(MAKE) svn_check_import2
endif

svn_check_import2:
	@echo
	$(eval newrevnum = $(shell cat $(TessyPrj)/lists/NewRevisionNumber.txt))
#check if the HEAD Revision == last (imported) revision
ifeq ($(oldrevnum),$(newrevnum))
	@echo nothing to import
# clean files
	rm -f $(TessyPrj)/lists/svn_changed_module.*
	echo >> $(TessyPrj)/lists/svn_changed_tmb.txt

else
	@echo checking changes from old revision:$(oldrevnum) to new revision:$(newrevnum)
# clean files
	rm -f $(TessyPrj)/lists/svn_changed_tmb.*
	rm -f $(TessyPrj)/lists/svn_changed_module.*
	@echo write svn_change_tmb.txt
# write changes for all .tmb in restorepath into a file (CAUTION DO NOT CHECK FOR DELETED)
	$(SVN_BIN) diff -r $(oldrevnum):$(newrevnum) $(restorepath) --summarize | egrep -o "[\.\./]+.*\.tmb" >> $(TessyPrj)/lists/svn_changed_tmb.txt;RET=$$?;if [ $$RET -ne "0" ];then echo no changes;fi
# execute new target to refresh variables
	$(MAKE) svn_check_import3
	@echo
endif
	@echo set old revision number to new revision number \(Revision:$(newrevnum)\)
	 mv $(TessyPrj)/lists/NewRevisionNumber.txt $(TessyPrj)/lists/OldRevisionNumber.txt

svn_check_import3:
	@echo
	$(eval restorelistsvn = $(shell cat $(TessyPrj)/lists/svn_changed_tmb.txt))
#ifneq ($(restorelistsvn),)
	@echo importing Modules from svn_change_tmb.txt
	$(foreach restorefile,$(restorelistsvn),\
			$(TESSY_BIN) -t $(TESSY_CMD_TIMEOUT) restore-module -test-collection $(realpath $(restorefile));\
			RET=$$?;if [ $$RET -eq "0" ];then echo success $(restorefile);else echo error $(restorefile);fi;\
	)

	@echo creating svn_changed_module.txt
	$(shell cat $(TessyPrj)/lists/svn_changed_tmb.txt | egrep -o "\.[A-z,0-9,\(,\)]+\.tmb" | egrep -o "\.[A-z,0-9,\(,\)]+\." | egrep -o "[A-z,0-9,\(,\)]+" | sort | uniq  >> $(TessyPrj)/lists/svn_changed_module.txt)
#endif

tessy_clean_up_usr_tbs:
	@echo take user tbs and process it to batch_test_tpl.tbs
#delete modules from elements
	$(SEDBIN) -e '/<module name=*.*>/c\'\
					   $(TessyUsrTbs) > batch_test_tpl_temp.tbs
	mv -f batch_test_tpl_temp.tbs $(TessyPrj)/batch_test_tpl.tbs
#delete folder from elements
	$(SEDBIN) -e '/<folder name=*.*>/c\'\
					   $(TessyPrj)/batch_test_tpl.tbs > batch_test_tpl_temp.tbs
	mv -f batch_test_tpl_temp.tbs $(TessyPrj)/batch_test_tpl.tbs

	$(SEDBIN) -e '/<\/folder>/c\'\
					   $(TessyPrj)/batch_test_tpl.tbs > batch_test_tpl_temp.tbs
	mv -f batch_test_tpl_temp.tbs $(TessyPrj)/batch_test_tpl.tbs
#delete testcollection from elements
	$(SEDBIN) -e '/<testcollection name=*.*>/c\'\
					   $(TessyPrj)/batch_test_tpl.tbs > batch_test_tpl_temp.tbs
	mv -f batch_test_tpl_temp.tbs $(TessyPrj)/batch_test_tpl.tbs

	$(SEDBIN) -e '/<\/testcollection>/c\'\
					   $(TessyPrj)/batch_test_tpl.tbs > batch_test_tpl_temp.tbs
	mv -f batch_test_tpl_temp.tbs $(TessyPrj)/batch_test_tpl.tbs
# add elements beginning if needed
	$(SEDBIN) -e '/<elements\/>/i \	<elements>'\
					   $(TessyPrj)/batch_test_tpl.tbs > batch_test_tpl_temp.tbs
	mv -f batch_test_tpl_temp.tbs $(TessyPrj)/batch_test_tpl.tbs
# change elements ending
	$(SEDBIN) -e 's/<elements\/>/<\/elements>/'\
					   $(TessyPrj)/batch_test_tpl.tbs > batch_test_tpl_temp.tbs
	mv -f batch_test_tpl_temp.tbs $(TessyPrj)/batch_test_tpl.tbs
# add testcollection
	$(SEDBIN) -e '/<\/elements>/i \	\	<testcollection name="TestCollection"/>'\
					   $(TessyPrj)/batch_test_tpl.tbs > batch_test_tpl_temp.tbs
	mv -f batch_test_tpl_temp.tbs $(TessyPrj)/batch_test_tpl.tbs

tessy_start:
	@echo starting Tessy instance headless
	${TESSYD_BIN} --dont-breakaway-from-job -t 180 --file $(TessyPrj)/tessy.pdbx;\
	RET=$$?;\
	if [ $$RET -ne "0" ];\
	then echo bad fucking thing is going on;exit $$RET;\
	fi

ifneq ($(TESSY_AUTO_DISCONNECT),)
	$(TESSY_BIN) disconnect
endif

	@echo connecting Tessy instance
	$(TESSY_BIN) connect;\
	RET=$$?;\
	if [ $$RET -ne "0" ];\
	then echo .; echo "tessycmd.exe return code $$RET indicates tool problem.";\
	exit $$RET;\
	fi

	@echo selecting project $(TessyProjectName)
	$(TESSY_BIN) select-project $(TessyProjectName);\
	RET=$$?;\
	if [ $$RET -ne "0" ];\
	then echo .; echo "tessycmd.exe return code $$RET indicates tool problem.";\
	exit $$RET;\
	fi

	@echo select Testcollection
	$(TESSY_BIN) select-test-collection $(TessyCollectionName);\
	RET=$$?;\
	if [ $$RET -ne "0" ];\
	then exit $$RET;\
	fi

tessy_shutdown:
	@echo shutting down Tessy instance
	${TESSYD_BIN} shutdown;\
	RET=$$?;\
	if [ $$RET -ne "0" ];\
	then echo .; echo "tessyd.exe return code $$RET indicates tool problem.";\
	fi
