#include "RTypesParser.h"
#include "ast.h"

#include <iostream>

int main(int argc, char* argv[]) {
    int result = 0;
    RTypesParser parser;
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            parser.trace_parsing();
        } else if (argv[i] == std::string("-s")) {
            parser.trace_scanning();
        } else if (!parser.parse(argv[i])) {
            // TODO: fixme
            //rtype::ast::node::Type* ast = parser.get_ast();
            ///////////////////////////////////////
            // if(ast) {                         //
            //     std::cout << "AST: " << *ast; //
            // }                                 //
            ///////////////////////////////////////
            std::cout << parser.get_result() << '\n';
        } else {
            result = 1;
        }
    }
    return result;
}
