#ifndef R_TYPE_AST_VISITOR_TYPE_VISITOR_H
#define R_TYPE_AST_VISITOR_TYPE_VISITOR_H

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
#include "ast/node/RawType.h"
#include "ast/node/ScalarType.h"
#include "ast/node/StructType.h"
#include "ast/node/Type.h"
#include "ast/node/UnionType.h"
#include "ast/node/VectorType.h"

namespace rtype::ast::visitor {

class TypeVisitor {
  public:
    TypeVisitor() {
    }

    virtual ~TypeVisitor() {
    }

    virtual void visit(const rtype::ast::node::Type& type) = 0;

    virtual void visit(const rtype::ast::node::ScalarType& type) = 0;

    virtual void visit(const rtype::ast::node::CompositeType& type) = 0;

    virtual void visit(
        const rtype::ast::node::SequenceType<rtype::ast::node::Type>& type) = 0;

    virtual void
    visit(const rtype::ast::node::SequenceType<rtype::ast::node::NamedType>&
              type) = 0;

    virtual void visit(const rtype::ast::node::NamedType& type) = 0;

    virtual void visit(const rtype::ast::node::CharacterType& type) = 0;

    virtual void visit(const rtype::ast::node::ComplexType& type) = 0;

    virtual void visit(const rtype::ast::node::DoubleType& type) = 0;

    virtual void visit(const rtype::ast::node::ParameterType& type) = 0;

    virtual void visit(const rtype::ast::node::FunctionType& type) = 0;

    virtual void visit(const rtype::ast::node::GroupType& type) = 0;

    virtual void visit(const rtype::ast::node::IntegerType& type) = 0;

    virtual void visit(const rtype::ast::node::ListType& type) = 0;

    virtual void visit(const rtype::ast::node::LogicalType& type) = 0;

    virtual void visit(const rtype::ast::node::NoNaType& type) = 0;

    virtual void visit(const rtype::ast::node::RawType& type) = 0;

    virtual void visit(const rtype::ast::node::StructType& type) = 0;

    virtual void visit(const rtype::ast::node::UnionType& type) = 0;

    virtual void visit(const rtype::ast::node::VectorType& type) = 0;
};

} // namespace rtype::ast::visitor

#endif /* R_TYPE_AST_VISITOR_TYPE_VISITOR_H */
