#ifndef TASTR_VISITOR_MUTABLE_VISITOR_HPP
#define TASTR_VISITOR_MUTABLE_VISITOR_HPP

#include "ast/ast.hpp"

namespace tastr {
namespace visitor {

class MutableNodeVisitor {
  public:
    MutableNodeVisitor() {
    }

    virtual ~MutableNodeVisitor() = default;

    virtual void visit(tastr::ast::Node& node) {
        node.accept(*this);
    }

    virtual void visit(tastr::ast::TypeNode& node) {
        node.accept(*this);
    }

    virtual void visit(tastr::ast::ScalarTypeNode& node) {
        node.accept(*this);
    }

    virtual void visit(tastr::ast::AScalarTypeNode& node) {
        node.accept(*this);
    }

    virtual void visit(tastr::ast::NAScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::IdentifierNode& node) = 0;

    virtual void visit(tastr::ast::KeywordNode& node) = 0;

    virtual void visit(tastr::ast::OperatorNode& node) = 0;

    virtual void visit(tastr::ast::TerminatorNode& node) = 0;

    virtual void visit(tastr::ast::SeparatorNode& node) = 0;

    virtual void visit(tastr::ast::EmptyNode& node) = 0;

    virtual void visit(tastr::ast::EofNode& node) = 0;

    virtual void visit(tastr::ast::CharacterAScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::ComplexAScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::DoubleAScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::IntegerAScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::LogicalAScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::RawAScalarTypeNode& node) = 0;

    virtual void visit(tastr::ast::VectorTypeNode& node) = 0;

    virtual void visit(tastr::ast::ClassTypeNode& node) = 0;

    virtual void visit(tastr::ast::EnvironmentTypeNode& node) = 0;

    virtual void visit(tastr::ast::ExpressionTypeNode& node) = 0;

    virtual void visit(tastr::ast::LanguageTypeNode& node) = 0;

    virtual void visit(tastr::ast::SymbolTypeNode& node) = 0;

    virtual void visit(tastr::ast::ExternalPointerTypeNode& node) = 0;

    virtual void visit(tastr::ast::BytecodeTypeNode& node) = 0;

    virtual void visit(tastr::ast::PairlistTypeNode& node) = 0;

    virtual void visit(tastr::ast::S4TypeNode& node) = 0;

    virtual void visit(tastr::ast::WeakReferenceTypeNode& node) = 0;

    virtual void visit(tastr::ast::DataFrameTypeNode& node) = 0;

    virtual void visit(tastr::ast::AnyTypeNode& node) = 0;

    virtual void visit(tastr::ast::UnknownTypeNode& node) = 0;

    virtual void visit(tastr::ast::CommaSeparatorNode& node) = 0;

    virtual void visit(tastr::ast::ParameterNode& node) = 0;

    virtual void visit(tastr::ast::FunctionTypeNode& node) = 0;

    virtual void visit(tastr::ast::ListTypeNode& node) = 0;

    virtual void visit(tastr::ast::StructTypeNode& node) = 0;

    virtual void visit(tastr::ast::TupleTypeNode& node) = 0;

    virtual void visit(tastr::ast::GroupTypeNode& node) = 0;

    virtual void visit(tastr::ast::UnionTypeNode& node) = 0;

    virtual void visit(tastr::ast::IntersectionTypeNode& node) = 0;

    virtual void visit(tastr::ast::VarargTypeNode& node) = 0;

    virtual void visit(tastr::ast::NullTypeNode& node) = 0;

    virtual void visit(tastr::ast::NullableTypeNode& node) = 0;

    virtual void visit(tastr::ast::TagTypePairNode& node) = 0;

    virtual void visit(tastr::ast::TypeDeclarationNode& node) = 0;

    virtual void visit(tastr::ast::TopLevelNode& node) = 0;
};

} // namespace visitor
} // namespace tastr

#endif /* TASTR_VISITOR_MUTABLE_VISITOR_HPP */
