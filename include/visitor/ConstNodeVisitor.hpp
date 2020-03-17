#ifndef TASTR_VISITOR_CONST_NODE_VISITOR_HPP
#define TASTR_VISITOR_CONST_NODE_VISITOR_HPP

#include "ast/ast.hpp"

namespace tastr::visitor {

class ConstNodeVisitor {
  public:
    ConstNodeVisitor() {
    }

    virtual ~ConstNodeVisitor() = default;

    virtual void visit(const tastr::ast::Node& node) = 0;

    virtual void visit(const tastr::ast::TypeNode& node) = 0;

    virtual void visit(const tastr::ast::ScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::AScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::NAScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::IdentifierNode& node) = 0;

    virtual void visit(const tastr::ast::KeywordNode& node) = 0;

    virtual void visit(const tastr::ast::OperatorNode& node) = 0;

    virtual void visit(const tastr::ast::TerminatorNode& node) = 0;

    virtual void visit(const tastr::ast::SeparatorNode& node) = 0;

    virtual void visit(const tastr::ast::EmptyNode& node) = 0;

    virtual void visit(const tastr::ast::CharacterAScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::ComplexAScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::DoubleAScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::IntegerAScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::LogicalAScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::RawAScalarTypeNode& node) = 0;

    virtual void visit(const tastr::ast::VectorTypeNode& node) = 0;

    virtual void visit(const tastr::ast::EnvironmentTypeNode& node) = 0;

    virtual void visit(const tastr::ast::ExpressionTypeNode& node) = 0;

    virtual void visit(const tastr::ast::LanguageTypeNode& node) = 0;

    virtual void visit(const tastr::ast::SymbolTypeNode& node) = 0;

    virtual void visit(const tastr::ast::ExternalPointerTypeNode& node) = 0;

    virtual void visit(const tastr::ast::BytecodeTypeNode& node) = 0;

    virtual void visit(const tastr::ast::PairlistTypeNode& node) = 0;

    virtual void visit(const tastr::ast::S4TypeNode& node) = 0;

    virtual void visit(const tastr::ast::WeakReferenceTypeNode& node) = 0;

    virtual void visit(const tastr::ast::AnyTypeNode& node) = 0;

    virtual void visit(const tastr::ast::UnknownTypeNode& node) = 0;

    virtual void visit(const tastr::ast::CommaSeparatorNode& node) = 0;

    virtual void visit(const tastr::ast::ParameterNode& node) = 0;

    virtual void visit(const tastr::ast::FunctionTypeNode& node) = 0;

    virtual void visit(const tastr::ast::ListTypeNode& node) = 0;

    virtual void visit(const tastr::ast::StructTypeNode& node) = 0;

    virtual void visit(const tastr::ast::TupleTypeNode& node) = 0;

    virtual void visit(const tastr::ast::GroupTypeNode& node) = 0;

    virtual void visit(const tastr::ast::UnionTypeNode& node) = 0;

    virtual void visit(const tastr::ast::VarargTypeNode& node) = 0;

    virtual void visit(const tastr::ast::NullTypeNode& node) = 0;

    virtual void visit(const tastr::ast::NullableTypeNode& node) = 0;

    virtual void visit(const tastr::ast::TagTypePairNode& node) = 0;

    virtual void visit(const tastr::ast::TypeDeclarationNode& node) = 0;

    virtual void visit(const tastr::ast::TopLevelNode& node) = 0;
};

} // namespace tastr::visitor

#endif /* TASTR_VISITOR_CONST_NODE_VISITOR_HPP */
