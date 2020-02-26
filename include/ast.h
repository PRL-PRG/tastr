#ifndef R_TYPE_AST_H
#define R_TYPE_AST_H

#include "ast/node/CharacterType.h"
#include "ast/node/ComplexType.h"
#include "ast/node/CompositeType.h"
#include "ast/node/DoubleType.h"
#include "ast/node/FunctionType.h"
#include "ast/node/GroupType.h"
#include "ast/node/IntegerType.h"
#include "ast/node/ListType.h"
#include "ast/node/LogicalType.h"
#include "ast/node/NamedType.h"
#include "ast/node/NoNaType.h"
#include "ast/node/ParameterType.h"
#include "ast/node/RawType.h"
#include "ast/node/ScalarType.h"
#include "ast/node/SequenceType.h"
#include "ast/node/StructType.h"
#include "ast/node/Type.h"
#include "ast/node/UnionType.h"
#include "ast/node/VectorType.h"
#include "ast/visitor/TypeVisitor.h"

#include <ostream>
#include <string>

std::ostream& operator<<(std::ostream& os, const rtype::ast::node::Type& type);

std::string to_string(const rtype::ast::node::Type& type);

#endif /* R_TYPE_AST_H */
