#ifndef TASTR_VISITOR_MUTABLE_VISITOR_HPP
#define TASTR_VISITOR_MUTABLE_VISITOR_HPP

#include "ast/ast.hpp"

namespace tastr::visitor {

class MutableVisitor {
  public:
    MutableVisitor() {
    }

    virtual ~MutableVisitor() = default;

    virtual void visit(tastr::ast::Node& node) = 0;

    virtual void visit(tastr::ast::TypeNode& node) = 0;

    virtual void visit(tastr::ast::ScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::IdentifierNode& node) = 0;

    virtual void visit(tastr::ast::CharacterScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::ComplexScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::DoubleScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::IntegerScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::LogicalScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::RawScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::VectorTypeNode& node) = 0;

    virtual void visit(tastr::ast::NoNaTypeNode& node) = 0;

    virtual void visit(tastr::ast::EnvironmentTypeNode& node) = 0;

    virtual void visit(tastr::ast::ExpressionTypeNode& node) = 0;

    virtual void visit(tastr::ast::LanguageTypeNode& node) = 0;

    virtual void visit(tastr::ast::SymbolTypeNode& node) = 0;

    virtual void visit(tastr::ast::ExternalPointerTypeNode& node) = 0;

    virtual void visit(tastr::ast::BytecodeTypeNode& node) = 0;

    virtual void visit(tastr::ast::PairlistTypeNode& node) = 0;

    virtual void visit(tastr::ast::S4TypeNode& node) = 0;

    virtual void visit(tastr::ast::AnyTypeNode& node) = 0;

    virtual void visit(tastr::ast::FunctionTypeNode& node) = 0;

    virtual void visit(tastr::ast::ListTypeNode& node) = 0;

    virtual void visit(tastr::ast::StructTypeNode& node) = 0;

    virtual void visit(tastr::ast::GroupTypeNode& node) = 0;

    virtual void visit(tastr::ast::UnionTypeNode& node) = 0;

    virtual void visit(tastr::ast::VarargTypeNode& node) = 0;

    virtual void visit(tastr::ast::NullTypeNode& node) = 0;

    virtual void visit(tastr::ast::NullableTypeNode& node) = 0;

    virtual void visit(tastr::ast::TypeNodeSequenceNode& node) = 0;

    virtual void visit(tastr::ast::TagTypePairNode& node) = 0;

    virtual void visit(tastr::ast::TagTypePairNodeSequenceNode& node) = 0;

    virtual void visit(tastr::ast::TypeDeclarationNode& node) = 0;

    virtual void visit(tastr::ast::TypeDeclarationNodeSequenceNode& node) = 0;

    virtual void visit(tastr::ast::TopLevelNode& node) = 0;
};

} // namespace tastr::visitor

#endif /* TASTR_VISITOR_MUTABLE_VISITOR_HPP */
