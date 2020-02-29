#ifndef TASTR_AST_VISITOR_VISITOR_H
#define TASTR_AST_VISITOR_VISITOR_H

#include "ast.h"

namespace tastr::ast::visitor {

class Visitor {
  public:
    Visitor() {
    }

    virtual ~Visitor() {
    }

    virtual void visit(const tastr::ast::node::Node& node) = 0;

    virtual void visit(const tastr::ast::node::Type& node) = 0;

    virtual void visit(const tastr::ast::node::ScalarType& node) = 0;

    virtual void visit(const tastr::ast::node::CompositeType& node) = 0;

    virtual void visit(
        const tastr::ast::node::SequenceType<tastr::ast::node::Type>& node) = 0;

    virtual void
    visit(const tastr::ast::node::SequenceType<tastr::ast::node::TaggedType>&
              type) = 0;

    virtual void visit(const tastr::ast::node::TaggedType& node) = 0;

    virtual void visit(const tastr::ast::node::CharacterType& node) = 0;

    virtual void visit(const tastr::ast::node::ComplexType& node) = 0;

    virtual void visit(const tastr::ast::node::DoubleType& node) = 0;

    virtual void visit(const tastr::ast::node::ParameterType& node) = 0;

    virtual void visit(const tastr::ast::node::EnvironmentType& node) = 0;

    virtual void visit(const tastr::ast::node::ExpressionType& node) = 0;

    virtual void visit(const tastr::ast::node::LanguageType& node) = 0;

    virtual void visit(const tastr::ast::node::SymbolType& node) = 0;

    virtual void visit(const tastr::ast::node::Identifier& node) = 0;

    virtual void visit(const tastr::ast::node::FunctionType& node) = 0;

    virtual void visit(const tastr::ast::node::GroupType& node) = 0;

    virtual void visit(const tastr::ast::node::IntegerType& node) = 0;

    virtual void visit(const tastr::ast::node::ListType& node) = 0;

    virtual void visit(const tastr::ast::node::LogicalType& node) = 0;

    virtual void visit(const tastr::ast::node::NoNaType& node) = 0;

    virtual void visit(const tastr::ast::node::RawType& node) = 0;

    virtual void visit(const tastr::ast::node::StructType& node) = 0;

    virtual void visit(const tastr::ast::node::UnionType& node) = 0;

    virtual void visit(const tastr::ast::node::VectorType& node) = 0;

    virtual void visit(const tastr::ast::node::VarargType& node) = 0;

    virtual void visit(const tastr::ast::node::TypeDeclaration& node) = 0;

    virtual void visit(const tastr::ast::node::TypeDeclarationSequence& node) = 0;

};

} // namespace tastr::ast::visitor

#endif /* TASTR_AST_VISITOR_VISITOR_H */
