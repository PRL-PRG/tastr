SRCDIR := src
INCLUDEDIR := include
TESTDIR := test
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

TYPEFILES := $(shell find $(TESTDIR) -name '*.type')

all: build

build: parser lexer header library application

parser: $(SRCDIR)/$(PARSERDIR)/Parser.cxx $(INCLUDEDIR)/$(PARSERDIR)/Parser.hxx

lexer: $(INCLUDEDIR)/$(PARSERDIR)/Lexer.hxx $(SRCDIR)/$(PARSERDIR)/Lexer.cxx

header: $(HEADERFILES)

library: static-library shared-library

static-library: $(LIBDIR)/$(LIBNAME).a

shared-library: $(LIBDIR)/$(LIBNAME).so

application: $(BINDIR)/$(BINNAME)

clean:
	$(RM) $(RMFLAGS) $(BUILDDIR)

run: application
	@echo "Write a type declaration. Quit with Ctrl-d."
	./$(BINDIR)/$(BINNAME) $(BINARGS)

$(SRCDIR)/$(PARSERDIR)/Parser.cxx: generate-parser

$(INCLUDEDIR)/$(PARSERDIR)/Parser.hxx: generate-parser

generate-parser: $(GRAMMARDIR)/Parser.yxx
	$(CD) $(GRAMMARDIR) && $(BISON) $(BISONFLAGS) --xml --graph=Parser.gv Parser.yxx
	$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)/$(PARSERDIR)
	$(MKDIR) $(MKDIRFLAGS) $(INCLUDEDIR)/$(PARSERDIR)
	$(MV) $(GRAMMARDIR)/Parser.cxx $(SRCDIR)/$(PARSERDIR)/Parser.cxx
	$(MV) $(GRAMMARDIR)/Parser.hxx $(INCLUDEDIR)/$(PARSERDIR)/Parser.hxx

$(INCLUDEDIR)/$(PARSERDIR)/Lexer.hxx: generate-lexer

$(SRCDIR)/$(PARSERDIR)/Lexer.cxx: generate-lexer

generate-lexer: $(GRAMMARDIR)/Lexer.lxx
	$(CD) $(GRAMMARDIR) && $(FLEX) $(FLEXFLAGS) Lexer.lxx
	$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)/$(PARSERDIR)
	$(MKDIR) $(MKDIRFLAGS) $(INCLUDEDIR)/$(PARSERDIR)
	$(MV) $(GRAMMARDIR)/Lexer.cxx $(SRCDIR)/$(PARSERDIR)/Lexer.cxx
	$(MV) $(GRAMMARDIR)/Lexer.hxx $(INCLUDEDIR)/$(PARSERDIR)/Lexer.hxx

$(OBJDIR)/$(PARSERDIR)/%.o: $(SRCDIR)/$(PARSERDIR)/% $(INCLUDEFILES)
	$(MKDIR) $(MKDIRFLAGS) `$(DIRNAME) $@`
	$(CXX) $(OBJFLAGS) -I$(INCLUDEDIR) -I$(INCLUDEDIR)/$(PARSERDIR) -o$@ $<

$(OBJDIR)/%.o: $(SRCDIR)/% $(INCLUDEFILES)
	$(MKDIR) $(MKDIRFLAGS) `$(DIRNAME) $@`
	$(CXX) $(OBJFLAGS) -I$(INCLUDEDIR) -o$@ $<

$(LIBDIR)/$(LIBNAME).a: $(OBJECTFILES)
	$(MKDIR) $(MKDIRFLAGS) $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

$(LIBDIR)/$(LIBNAME).so: $(OBJECTFILES)
	$(MKDIR) $(MKDIRFLAGS) $(LIBDIR)
	$(CXX) $(LIBFLAGS) -o $@ $^

$(BINDIR)/$(BINNAME): $(DRIVERFILES) $(LIBDIR)/$(LIBNAME).a
	@$(MKDIR) $(MKDIRFLAGS) $(BINDIR)
	$(CXX) $(BINFLAGS) -I$(INCLUDEDIR) -o$@ $^

$(HEADERFILES): copy-header

copy-header: $(INCLUDEFILES)
	@$(MKDIR) $(MKDIRFLAGS) $(HEADERDIR)
	$(CP) $(CPFLAGS) $(INCLUDEDIR)/* $(HEADERDIR)

test:
	@for typefile in $(TYPEFILES); do                                   \
			echo "Testing" $$typefile;                                      \
	    $(BINDIR)/$(BINNAME) $$typefile | diff $$typefile - || exit 1 ; \
	done

cppcheck:
	$(CPPCHECK) --quiet                         \
	            --project=compile_commands.json \
	            --enable=all                    \
	            -I$(INCLUDEDIR)                 \
	            -i$(SRCDIR)/$(PARSERDIR)        \
	            -i$(INCLUDEDIR)/$(PARSERDIR)    \
	            src                             \
	            include

clang-format:
	$(CLANGFORMAT) -i $(CPPSRCFILES) $(CSRCFILES) $(HPPINCLUDEFILES) $(HINCLUDEFILES) $(DRIVERFILES)

.PHONY: all             \
        build           \
        parser          \
        generate-parser \
        lexer           \
        generate-lexer  \
        header          \
        copy-header     \
        library         \
        static-library  \
        shared-library  \
        application     \
        clean           \
        run             \
        clang-format    \
        test            \
        cppcheck
