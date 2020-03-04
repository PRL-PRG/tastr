#ifndef TASTR_AST_H
#define TASTR_AST_H

#include "ast/AnyTypeNode.h"
#include "ast/BytecodeTypeNode.h"
#include "ast/CharacterScalarTypeNode.h"
#include "ast/ComplexScalarTypeNode.h"
#include "ast/DoubleScalarTypeNode.h"
#include "ast/EnvironmentTypeNode.h"
#include "ast/ExpressionTypeNode.h"
#include "ast/ExternalPointerTypeNode.h"
#include "ast/FunctionTypeNode.h"
#include "ast/GroupTypeNode.h"
#include "ast/IdentifierNode.h"
#include "ast/IntegerScalarTypeNode.h"
#include "ast/LanguageTypeNode.h"
#include "ast/ListTypeNode.h"
#include "ast/LogicalScalarTypeNode.h"
#include "ast/NoNaTypeNode.h"
#include "ast/Node.h"
#include "ast/PairlistTypeNode.h"
#include "ast/RawScalarTypeNode.h"
#include "ast/S4TypeNode.h"
#include "ast/ScalarTypeNode.h"
#include "ast/StructTypeNode.h"
#include "ast/SymbolTypeNode.h"
#include "ast/TagTypePairNode.h"
#include "ast/TagTypePairNodeSequenceNode.h"
#include "ast/TopLevelNode.h"
#include "ast/TypeDeclarationNode.h"
#include "ast/TypeDeclarationNodeSequenceNode.h"
#include "ast/TypeNode.h"
#include "ast/TypeNodeSequenceNode.h"
#include "ast/UnionTypeNode.h"
#include "ast/VarargTypeNode.h"
#include "ast/VectorTypeNode.h"
#include "parser/ParseResult.h"
#include "visitor/Visitor.h"

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

#endif /* TASTR_AST_H */
