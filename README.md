# tastr: Type AST for R

`tastr` is a library that implements a grammar for R types. It provides functions to parse types from input streams (files, strings, etc.) to C++ objects. It also provides the reverse functionality to unparse these objects. 
The Type AST is modeled using C++ classes. The design relies heavily on unique ownership, i.e., an AST node holds unique references to its child nodes.
The grammar is implemented using [`flex`](https://westes.github.io/flex/manual/) and [`bison`](https://www.gnu.org/software/bison/manual/bison.html).

## Administration

To obtain the project source, run:

`$` `git clone https://github.com/aviralg/tastr.git`

To build the project, run:

`$` `make`

To clean the build artifacts, run:

`$` `make clean`


## Type Grammar

`<integer>`: `"integer"`
           | `"int"`
           | `"i"`

`<double>`: `"double"`
          | `"dbl"`
          | `"d"` 

`<complex>`: `"complex"` 
           | `"clx"` 
           | `"x"`

`<character>`: `"character"` 
             | `"chr"` 
             | `"s"`

`<logical>`: `"logical"` 
           | `"lgl"` 
           | `"l"`

`<raw>`: `"raw"` 
       | `"r"`

`<environment>`: `"environment"`
               | `"env"`
               | `"t"`

`<expression>`: `"expression"`
              | `"exr"`
              | `"e"` 

`<language>`: `"language"` 
            | `"lng"` 
            | `"g"`

`<symbol>`: `"symbol"` 
          | `"sym"` 
          | `"y"`

`<scalar>` : `<integer>`
           | `<double>`
           | `<complex>`
           | `<character>`
           | `<logical>`
           | `<raw>`

`<vector>`: `<scalar>` `"["` `"]"`

`<nona>`: `"!"` `<vector>`

`<list>`: `"(("` `<typeseq>` `"))"`

`<typeseq>`: ` `
           | `<type>`
           | `<typeseq>` `","` `<type>`

`<struct>`: `"{{"` `<tagtypeseq>` `"}}"`

`<tagtypeseq>`: ` `
              | `<tagtype>`
              | `<tagtypeseq>` `","` `<tagtype>`

`<tagtype>`: `<tag>` `":"` `<type>`

`<tag>`: `<identifier>`

 `<function>`: `"<"` `<paramseq>` `">"` `"=>"` `<type>`

`<param>`: `<type>` | `"..."`

`<paramseq>`: ` `
            | `<param>`
            | `<paramseq>` `","` `<param>`

`<group>`: `"("` `<type>`  `")"`

`<union>`: `<type>` `"|"` `<type>`

`<type>`: `<scalar>`
      | `<environment>`
      | `<expression>`
      | `<language>`
      | `<symbol>`
      | `<vector>`
      | `<nona>`
      | `<list>`
      | `<struct>`
      | `<function>`
      | `<group>`
      | `<union>`


`<decl>`: `"type"` `<identifier>` `<type>` `";"`

`<declseq>`: `<decl>`
           | `<declseq>` `<decl>`



## Useful Resources

### Bison and Flex
- [Flex Token Order](https://stackoverflow.com/questions/22444094/flex-token-order)
- [UTK Bison Notes](http://web.eecs.utk.edu/~bvanderz/teaching/cs461Sp11/notes/bison/)
- [Parsing rule for empty files](https://stackoverflow.com/questions/11047227/no-error-while-parsing-empty-file-yacc-lex)
- [Dynamic file loading in Flex](https://stackoverflow.com/questions/31839746/loading-external-files-flex-bison-yyin)
- [Redefine `YY_INPUT` in Flex](https://stackoverflow.com/questions/1920604/how-to-make-yy-input-point-to-a-string-rather-than-stdin-in-lex-yacc-solaris)
- [C++ istream with Flex](https://stackoverflow.com/questions/9628099/c-istream-with-lex)
- [Bison/Flex Example](https://github.com/ezaquarii/bison-flex-cpp-example)
- [Read from C++ streams in Flex](https://stackoverflow.com/questions/780676/string-input-to-flex-lexer)
- [Lex and Yacc Tutorial](https://www.epaperpress.com/lexandyacc/index.html)
- [Parsing strings in Flex](http://dinosaur.compilertools.net/flex/flex_11.html)
- [Bison/Flex Example](https://coldfix.eu/2015/05/16/bison-c++11/)
- [Unique Pointer as a Semantic Value in Bison](http://www.comrite.com/wp/c11-stdunique_ptr-as-semantic-value-in-bison-c-mode/)
- [Resolving Grammar Conflicts](https://efxa.org/2014/05/17/techniques-for-resolving-common-grammar-conflicts-in-parsers/)
- [Bison/Flex Example](http://www.kylheku.com/cgit/txr/tree/parser.l)
- [Bison/Flex Example](http://www.jonathanbeard.io/tutorials/FlexBisonC++)
- [Bison/Flex Example](http://panthema.net/2007/flex-bison-cpp-example/)
- [Bison/Flex Example](https://panthema.net/2007/flex-bison-cpp-example/flex-bison-cpp-example-0.1/doxygen-html/index.html)
- [Bison/Flex Example](https://github.com/EmilGedda/Leonardo)

### C++: Unique Pointers and Polymorphism
- [Arguments and Unique Pointers](https://vladris.com/blog/2016/03/11/arguments-and-smart-pointers.html)
- [Smart Pointer Parameters](https://herbsutter.com/2013/06/05/gotw-91-solution-smart-pointer-parameters/)
- [Move Constructors and Multiple Inheritance](https://stackoverflow.com/questions/10114701/move-constructors-and-multiple-inheritance)
- [Copy Constructors and Unique Pointer](https://stackoverflow.com/questions/16030081/copy-constructor-for-a-class-with-unique-ptr)
- [Rules for Smart Pointers](https://www.modernescpp.com/index.php/c-core-guidelines-rules-to-smart-pointers)
- [Using Smart Pointers as Class Members](https://stackoverflow.com/questions/15648844/using-smart-pointers-for-class-members)
- [Cloning, Covariant Return and Smart Pointer](https://www.fluentcpp.com/2017/09/12/how-to-return-a-smart-pointer-and-use-covariance/)
- [How I Declare my Class and Why](http://howardhinnant.github.io/classdecl.html)
- [Polymorphic Cloning and CRTP](https://katyscode.wordpress.com/2013/08/22/c-polymorphic-cloning-and-the-crtp-curiously-recurring-template-pattern/)
- [Delegating Constructors](https://arne-mertz.de/2015/08/new-c-features-inherited-and-delegating-constructors/)
- [`==` operator and Polymorphism](https://stackoverflow.com/a/565785)
- [Move constructors and inheritance](https://stackoverflow.com/questions/15351341/move-constructors-and-inheritance)
- [Move assignment operator and inheritance](https://stackoverflow.com/questions/50854598/inheritence-of-the-move-assignment-operator-in-c)
- [Move assignment on self](https://stackoverflow.com/questions/9322174/move-assignment-operator-and-if-this-rhs)
- [C++ `final` keyword](https://smartbear.com/blog/develop/use-c11-inheritance-control-keywords-to-prevent-in/)

## Make and Code Compilation
- [Compiling a static library in linux](https://stackoverflow.com/questions/2734719/how-to-compile-a-static-library-in-linux)
- [Compiling C/C++ software](https://gist.github.com/gubatron/32f82053596c24b6bec6)
