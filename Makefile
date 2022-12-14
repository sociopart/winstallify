# GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug_x86_64
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug_x86_64)
  winstallify_cli_config = debug_x86_64
endif
ifeq ($(config),debug_x86)
  winstallify_cli_config = debug_x86
endif
ifeq ($(config),release_x86_64)
  winstallify_cli_config = release_x86_64
endif
ifeq ($(config),release_x86)
  winstallify_cli_config = release_x86
endif

PROJECTS := winstallify-cli

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

winstallify-cli:
ifneq (,$(winstallify_cli_config))
	@echo "==== Building winstallify-cli ($(winstallify_cli_config)) ===="
	@${MAKE} --no-print-directory -C source -f Makefile config=$(winstallify_cli_config)
endif

clean:
	@${MAKE} --no-print-directory -C source -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug_x86_64"
	@echo "  debug_x86"
	@echo "  release_x86_64"
	@echo "  release_x86"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   winstallify-cli"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"