#ifndef TASTR_VISITOR_VISITOR_H
#define TASTR_VISITOR_VISITOR_H

#include "ast.h"

namespace tastr::visitor {

class Visitor {
  public:
    Visitor() {
    }

    virtual ~Visitor() = default;

    virtual void visit(const tastr::ast::Node& node) = 0;

    virtual void visit(const tastr::ast::TypeNode& node) = 0;

    virtual void visit(const tastr::ast::ScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::IdentifierNode& node) = 0;

    virtual void visit(const tastr::ast::CharacterScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::ComplexScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::DoubleScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::IntegerScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::LogicalScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::RawScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::VectorTypeNode& node) = 0;

    virtual void visit(const tastr::ast::NoNaTypeNode& node) = 0;

    virtual void visit(const tastr::ast::EnvironmentTypeNode& node) = 0;

    virtual void visit(const tastr::ast::ExpressionTypeNode& node) = 0;

    virtual void visit(const tastr::ast::LanguageTypeNode& node) = 0;

    virtual void visit(const tastr::ast::SymbolTypeNode& node) = 0;

    virtual void visit(const tastr::ast::ExternalPointerTypeNode& node) = 0;

    virtual void visit(const tastr::ast::BytecodeTypeNode& node) = 0;

    virtual void visit(const tastr::ast::PairlistTypeNode& node) = 0;

    virtual void visit(const tastr::ast::S4TypeNode& node) = 0;

    virtual void visit(const tastr::ast::FunctionTypeNode& node) = 0;

    virtual void visit(const tastr::ast::ListTypeNode& node) = 0;

    virtual void visit(const tastr::ast::StructTypeNode& node) = 0;

    virtual void visit(const tastr::ast::GroupTypeNode& node) = 0;

    virtual void visit(const tastr::ast::UnionTypeNode& node) = 0;

    virtual void visit(const tastr::ast::VarargTypeNode& node) = 0;

    virtual void visit(const tastr::ast::TypeNodeSequenceNode& node) = 0;

    virtual void visit(const tastr::ast::TagTypePairNode& node) = 0;

    virtual void visit(const tastr::ast::TagTypePairNodeSequenceNode& node) = 0;

    virtual void visit(const tastr::ast::TypeDeclarationNode& node) = 0;

    virtual void
    visit(const tastr::ast::TypeDeclarationNodeSequenceNode& node) = 0;

    virtual void visit(const tastr::ast::TopLevelNode& node) = 0;
};

} // namespace tastr::visitor

#endif /* TASTR_VISITOR_VISITOR_H */
