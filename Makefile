SRCDIR := src
INCLUDEDIR := include
TESTSDIR := tests
GRAMMARDIR := grammar
DRIVERDIR := driver
BUILDDIR := build
PARSERDIR := parser
PROJECTNAME := tastr
OBJDIR := $(BUILDDIR)/objects
BINDIR := $(BUILDDIR)/bin
LIBDIR := $(BUILDDIR)/lib
HEADERDIR := $(BUILDDIR)/include/tastr
OBJNAME := $(PROJECTNAME)
BINNAME := $(PROJECTNAME)
LIBNAME := lib$(PROJECTNAME)

CXX := clang++
BISON := bison
FLEX := flex
AR := ar
MV := mv
MKDIR := mkdir
DIRNAME := dirname
CD := cd
RM := rm
CPPCHECK := cppcheck
CLANGFORMAT := clang-format
CP := cp
DIFF := diff
TOUCH := touch

RMFLAGS := -rf
MKDIRFLAGS := -p
FLEXFLAGS := -v
BISONFLAGS := -v
ARFLAGS := rcs
CPFLAGS := -R

CXXFLAGS := -O2 -g -ggdb3 -std=c++17
OBJFLAGS := -c -fPIC $(CXXFLAGS)
LIBFLAGS := -shared -Wl,-soname,$(LIBNAME).so
BINFLAGS := $(CXXFLAGS)
BINARGS := -

CPPSRCFILES := $(shell find $(SRCDIR) -name '*.cpp')
CSRCFILES := $(shell find $(SRCDIR) -name '*.c')
CCSRCFILES := $(shell find $(SRCDIR) -name '*.cc')
CXXSRCFILES := $(shell find $(SRCDIR) -name '*.cxx')
SRCFILES :=  $(CPPSRCFILES) $(CSRCFILES) $(CCSRCFILES) $(CXXSRCFILES)

HPPINCLUDEFILES := $(shell find $(INCLUDEDIR) -name '*.hpp')
HINCLUDEFILES := $(shell find $(INCLUDEDIR) -name '*.h')
HHINCLUDEFILES := $(shell find $(INCLUDEDIR) -name '*.hh')
HXXINCLUDEFILES := $(shell find $(INCLUDEDIR) -name '*.hxx')
INCLUDEFILES := $(HPPINCLUDEFILES) $(HINCLUDEFILES) $(HHINCLUDEFILES) $(HXXINCLUDEFILES)
HEADERFILES := $(patsubst $(INCLUDEDIR)/%,$(HEADERDIR)/%,$(INCLUDEFILES))

DRIVERFILES := $(shell find $(DRIVERDIR) -name '*.cpp') $(shell find $(DRIVERDIR) -name '*.c') $(shell find $(DRIVERDIR) -name '*.cc')
OBJECTFILES := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(addsuffix .o,$(SRCFILES)))

PASSTYPEDECLFILES := $(shell find $(TESTSDIR)/pass -maxdepth 1 -name '*.typedecl')
FAILTYPEDECLFILES := $(shell find $(TESTSDIR)/fail -maxdepth 1 -name '*.typedecl')
PASSTYPEDECLFILESOUTPUT := $(patsubst $(TESTSDIR)/pass/%,$(TESTSDIR)/pass/output/%,$(PASSTYPEDECLFILES))
FAILTYPEDECLFILESOUTPUT := $(patsubst $(TESTSDIR)/fail/%,$(TESTSDIR)/fail/output/%,$(FAILTYPEDECLFILES))

PARSER_SENTINEL := .parser.sentinel
LEXER_SENTINEL := .lexer.sentinel
HEADER_SENTINEL := .header.sentinel


################################################################################
# ALL
################################################################################

.PHONY: all
all: build
	@:

.PHONY: clean
clean: clean-build clean-test
	@:


################################################################################
# BUILD
################################################################################

.PHONY: build
build: parser lexer header library application
	@:

.PHONY: clean-build
clean-build:
	$(RM) $(RMFLAGS) $(BUILDDIR)
	$(RM) $(RMFLAGS) $(PARSER_SENTINEL) $(LEXER_SENTINEL) $(HEADER_SENTINEL)


################################################################################
# PARSER
################################################################################

.PHONY: parser
parser: $(SRCDIR)/$(PARSERDIR)/Parser.cxx $(INCLUDEDIR)/$(PARSERDIR)/Parser.hxx
	@:

$(SRCDIR)/$(PARSERDIR)/Parser.cxx $(INCLUDEDIR)/$(PARSERDIR)/Parser.hxx: $(PARSER_SENTINEL)
	@:

$(PARSER_SENTINEL): $(GRAMMARDIR)/Parser.yxx
	$(CD) $(GRAMMARDIR) && $(BISON) $(BISONFLAGS) --xml --graph=Parser.gv Parser.yxx
	@$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)/$(PARSERDIR)
	@$(MKDIR) $(MKDIRFLAGS) $(INCLUDEDIR)/$(PARSERDIR)
	$(MV) $(GRAMMARDIR)/Parser.cxx $(SRCDIR)/$(PARSERDIR)/Parser.cxx
	$(MV) $(GRAMMARDIR)/Parser.hxx $(INCLUDEDIR)/$(PARSERDIR)/Parser.hxx
	@$(TOUCH) $(PARSER_SENTINEL)


################################################################################
# LEXER
################################################################################

.PHONY: lexer
lexer: $(INCLUDEDIR)/$(PARSERDIR)/Lexer.hxx $(SRCDIR)/$(PARSERDIR)/Lexer.cxx
	@:

