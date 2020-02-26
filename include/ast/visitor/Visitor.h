#ifndef R_TYPE_AST_VISITOR_VISITOR_H
#define R_TYPE_AST_VISITOR_VISITOR_H

#include "ast.h"

namespace rtype::ast::visitor {

class Visitor {
  public:
    Visitor() {
    }

    virtual ~Visitor() {
    }

    virtual void visit(const rtype::ast::node::Node& node) = 0;

    virtual void visit(const rtype::ast::node::Type& node) = 0;

    virtual void visit(const rtype::ast::node::ScalarType& node) = 0;

    virtual void visit(const rtype::ast::node::CompositeType& node) = 0;

    virtual void visit(
        const rtype::ast::node::SequenceType<rtype::ast::node::Type>& node) = 0;

    virtual void
    visit(const rtype::ast::node::SequenceType<rtype::ast::node::NamedType>&
              type) = 0;

    virtual void visit(const rtype::ast::node::NamedType& node) = 0;

    virtual void visit(const rtype::ast::node::CharacterType& node) = 0;

    virtual void visit(const rtype::ast::node::ComplexType& node) = 0;

    virtual void visit(const rtype::ast::node::DoubleType& node) = 0;

    virtual void visit(const rtype::ast::node::ParameterType& node) = 0;

    virtual void visit(const rtype::ast::node::FunctionType& node) = 0;

    virtual void visit(const rtype::ast::node::GroupType& node) = 0;

    virtual void visit(const rtype::ast::node::IntegerType& node) = 0;

    virtual void visit(const rtype::ast::node::ListType& node) = 0;

    virtual void visit(const rtype::ast::node::LogicalType& node) = 0;

    virtual void visit(const rtype::ast::node::NoNaType& node) = 0;

    virtual void visit(const rtype::ast::node::RawType& node) = 0;

    virtual void visit(const rtype::ast::node::StructType& node) = 0;

    virtual void visit(const rtype::ast::node::UnionType& node) = 0;

    virtual void visit(const rtype::ast::node::VectorType& node) = 0;

    virtual void visit(const rtype::ast::node::TypeDeclaration& node) = 0;
};

} // namespace rtype::ast::visitor

#endif /* R_TYPE_AST_VISITOR_VISITOR_H */
