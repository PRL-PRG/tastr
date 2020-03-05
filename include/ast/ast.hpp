#ifndef TASTR_AST_AST_H
#define TASTR_AST_AST_H

#include "ast/AnyTypeNode.hpp"
#include "ast/BytecodeTypeNode.hpp"
#include "ast/CharacterScalarTypeNode.hpp"
#include "ast/ComplexScalarTypeNode.hpp"
#include "ast/DoubleScalarTypeNode.hpp"
#include "ast/EnvironmentTypeNode.hpp"
#include "ast/ExpressionTypeNode.hpp"
#include "ast/ExternalPointerTypeNode.hpp"
#include "ast/FunctionTypeNode.hpp"
#include "ast/GroupTypeNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/IntegerScalarTypeNode.hpp"
#include "ast/LanguageTypeNode.hpp"
#include "ast/ListTypeNode.hpp"
#include "ast/LogicalScalarTypeNode.hpp"
#include "ast/NoNaTypeNode.hpp"
#include "ast/Node.hpp"
#include "ast/PairlistTypeNode.hpp"
#include "ast/RawScalarTypeNode.hpp"
#include "ast/S4TypeNode.hpp"
#include "ast/ScalarTypeNode.hpp"
#include "ast/StructTypeNode.hpp"
#include "ast/SymbolTypeNode.hpp"
#include "ast/TagTypePairNode.hpp"
#include "ast/TagTypePairNodeSequenceNode.hpp"
#include "ast/TopLevelNode.hpp"
#include "ast/TypeDeclarationNode.hpp"
#include "ast/TypeDeclarationNodeSequenceNode.hpp"
#include "ast/TypeNode.hpp"
#include "ast/TypeNodeSequenceNode.hpp"
#include "ast/UnionTypeNode.hpp"
#include "ast/VarargTypeNode.hpp"
#include "ast/VectorTypeNode.hpp"
#include "parser/ParseResult.hpp"
#include "visitor/Visitor.hpp"

#include <filesystem>
#include <ostream>
#include <string>

std::ostream& operator<<(std::ostream& os, const tastr::ast::Node& node);

std::string to_string(const tastr::ast::Node& node);

tastr::parser::ParseResult parse_stdin(bool debug_lexer = false,
                                       bool debug_parser = false);

tastr::parser::ParseResult parse_string(const std::string& string,
                                        bool debug_lexer = false,
                                        bool debug_parser = false);

tastr::parser::ParseResult parse_file(const std::filesystem::path& filepath,
                                      bool debug_lexer = false,
                                      bool debug_parser = false);

#endif /* TASTR_AST_AST_H */
