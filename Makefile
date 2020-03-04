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

SRCFILES := $(shell find $(SRCDIR) -name '*.cpp') $(shell find $(SRCDIR) -name '*.c') $(shell find $(SRCDIR) -name '*.cc') $(shell find $(SRCDIR) -name '*.cxx')
INCLUDEFILES := $(shell find $(INCLUDEDIR) -name '*.hpp') $(shell find $(INCLUDEDIR) -name '*.h') $(shell find $(INCLUDEDIR) -name '*.hh') $(shell find $(INCLUDEDIR) -name '*.hxx')
DRIVERFILES := $(shell find $(DRIVERDIR) -name '*.cpp') $(shell find $(DRIVERDIR) -name '*.c') $(shell find $(DRIVERDIR) -name '*.cc')
OBJECTFILES := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(addsuffix .o,$(SRCFILES)))

all: build

build: parser lexer library application

parser: $(SRCDIR)/Parser.cxx $(INCLUDEDIR)/Parser.hxx $(INCLUDEDIR)/location.hh

lexer: $(INCLUDEDIR)/Lexer.hxx $(SRCDIR)/Lexer.cxx

library: static-library shared-library

static-library: $(LIBDIR)/$(LIBNAME).a

shared-library: $(LIBDIR)/$(LIBNAME).so

application: $(BINDIR)/$(BINNAME)

clean:
	$(RM) $(RMFLAGS) $(BUILDDIR)

run: application
	@echo "Write a type declaration. Quit with Ctrl-d."
	./$(BINDIR)/$(BINNAME) $(BINARGS)

$(SRCDIR)/Parser.cxx $(INCLUDEDIR)/Parser.hxx $(INCLUDEDIR)/location.hh: $(GRAMMARDIR)/Parser.yxx
	$(CD) $(GRAMMARDIR) && $(BISON) $(BISONFLAGS) --xml --graph=Parser.gv Parser.yxx
	$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)/$(PARSERDIR)
	$(MKDIR) $(MKDIRFLAGS) $(INCLUDEDIR)/$(PARSERDIR)
	$(MV) $(GRAMMARDIR)/Parser.cxx $(SRCDIR)/Parser.cxx
	$(MV) $(GRAMMARDIR)/Parser.hxx $(INCLUDEDIR)/Parser.hxx
	$(MV) $(GRAMMARDIR)/location.hh $(INCLUDEDIR)/location.hh

$(INCLUDEDIR)/Lexer.hxx $(SRCDIR)/Lexer.cxx: $(GRAMMARDIR)/Lexer.lxx
	$(CD) $(GRAMMARDIR) && $(FLEX) $(FLEXFLAGS) Lexer.lxx
	$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)/$(PARSERDIR)
	$(MV) $(GRAMMARDIR)/Lexer.cxx $(SRCDIR)/Lexer.cxx
	$(MV) $(GRAMMARDIR)/Lexer.hxx $(INCLUDEDIR)/Lexer.hxx

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


.PHONY: all            \
        build          \
        parser         \
        lexer          \
        library        \
        static-library \
        shared-library \
        application    \
        clean          \
        run
