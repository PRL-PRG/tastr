#ifndef TASTR_VISITOR_UNPARSER_H
#define TASTR_VISITOR_UNPARSER_H

#include "visitor/Visitor.h"

#include <ostream>

namespace tastr::visitor {

class Unparser final: public Visitor {
  public:
    explicit Unparser(std::ostream& os): Visitor(), os_(os) {
    }

    ~Unparser() {
    }

    void visit(const tastr::ast::Node& node) override final {
        node.accept(*this);
    }

    void visit(const tastr::ast::TypeNode& node) override final {
        node.accept(*this);
    }

    void visit(const tastr::ast::ScalarTypeNode& node) override final {
        node.accept(*this);
    }

    void visit(const tastr::ast::CompositeTypeNode& node) override final {
        node.accept(*this);
    }

    void visit(
        const tastr::ast::SequenceTypeNode<tastr::ast::TypeNode>& type) override final {
    }

    void visit(const tastr::ast::SequenceTypeNode<tastr::ast::TaggedTypeNode>& node)
        override final {
    }

    void visit(const tastr::ast::TaggedTypeNode& node) override final {
        node.get_identifier().accept(*this);
        os_ << ":";
        node.get_type().accept(*this);
    }

    void visit(const tastr::ast::CharacterTypeNode& node) override final {
        os_ << "character";
    }

    void visit(const tastr::ast::EnvironmentTypeNode& node) override final {
        os_ << "environment";
    }

    void visit(const tastr::ast::ExpressionTypeNode& node) override final {
        os_ << "expression";
    }

    void visit(const tastr::ast::LanguageTypeNode& node) override final {
        os_ << "language";
    }

    void visit(const tastr::ast::SymbolTypeNode& node) override final {
        os_ << "symbol";
    }

    void visit(const tastr::ast::ComplexTypeNode& node) override final {
        os_ << "complex";
    }

    void visit(const tastr::ast::DoubleTypeNode& node) override final {
        os_ << "double";
    }

    void visit(const tastr::ast::FunctionTypeNode& node) override final {
        node.get_parameter_types().accept(*this);
        os_ << " => ";
        node.get_return_type().accept(*this);
    }

    void visit(const tastr::ast::ParameterTypeNode& node) override final {
        os_ << "<";
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << ", ";
            }
            --show_separator;
        }
        os_ << ">";
    }

    void visit(const tastr::ast::GroupTypeNode& node) override final {
        os_ << "(";
        node.get_inner_type().accept(*this);
        os_ << ")";
    }

    void visit(const tastr::ast::IntegerTypeNode& node) override final {
        os_ << "integer";
    }

    void visit(const tastr::ast::ListTypeNode& node) override final {
        os_ << "((";
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << ", ";
            }
            --show_separator;
        }
        os_ << "))";
    }

    void visit(const tastr::ast::LogicalTypeNode& node) override final {
        os_ << "logical";
    }

    void visit(const tastr::ast::NoNaTypeNode& node) override final {
        os_ << "!";
        node.get_inner_type().accept(*this);
    }

    void visit(const tastr::ast::RawTypeNode& node) override final {
        os_ << "raw";
    }

    void visit(const tastr::ast::StructTypeNode& node) override final {
        os_ << "{{";
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << ", ";
            }
            --show_separator;
        }
        os_ << "}}";
    }

    void visit(const tastr::ast::UnionTypeNode& node) override final {
        node.get_first_type().accept(*this);
        os_ << "|";
        node.get_second_type().accept(*this);
    }

    void visit(const tastr::ast::VectorTypeNode& node) override final {
        node.get_scalar_type().accept(*this);
        os_ << "[]";
    }

    void visit(const tastr::ast::TypeDeclarationNode& node) override final {
        os_ << "type ";
        node.get_identifier().accept(*this);
        os_ << " ";
        node.get_type().accept(*this);
        os_ << ";";
    }

    void
    visit(const tastr::ast::TypeDeclarationSequenceNode& node) override final {
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << std::endl;
            }
            --show_separator;
        }
    }

    void visit(const tastr::ast::IdentifierNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::VarargTypeNode& node) override final {
        os_ << "...";
    }

  private:
    std::ostream& os_;
};

} // namespace tastr::visitor

#endif /* TASTR_VISITOR_UNPARSER_H */
