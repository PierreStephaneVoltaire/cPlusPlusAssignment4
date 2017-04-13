# GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  Assignment4_config = debug
endif
ifeq ($(config),release)
  Assignment4_config = release
endif

PROJECTS := Assignment4

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

Assignment4:
ifneq (,$(Assignment4_config))
	@echo "==== Building Assignment4 ($(Assignment4_config)) ===="
	@${MAKE} --no-print-directory -C . -f Assignment4.make config=$(Assignment4_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f Assignment4.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Assignment4"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"