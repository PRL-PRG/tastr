#ifndef TASTR_VISITOR_VISITOR_H
#define TASTR_VISITOR_VISITOR_H

#include "ast.h"

namespace tastr::visitor {

class Visitor {
  public:
    Visitor() {
    }

    virtual ~Visitor() {
    }

    virtual void visit(const tastr::ast::Node& node) = 0;

    virtual void visit(const tastr::ast::Type& node) = 0;

    virtual void visit(const tastr::ast::ScalarType& node) = 0;

    virtual void visit(const tastr::ast::CompositeType& node) = 0;

    virtual void
    visit(const tastr::ast::SequenceType<tastr::ast::Type>& node) = 0;

    virtual void
    visit(const tastr::ast::SequenceType<tastr::ast::TaggedType>& type) = 0;

    virtual void visit(const tastr::ast::TaggedType& node) = 0;

    virtual void visit(const tastr::ast::CharacterType& node) = 0;

    virtual void visit(const tastr::ast::ComplexType& node) = 0;

    virtual void visit(const tastr::ast::DoubleType& node) = 0;

    virtual void visit(const tastr::ast::ParameterType& node) = 0;

    virtual void visit(const tastr::ast::EnvironmentType& node) = 0;

    virtual void visit(const tastr::ast::ExpressionType& node) = 0;

    virtual void visit(const tastr::ast::LanguageType& node) = 0;

    virtual void visit(const tastr::ast::SymbolType& node) = 0;

    virtual void visit(const tastr::ast::Identifier& node) = 0;

    virtual void visit(const tastr::ast::FunctionType& node) = 0;

    virtual void visit(const tastr::ast::GroupType& node) = 0;

    virtual void visit(const tastr::ast::IntegerType& node) = 0;

    virtual void visit(const tastr::ast::ListType& node) = 0;

    virtual void visit(const tastr::ast::LogicalType& node) = 0;

    virtual void visit(const tastr::ast::NoNaType& node) = 0;

    virtual void visit(const tastr::ast::RawType& node) = 0;

    virtual void visit(const tastr::ast::StructType& node) = 0;

    virtual void visit(const tastr::ast::UnionType& node) = 0;

    virtual void visit(const tastr::ast::VectorType& node) = 0;

    virtual void visit(const tastr::ast::VarargType& node) = 0;

    virtual void visit(const tastr::ast::TypeDeclaration& node) = 0;

    virtual void visit(const tastr::ast::TypeDeclarationSequence& node) = 0;
};

} // namespace tastr::visitor

#endif /* TASTR_VISITOR_VISITOR_H */
