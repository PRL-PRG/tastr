#ifndef TASTR_AST_H
#define TASTR_AST_H

#include "ast/CharacterTypeNode.h"
#include "ast/ComplexTypeNode.h"
#include "ast/CompositeTypeNode.h"
#include "ast/DoubleTypeNode.h"
#include "ast/EnvironmentTypeNode.h"
#include "ast/ExpressionTypeNode.h"
#include "ast/FunctionTypeNode.h"
#include "ast/GroupTypeNode.h"
#include "ast/IdentifierNode.h"
#include "ast/IntegerTypeNode.h"
#include "ast/LanguageTypeNode.h"
#include "ast/ListTypeNode.h"
#include "ast/LogicalTypeNode.h"
#include "ast/NoNaTypeNode.h"
#include "ast/Node.h"
#include "ast/RawTypeNode.h"
#include "ast/ScalarTypeNode.h"
#include "ast/StructTypeNode.h"
#include "ast/SymbolTypeNode.h"
#include "ast/TaggedTypeNode.h"
#include "ast/TypeNode.h"
#include "ast/TypeDeclarationNode.h"
#include "ast/TypeDeclarationSequenceNode.h"
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
