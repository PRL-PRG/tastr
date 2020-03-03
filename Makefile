CXX := g++
BISON := bison
FLEX := flex
AR := ar
MV := mv
MKDIR := mkdir
MKDIRFLAGS := -p
CD := cd

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


FLEXFLAGS := -v
BISONFLAGS := -v
ARFLAGS := rcs
CXXFLAGS := -O0 -g -ggdb3 -std=c++17
OBJFLAGS := -c -fPIC $(CXXFLAGS)
LIBFLAGS := -shared
BINFLAGS := $(CXXFLAGS)

SRCFILES := $(shell find $(SRCDIR) -name *.cpp) $(shell find $(SRCDIR) -name *.c) $(shell find $(SRCDIR) -name *.cc) $(shell find $(SRCDIR) -name *.cxx)
INCLUDEILES := $(shell find $(INCLUDEDIR) -name *.hpp) $(shell find $(INCLUDEDIR) -name *.h) $(shell find $(INCLUDEDIR) -name *.hh) $(shell find $(INCLUDEDIR) -name *.hxx)
DRIVERFILES := $(shell find $(DRIVERDIR) -name *.cpp) $(shell find $(DRIVERDIR) -name *.c) $(shell find $(DRIVERDIR) -name *.cc)
OBJECTFILES := $(addprefix $(OBJDIR)/,$(notdir $(patsubst %.cpp,%.o,$(patsubst %.cxx,%.o,$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(SRCFILES)))))))

all: build

build: clean library application

library: $(LIBDIR)/$(LIBNAME).so

application: $(BINDIR)/$(BINNAME)

run: application
	@echo "Write a type. Quit with ctrl-d."
	./$(BUILDDIR)/$(BINNAME) -s -p -

clean:
	rm -rf $(BUILDDIR)

parser: $(GRAMMARDIR)/Parser.yxx
	$(CD) $(GRAMMARDIR) && $(BISON) $(BISONFLAGS) --xml --graph=Parser.gv Parser.yxx
	$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)/$(PARSERDIR)
	$(MKDIR) $(MKDIRFLAGS) $(INCLUDEDIR)/$(PARSERDIR)
	$(MV) $(GRAMMARDIR)/Parser.cxx $(SRCDIR)/Parser.cxx
	$(MV) $(GRAMMARDIR)/Parser.hxx $(INCLUDEDIR)/Parser.hxx
	$(MV) $(GRAMMARDIR)/location.hh $(INCLUDEDIR)/location.hh

lexer: $(GRAMMARDIR)/Lexer.lxx
	$(CD) $(GRAMMARDIR) && $(FLEX) $(FLEXFLAGS) Lexer.lxx
	$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)/$(PARSERDIR)
	$(MV) $(GRAMMARDIR)/Lexer.cxx $(SRCDIR)/Lexer.cxx
	$(MV) $(GRAMMARDIR)/Lexer.hxx $(INCLUDEDIR)/Lexer.hxx

$(OBJDIR)/$(OBJNAME).o: parser lexer $(SRCFILES) $(INCLUDEFILES)
	$(MKDIR) $(MKDIRFLAGS) $(OBJDIR)
	$(CD) $(OBJDIR) && $(CXX) $(OBJFLAGS) -I$(realpath $(INCLUDEDIR)) $(realpath $(SRCFILES))
	$(CXX) $(LIBFLAGS) -o$@ $(OBJECTFILES)

# https://stackoverflow.com/questions/2734719/how-to-compile-a-static-library-in-linux
$(LIBDIR)/$(LIBNAME).a: $(OBJDIR)/$(OBJNAME).o
	$(MKDIR) $(MKDIRFLAGS) $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $<

$(LIBDIR)/$(LIBNAME).so: $(LIBDIR)/$(LIBNAME).a
	$(MKDIR) $(MKDIRFLAGS) $(LIBDIR)
	$(CXX) $(LIBFLAGS) -o $@ $<

$(BINDIR)/$(BINNAME): $(DRIVERFILES) $(OBJECTFILES)
	$(MKDIR) $(MKDIRFLAGS) $(BINDIR)
	$(CXX) $(BINFLAGS) -I$(INCLUDEDIR) -o$@ $(DRIVERFILES) $(OBJECTFILES)


.PHONY: clean \
        build \
        all   \
        parser \
        lexer \
        library \
        application \
        test \
        run
