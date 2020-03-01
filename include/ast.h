#ifndef TASTR_AST_H
#define TASTR_AST_H

#include "ast/CharacterScalarTypeNode.h"
#include "ast/ComplexScalarTypeNode.h"
#include "ast/DoubleScalarTypeNode.h"
#include "ast/EnvironmentTypeNode.h"
#include "ast/ExpressionTypeNode.h"
#include "ast/FunctionTypeNode.h"
#include "ast/GroupTypeNode.h"
#include "ast/IdentifierNode.h"
#include "ast/IntegerScalarTypeNode.h"
#include "ast/LanguageTypeNode.h"
#include "ast/ListTypeNode.h"
#include "ast/LogicalScalarTypeNode.h"
#include "ast/NoNaTypeNode.h"
#include "ast/Node.h"
#include "ast/RawScalarTypeNode.h"
#include "ast/ScalarTypeNode.h"
#include "ast/StructTypeNode.h"
#include "ast/SymbolTypeNode.h"
#include "ast/TagTypePairNode.h"
#include "ast/TypeDeclarationNode.h"
#include "ast/TypeDeclarationSequenceNode.h"
#include "ast/TypeNode.h"
#include "ast/UnionTypeNode.h"
#include "ast/VarargTypeNode.h"
#include "ast/VectorTypeNode.h"
#include "visitor/Visitor.h"

#include <filesystem>
#include <ostream>
#include <string>

std::ostream& operator<<(std::ostream& os, const tastr::ast::Node& node);

std::string to_string(const tastr::ast::Node& node);

int parse_stdin();

int parse_string(const std::string& string);

int parse_file(const std::filesystem::path& filepath);

#endif /* TASTR_AST_H */