$(INCLUDEDIR)/$(PARSERDIR)/Lexer.hxx $(SRCDIR)/$(PARSERDIR)/Lexer.cxx: $(LEXER_SENTINEL)
	@:

$(LEXER_SENTINEL): $(GRAMMARDIR)/Lexer.lxx
	$(CD) $(GRAMMARDIR) && $(FLEX) $(FLEXFLAGS) Lexer.lxx
	@$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)/$(PARSERDIR)
	@$(MKDIR) $(MKDIRFLAGS) $(INCLUDEDIR)/$(PARSERDIR)
	$(MV) $(GRAMMARDIR)/Lexer.cxx $(SRCDIR)/$(PARSERDIR)/Lexer.cxx
	$(MV) $(GRAMMARDIR)/Lexer.hxx $(INCLUDEDIR)/$(PARSERDIR)/Lexer.hxx
	@$(TOUCH) $(LEXER_SENTINEL)


################################################################################
# HEADER
################################################################################

.PHONY: header
header: $(HEADERFILES)
	@:

$(HEADERFILES): $(HEADER_SENTINEL)
	@:

$(HEADER_SENTINEL): $(INCLUDEFILES)
	@$(MKDIR) $(MKDIRFLAGS) $(HEADERDIR)
	$(CP) $(CPFLAGS) $(INCLUDEDIR)/* $(HEADERDIR)
	@$(TOUCH) $(HEADER_SENTINEL)


################################################################################
# LIBRARY
################################################################################

.PHONY: library
library: static-library shared-library
	@:

.PHONY: static-library
static-library: $(LIBDIR)/$(LIBNAME).a
	@:

.PHONY: shared-library
shared-library: $(LIBDIR)/$(LIBNAME).so
	@:

$(LIBDIR)/$(LIBNAME).a: $(OBJECTFILES)
	@$(MKDIR) $(MKDIRFLAGS) $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

$(LIBDIR)/$(LIBNAME).so: $(OBJECTFILES)
	@$(MKDIR) $(MKDIRFLAGS) $(LIBDIR)
	$(CXX) $(LIBFLAGS) -o $@ $^

$(OBJDIR)/$(PARSERDIR)/%.o: $(SRCDIR)/$(PARSERDIR)/% $(INCLUDEFILES)
	@$(MKDIR) $(MKDIRFLAGS) `$(DIRNAME) $@`
	$(CXX) $(OBJFLAGS) -I$(INCLUDEDIR) -I$(INCLUDEDIR)/$(PARSERDIR) -o$@ $<

$(OBJDIR)/%.o: $(SRCDIR)/% $(INCLUDEFILES)
	@$(MKDIR) $(MKDIRFLAGS) `$(DIRNAME) $@`
	$(CXX) $(OBJFLAGS) -I$(INCLUDEDIR) -o$@ $<


################################################################################
# APPLICATION
################################################################################

.PHONY: application
application: $(BINDIR)/$(BINNAME)
	@:

$(BINDIR)/$(BINNAME): $(DRIVERFILES) $(LIBDIR)/$(LIBNAME).a
	@$(MKDIR) $(MKDIRFLAGS) $(BINDIR)
	$(CXX) $(BINFLAGS) -I$(INCLUDEDIR) -o$@ $^


################################################################################
# TESTS
################################################################################

.PHONY: test
test: test-pass test-fail
	@:

.PHONY: test-pass
test-pass: $(TESTSDIR)/pass/output $(PASSTYPEDECLFILESOUTPUT)
	@:

.PHONY: test-fail
test-fail: $(TESTSDIR)/fail/output $(FAILTYPEDECLFILESOUTPUT)
	@:

$(TESTSDIR)/pass/output:
	@$(MKDIR) $(MKDIRFLAGS) $@

$(TESTSDIR)/fail/output:
	@$(MKDIR) $(MKDIRFLAGS) $@

$(TESTSDIR)/pass/output/%.typedecl: $(TESTSDIR)/pass/%.typedecl $(BINDIR)/$(BINNAME)
	@echo "Testing" $<;
	@if $(BINDIR)/$(BINNAME) $< > $@ 2>&1; \
	then $(DIFF) $< $@;                    \
	else cat $@ && exit 1;                 \
	fi

$(TESTSDIR)/fail/output/%.typedecl: $(TESTSDIR)/fail/%.typedecl $(BINDIR)/$(BINNAME)
	@echo "Testing" $<;
	@if $(BINDIR)/$(BINNAME) $< > $@ 2>&1; \
	then cat $@ && exit 1;                 \
	fi

.PHONY: clean-test
clean-test:
	$(RM) $(RMFLAGS) $(TESTSDIR)/pass/output
	$(RM) $(RMFLAGS) $(TESTSDIR)/fail/output


################################################################################
# RUN
################################################################################

.PHONY: run
run: application
	@echo "Write a type declaration. Quit with Ctrl-d."
	./$(BINDIR)/$(BINNAME) $(BINARGS)


################################################################################
# MISCELLANEOUS
################################################################################

.PHONY: cppcheck
cppcheck:
	$(CPPCHECK) --quiet                         \
	            --project=compile_commands.json \
	            --enable=all                    \
	            -I$(INCLUDEDIR)                 \
	            -i$(SRCDIR)/$(PARSERDIR)        \
	            -i$(INCLUDEDIR)/$(PARSERDIR)    \
	            src                             \
	            include

.PHONY: clang-format
clang-format:
	$(CLANGFORMAT) -i $(CPPSRCFILES) $(CSRCFILES) $(HPPINCLUDEFILES) $(HINCLUDEFILES) $(DRIVERFILES)
