# SVN-Id: $Id: testing.mk 52032 2017-01-17 13:19:54Z ostwal01 $
# SVN-Url: $HeadURL: http://debesvn001/kostal/lk_ae_internal/LK/Eclipse/ProjectTemplate/trunk/Tools/Make/tests/testing.mk $

######################################################################
#
# MAKEFILE TEMPLATE AEP2
#
# See /doc for detailed documentation
#
# Make file containing targets for internal make process testing.
#
# The targets in this file are intended to be used for quality
# assurance tasks for the make process itself and shall not be
# executed in normal development projects.
#
######################################################################

# Archive containing the test code.
TESTCODE_PKG=tests/make_process_testcode.tar.gz

# Files to include when packaging test code.
TESTCODE_FILES= \
	Source \
	Tools/Make/config/blacklist.mk \
	Tools/Make/config/qac_blacklist.mk \
	Tools/Tessy/tessy.pdbx \
	Tools/Tessy/backup \
	Tools/Tessy/config/default_configuration.xml


# Package source code in the project into the test code archive.
pack_testcode: ${TESTCODE_PKG}

.PHONY: ${TESTCODE_PKG}
${TESTCODE_PKG}:
	@echo "Packing testcode to archive '$@'."
	tar --directory=${BaseDir} \
		-czvf $@ \
		--exclude='.dummy' \
		${TESTCODE_FILES}


# Extract the test code archive into the project
.PHONY: install_testcode
install_testcode: 
	@echo "Extracting test code."
	tar --directory=${BaseDir} \
		-xvzf ${TESTCODE_PKG}


# Run make process to compile the test code.
.PHONY: test_build
test_build: clean install_testcode
	./make.bat release VERBOSE_OFF all_rebuild
	./make.bat debug VERBOSE_ON all_rebuild


# Run make process to execute the qac check of test code.
.PHONY: test_qac
test_qac: qac_clean install_testcode
	$(MAKE) qac_all_rebuild | tee ${TargetDir}/qacmsg.txt

	EXPMSG=7; \
	NUMMSG=$$(cat ${TargetDir}/qacmsg.txt \
		| grep -P '^(.+):(\d+): (\w+): (\d+) ([^\n]+)$$' | wc -l); \
	if [ $${NUMMSG} != $${EXPMSG} ]; \
	then \
		echo "FAILED: Expected $${EXPMSG} QA-C messages, but found $${NUMMSG}."; \
	else \
		echo "OK: Got $${EXPMSG} QA-C messages as expected."; \
	fi


# Check result of svnversion
.PHONY: test_svnversion
test_svnversion:
	if echo ${SVN_WC_REV} | grep -Eq '^[0-9]+'; \
	then \
		echo "OK: Valid working copy revision is ${SVN_WC_REV}."; \
	else \
		echo "FAILED: Strange working copy revision ${SVN_WC_REV}"; \
	fi


# Check if the build process fails for an undefined build mode.
.PHONY: test_buildmode_undef
test_buildmode_undef:
	$(MAKE) BUILDMODE=undef_buildmode MAKE_VERBOSE=VERBOSE_OFF print_info > /dev/null; \
	RET=$$?; \
	if [ $$RET == 0 ]; then \
		echo "FAILED: Make process does not fail for undefined build mode."; \
		exit 1; \
	else \
		echo "OK: Make process failed with exit code $${RET} for undefined build mode."; \
	fi

	$(MAKE) BUILDMODE=release MAKE_VERBOSE=VERBOSE_OFF print_info > /dev/null; \
	RET=$$?; \
	if [ $$RET == 0 ]; then \
		echo "OK: Make process succeeded for defined build mode."; \
	else \
		echo "FAILED: Make process failed with exit code $${RET} for defined build mode."; \
		exit 1; \
	fi


# Run print_info target.
.PHONY: test_print_info
test_print_info:
	${MAKE} print_info


# Run tessy_batch target
.PHONY: test_tessy_batch
test_tessy_batch: install_testcode
	./make.bat release VERBOSE_ON tessy_batch -j1


# Run all tests
test_all: test_build test_qac test_svnversion test_buildmode_undef \
	test_print_info
