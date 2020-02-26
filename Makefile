CXX = g++
BISON = bison
FLEX = flex
MV := mv
MKDIR := mkdir
MKDIRFLAGS := -p

SRCDIR := src
INCLUDEDIR := include
GRAMMARDIR := grammar
DRIVERDIR := driver
BUILDDIR := build
LIBNAME := librtypesparser
APPNAME := rtypesparser

FLEXFLAGS := -v
BISONFLAGS := -v
CXXFLAGS := -O0 -g -ggdb3 -std=c++17
LIBFLAGS := $(CXXFLAGS) -shared -fPIC
APPFLAGS := $(CXXFLAGS)

SRCFILES := $(shell find $(SRCDIR) -name *.cpp) $(shell find $(SRCDIR) -name *.c) $(shell find $(SRCDIR) -name *.cc)
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

parser: $(GRAMMARDIR)/parser.yy
	$(BISON) $(BISONFLAGS) --xml --graph=$(GRAMMARDIR)/Parser.gv -o $(GRAMMARDIR)/Parser.cpp $<
	$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)
	$(MKDIR) $(MKDIRFLAGS) $(INCLUDEDIR)
	$(MV) $(GRAMMARDIR)/Parser.cpp $(SRCDIR)
	$(MV) $(GRAMMARDIR)/Parser.hpp $(GRAMMARDIR)/location.hh $(INCLUDEDIR)

scanner: $(GRAMMARDIR)/scanner.ll
	$(FLEX) $(FLEXFLAGS) -o$(GRAMMARDIR)/scanner.cpp $<
	$(MKDIR) $(MKDIRFLAGS) $(SRCDIR)
	$(MV) $(GRAMMARDIR)/scanner.cpp $(SRCDIR)

$(BUILDDIR)/librtypesparser: parser scanner
	$(MKDIR) $(MKDIRFLAGS) $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -I$(INCLUDEDIR) -o$@ $(SRCFILES)

$(BUILDDIR)/rtypesparser: parser scanner
	$(MKDIR) $(MKDIRFLAGS) $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(APPFLAGS) -I$(INCLUDEDIR) -o$@ $(SRCFILES) $(DRIVERFILES)

.PHONY: clean \
        build \
        all   \
        parser \
        scanner \
        library \
        application \
        run
