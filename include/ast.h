#ifndef TASTR_AST_H
#define TASTR_AST_H

#include "ast/CharacterType.h"
#include "ast/ComplexType.h"
#include "ast/CompositeType.h"
#include "ast/DoubleType.h"
#include "ast/EnvironmentType.h"
#include "ast/ExpressionType.h"
#include "ast/FunctionType.h"
#include "ast/GroupType.h"
#include "ast/Identifier.h"
#include "ast/IntegerType.h"
#include "ast/LanguageType.h"
#include "ast/ListType.h"
#include "ast/LogicalType.h"
#include "ast/NoNaType.h"
#include "ast/Node.h"
#include "ast/ParameterType.h"
#include "ast/RawType.h"
#include "ast/ScalarType.h"
#include "ast/SequenceType.h"
#include "ast/StructType.h"
#include "ast/SymbolType.h"
#include "ast/TaggedType.h"
#include "ast/Type.h"
#include "ast/TypeDeclaration.h"
#include "ast/TypeDeclarationSequence.h"
#include "ast/UnionType.h"
#include "ast/VarargType.h"
#include "ast/VectorType.h"
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
