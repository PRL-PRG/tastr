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

    void visit(const tastr::ast::TagTypePairNode& node) override final {
        node.get_identifier().accept(*this);
        os_ << ":";
        node.get_type().accept(*this);
    }

    void visit(const tastr::ast::CharacterScalarTypeNode& node) override final {
        os_ << node.get_identifier();
    }

    void visit(const tastr::ast::EnvironmentTypeNode& node) override final {
        os_ << node.get_identifier();
    }

    void visit(const tastr::ast::ExpressionTypeNode& node) override final {
        os_ << node.get_identifier();
    }

    void visit(const tastr::ast::LanguageTypeNode& node) override final {
        os_ << node.get_identifier();
    }

    void visit(const tastr::ast::SymbolTypeNode& node) override final {
        os_ << node.get_identifier();
    }

    void visit(const tastr::ast::ComplexScalarTypeNode& node) override final {
        os_ << node.get_identifier();
    }

    void visit(const tastr::ast::DoubleScalarTypeNode& node) override final {
        os_ << node.get_identifier();
    }

    void visit(const tastr::ast::FunctionTypeNode& node) override final {
        const tastr::ast::TypeNodeSequenceNode& parameter_types =
            node.get_parameter_types();

        os_ << "<";
        int show_separator = parameter_types.size() - 1;
        for (auto i = parameter_types.cbegin(); i != parameter_types.cend();
             ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << ", ";
            }
            --show_separator;
        }
        os_ << ">";

        os_ << " => ";
        node.get_return_type().accept(*this);
    }

    void visit(const tastr::ast::GroupTypeNode& node) override final {
        os_ << "(";
        node.get_inner_type().accept(*this);
        os_ << ")";
    }

    void visit(const tastr::ast::IntegerScalarTypeNode& node) override final {
        os_ << node.get_identifier();
    }

    void visit(const tastr::ast::ListTypeNode& node) override final {
        os_ << "((";
        node.get_element_types().accept(*this);
        os_ << "))";
    }

    void visit(const tastr::ast::LogicalScalarTypeNode& node) override final {
        os_ << node.get_identifier();
    }

    void visit(const tastr::ast::NoNaTypeNode& node) override final {
        os_ << "!";
        node.get_inner_type().accept(*this);
    }

    void visit(const tastr::ast::RawScalarTypeNode& node) override final {
        os_ << node.get_identifier();
    }

    void visit(const tastr::ast::StructTypeNode& node) override final {
        os_ << "{{";
        node.get_element_types().accept(*this);
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

    void visit(const tastr::ast::TopLevelNode& node) override final {
        node.get_type_declarations().accept(*this);
    }

    void visit(const tastr::ast::IdentifierNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::VarargTypeNode& node) override final {
        os_ << "...";
    }

    void visit(const tastr::ast::TypeNodeSequenceNode& node) override final {
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << ", ";
            }
            --show_separator;
        }
    }

    void
    visit(const tastr::ast::TagTypePairNodeSequenceNode& node) override final {
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << ", ";
            }
            --show_separator;
        }
    }

    void visit(const tastr::ast::TypeDeclarationNodeSequenceNode& node)
        override final {
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << std::endl;
            }
            --show_separator;
        }
    }

  private:
    std::ostream& os_;
};

} // namespace tastr::visitor

#endif /* TASTR_VISITOR_UNPARSER_H */
