CXX = g++
BISON = bison
FLEX = flex
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
APPNAME := $(PROJECTNAME)
LIBNAME := lib$(PROJECTNAME)


FLEXFLAGS := -v
BISONFLAGS := -v
CXXFLAGS := -O0 -g -ggdb3 -std=c++17
LIBFLAGS := $(CXXFLAGS) -shared -fPIC
APPFLAGS := $(CXXFLAGS)

SRCFILES := $(shell find $(SRCDIR) -name *.cpp) $(shell find $(SRCDIR) -name *.c) $(shell find $(SRCDIR) -name *.cc) $(shell find $(SRCDIR) -name *.cxx)
DRIVERFILES := $(shell find $(DRIVERDIR) -name *.cpp) $(shell find $(DRIVERDIR) -name *.c) $(shell find $(DRIVERDIR) -name *.cc)

all: build

build: clean library application

library: $(BUILDDIR)/$(LIBNAME)

application: $(BUILDDIR)/$(APPNAME)

run: application
	@echo "Write a type. Quit with ctrl-d."
	./$(BUILDDIR)/$(APPNAME) -s -p -

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

$(BUILDDIR)/$(LIBNAME): parser lexer
	$(MKDIR) $(MKDIRFLAGS) $(BUILDDIR)
	$(CXX) $(LIBFLAGS) -I$(INCLUDEDIR) -o$@ $(SRCFILES)

$(BUILDDIR)/$(APPNAME): parser lexer
	$(MKDIR) $(MKDIRFLAGS) $(BUILDDIR)
	$(CXX) $(APPFLAGS) -I$(INCLUDEDIR) -o$@ $(SRCFILES) $(DRIVERFILES)

.PHONY: clean \
        build \
        all   \
        parser \
        lexer \
        library \
        application \
        run
