#ifndef TASTR_PARSER_UNPARSER_HPP
#define TASTR_PARSER_UNPARSER_HPP

#include "visitor/visitor.hpp"

#include <ostream>

namespace tastr::visitor {

class Unparser final: public ConstNodeVisitor {
  public:
    explicit Unparser(std::ostream& os): ConstNodeVisitor(), os_(os) {
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

    void visit(const tastr::ast::AScalarTypeNode& node) override final {
        node.accept(*this);
    }

    void visit(const tastr::ast::NAScalarTypeNode& node) override final {
        os_ << "^";
        node.get_a_scalar_type().accept(*this);
    }

    void visit(const tastr::ast::IdentifierNode& node) override final {
        os_ << node.get_name();
    }

    void
    visit(const tastr::ast::CharacterAScalarTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::ComplexAScalarTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::DoubleAScalarTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::IntegerAScalarTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::LogicalAScalarTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::RawAScalarTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::VectorTypeNode& node) override final {
        node.get_scalar_type().accept(*this);
        os_ << "[]";
    }

    void visit(const tastr::ast::EnvironmentTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::ExpressionTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::LanguageTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::SymbolTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::ExternalPointerTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::BytecodeTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::PairlistTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::S4TypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::WeakReferenceTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::AnyTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::UnknownTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::FunctionTypeNode& node) override final {
        const tastr::ast::TypeNodeSequenceNode& parameter_types =
            node.get_parameter_types();

        os_ << "<";
        const std::string& separator = parameter_types.get_separator();
        int show_separator = parameter_types.size() - 1;
        for (auto i = parameter_types.cbegin(); i != parameter_types.cend();
             ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << separator << " ";
            }
            --show_separator;
        }
        os_ << ">";

        os_ << " " << node.get_separator() << " ";
        node.get_return_type().accept(*this);
    }

    void visit(const tastr::ast::ListTypeNode& node) override final {
        os_ << node.get_opening_bracket();
        node.get_element_types().accept(*this);
        os_ << node.get_closing_bracket();
    }

    void visit(const tastr::ast::StructTypeNode& node) override final {
        os_ << node.get_opening_bracket();
        node.get_element_types().accept(*this);
        os_ << node.get_closing_bracket();
    }

    void visit(const tastr::ast::TupleTypeNode& node) override final {
        os_ << node.get_opening_bracket();
        node.get_element_types().accept(*this);
        os_ << node.get_closing_bracket();
    }

    void visit(const tastr::ast::GroupTypeNode& node) override final {
        os_ << node.get_opening_bracket();
        node.get_inner_type().accept(*this);
        os_ << node.get_closing_bracket();
    }

    void visit(const tastr::ast::UnionTypeNode& node) override final {
        node.get_first_type().accept(*this);
        os_ << " " << node.get_separator() << " ";
        node.get_second_type().accept(*this);
    }

    void visit(const tastr::ast::VarargTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::NullTypeNode& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::NullableTypeNode& node) override final {
        os_ << node.get_name();
        node.get_inner_type().accept(*this);
    }

    void visit(const tastr::ast::TypeNodeSequenceNode& node) override final {
        const std::string& separator = node.get_separator();
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << separator << " ";
            }
            --show_separator;
        }
    }

    void visit(const tastr::ast::TagTypePairNode& node) override final {
        node.get_identifier().accept(*this);
        os_ << " " << node.get_separator() << " ";
        node.get_type().accept(*this);
    }

    void
    visit(const tastr::ast::TagTypePairNodeSequenceNode& node) override final {
        const std::string& separator = node.get_separator();
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << separator << " ";
            }
            --show_separator;
        }
    }

    void visit(const tastr::ast::TypeDeclarationNode& node) override final {
        os_ << "type ";
        node.get_identifier().accept(*this);
        os_ << " ";
        node.get_type().accept(*this);
        os_ << ";";
    }

    void visit(const tastr::ast::TypeDeclarationNodeSequenceNode& node)
        override final {
        const std::string& separator = node.get_separator();
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << separator;
            }
            --show_separator;
        }
    }

    void visit(const tastr::ast::TopLevelNode& node) override final {
        node.get_type_declarations().accept(*this);
    }

  private:
    std::ostream& os_;
};

} // namespace tastr::visitor

#endif /* TASTR_PARSER_UNPARSER_HPP */
