SRCDIR := src
INCLUDEDIR := include
GRAMMARDIR := grammar
DRIVERDIR := driver
BUILDDIR := build
PARSERDIR := parser
PROJECTNAME := tastr
OBJDIR := $(BUILDDIR)/objects
BINDIR := $(BUILDDIR)/bin
LIBDIR := $(BUILDDIR)/lib
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

RMFLAGS := -rf
MKDIRFLAGS := -p
FLEXFLAGS := -v
BISONFLAGS := -v
ARFLAGS := rcs

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

DRIVERFILES := $(shell find $(DRIVERDIR) -name '*.cpp') $(shell find $(DRIVERDIR) -name '*.c') $(shell find $(DRIVERDIR) -name '*.cc')
OBJECTFILES := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(addsuffix .o,$(SRCFILES)))

all: build

build: parser lexer library application

parser: $(SRCDIR)/$(PARSERDIR)/Parser.cxx $(INCLUDEDIR)/$(PARSERDIR)/Parser.hxx $(INCLUDEDIR)/$(PARSERDIR)/location.hh

lexer: $(INCLUDEDIR)/$(PARSERDIR)/Lexer.hxx $(SRCDIR)/$(PARSERDIR)/Lexer.cxx

library: static-library shared-library

static-library: $(LIBDIR)/$(LIBNAME).a

shared-library: $(LIBDIR)/$(LIBNAME).so

application: $(BINDIR)/$(BINNAME)

clean:
	$(RM) $(RMFLAGS) $(BUILDDIR)

run: application
	@echo "Write a type declaration. Quit with Ctrl-d."
	./$(BINDIR)/$(BINNAME) $(BINARGS)

$(SRCDIR)/$(PARSERDIR)/Parser.cxx $(INCLUDEDIR)/$(PARSERDIR)/Parser.hxx $(INCLUDEDIR)/$(PARSERDIR)/location.hh: $(GRAMMARDIR)/Parser.yxx
	$(CD) $(GRAMMARDIR) && $(BISON) $(BISONFLAGS) --xml --graph=Parser.gv Parser.yxx
	$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)/$(PARSERDIR)
	$(MKDIR) $(MKDIRFLAGS) $(INCLUDEDIR)/$(PARSERDIR)
	$(MV) $(GRAMMARDIR)/Parser.cxx $(SRCDIR)/$(PARSERDIR)/Parser.cxx
	$(MV) $(GRAMMARDIR)/Parser.hxx $(INCLUDEDIR)/$(PARSERDIR)/Parser.hxx
	$(MV) $(GRAMMARDIR)/location.hh $(INCLUDEDIR)/$(PARSERDIR)/location.hh

$(INCLUDEDIR)/$(PARSERDIR)/Lexer.hxx $(SRCDIR)/$(PARSERDIR)/Lexer.cxx: $(GRAMMARDIR)/Lexer.lxx
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

.PHONY: all            \
        build          \
        parser         \
        lexer          \
        library        \
        static-library \
        shared-library \
        application    \
        clean          \
        run            \
        clang-format   \
        cppcheck
