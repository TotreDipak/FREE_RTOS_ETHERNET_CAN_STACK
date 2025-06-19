# SVN-Id: $$Id: qac_blacklist.mk 52032 2017-01-17 13:19:54Z ostwal01 $$
# SVN-Url: $$HeadURL: http://debesvn001/kostal/lk_ae_internal/LK/Eclipse/ProjectTemplate/trunk/Tools/Make/config/qac_blacklist.mk $$

# blacklist_qac.mk
# 
#  Created on: 26.05.2010
#      Author: breusc01
#
#  Definition of source files / paths to be excluded from qac-check process 
#

# Following sources are excluded from the QA-C check,
# By default, blacklist entries of project build are referenced here.
# Remove the blacklist reference, if entries of build and QAC check
# should be kept separately from each other
#
# Note: Whole paths can be excluded using '%' acts as wildcard character, e.g.
#	../../Source/demo%

blacklist_source_qac= \
	${blacklist} \
#	../../Source/BSW/%  ==> example

# Messages caused by header files of following locations (paths) are excluded
# from QAC message reporting 
#
# blacklist header suppression directly works via path definitions
# (no-wildcard '%' as for blacklist_source_qac entries) 
# Those paths are directly passed to QAC for suppression. 
# Specified paths operate recursively.
# Thus, avoid configuring nested paths. Instead limit the listed entries
# to top level ones (e.g. like an AUTOSAR subtree) and to those
# which are contained in parallel subtrees, e.g. ../../Source/BSW covers
# header suppression for all sub-ordinated paths of ../../BSW. 
# Futhermore, reducing the amount of blacklist header entries improves
# the execution performance.
# By default, include file paths of the compiler location are suppressed.
# This can be adopted to project specific needs.
#
# NOTE: errors or messages of gravity 9 or more cannot be suppressed!  

blacklist_header_qac= \
	${COMPILER_PATH}  \
#	../../Source/BSW  ==> example

	


