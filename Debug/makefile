################################################################################
# Automatically-generated file.  Do not edit directly; use project properties.
################################################################################


ROOT := ..

-include $(ROOT)/makefile.init

RM := rm -rf

-include $(ROOT)/auto-generated.mk
-include sources.mk
-include $(SUBDIRS:%=%/subdir.mk)
-include objects.mk
-include $(com.palmsource.eclipse.palmos4dev.compiler.m68k_palmos_o_DEPS)
-include $(com.palmsource.eclipse.tools.compiler.palmrc_trc_DEPS)
-include $(ROOT)/makefile.defs

all: PalmOS_Authenticator.prc

$(MULTISECTION_ASM_OBJS): multiple_code_sections.s 
	@echo
	m68k-palmos-as  -o $@ multiple_code_sections.s 

PalmOS_Authenticator: $(com.palmsource.eclipse.palmos4dev.compiler.m68k_palmos_o_OBJS) $(MULTISECTION_ASM_OBJS) $(MULTISECTION_OBJS) 
	@echo
	m68k-palmos-gcc -g -o $@ $(com.palmsource.eclipse.palmos4dev.compiler.m68k_palmos_o_OBJS) $(MULTISECTION_ASM_OBJS) $(MULTISECTION_OBJS) 

buildprc_temp.prc: PalmOS_Authenticator 
	@echo
	build-prc $(MULTISECTION_DEFINITIONS_FILE) -c '$(CREATOR_ID)' -n $(ARTIFACT_NAME) -o $@ PalmOS_Authenticator 

.INTERMEDIATE: buildprc_temp.prc

buildprc_temp.prc: $(ROOT)/auto-generated.mk


prcmerge_temp.prc: buildprc_temp.prc 
	@echo
	"$(TOOLS_DIR)PRCMerge" -quiet -omit pref -o $@ buildprc_temp.prc 

.INTERMEDIATE: prcmerge_temp.prc

prcmerge_temp.prc: $(ROOT)/auto-generated.mk


PalmOS_Authenticator.prc: prcmerge_temp.prc $(com.palmsource.eclipse.tools.compiler.palmrc_trc_OBJS) 
	@echo
	"$(TOOLS_DIR)PRCMerge" -quiet -dbVersion $(DATABASE_VERSION) -dbType '$(DB_TYPE)' -dbCreator '$(CREATOR_ID)' -n $(DB_NAME) $(DATABASE_BACKUP) $(DATABASE_HIDDEN) $(DATABASE_RESET) $(DATABASE_PROTECT) $(DATABASE_BUNDLE) -o $@ prcmerge_temp.prc $(com.palmsource.eclipse.tools.compiler.palmrc_trc_OBJS) 

PalmOS_Authenticator.prc: $(ROOT)/auto-generated.mk




clean:
	-$(RM) $(com.palmsource.eclipse.palmos4dev.compiler.m68k_palmos_o_OBJS) $(com.palmsource.eclipse.palmos4dev.compiler.m68k_palmos_o_DEPS) $(MULTISECTION_OBJS) multiple_code_sections.s $(MULTISECTION_ASM_OBJS) PalmOS_Authenticator buildprc_temp.prc prcmerge_temp.prc PalmOS_Authenticator.prc $(com.palmsource.eclipse.tools.compiler.palmrc_trc_OBJS) $(com.palmsource.eclipse.tools.compiler.palmrc_trc_DEPS) 

.PHONY: all clean dependents

-include $(ROOT)/makefile.targets
