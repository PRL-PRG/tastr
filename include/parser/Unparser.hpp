#ifndef TASTR_PARSER_UNPARSER_HPP
#define TASTR_PARSER_UNPARSER_HPP

#include "rang/rang.hpp"
#include "visitor/visitor.hpp"

#include <ostream>

namespace tastr::visitor {

class Unparser final: public ConstNodeVisitor {
  public:
    Unparser(std::ostream& os, bool show_ast, bool style_output)
        : ConstNodeVisitor()
        , os_(os)
        , show_ast_(show_ast)
        , style_output_(style_output) {
    }

    ~Unparser() {
    }

    bool should_show_ast() const {
        return show_ast_;
    }

    bool should_style_output() const {
        return style_output_;
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
        ast_([this, &node] {
            os_ << "^";
            node.get_a_scalar_type().accept(*this);
        });
    }

    void visit(const tastr::ast::IdentifierNode& node) override final {
        if (node.is_quoted()) {
            os_ << "`";
        }

        italic_([this, &node] {
            bright_blue_([this, &node] { os_ << node.get_name(); });
        });

        if (node.is_quoted()) {
            os_ << "`";
        }
    }

    void
    visit(const tastr::ast::CharacterAScalarTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::ComplexAScalarTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::DoubleAScalarTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::IntegerAScalarTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::LogicalAScalarTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::RawAScalarTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::VectorTypeNode& node) override final {
        ast_([this, &node] {
            node.get_scalar_type().accept(*this);
            visit(node.get_operator());
        });
    }

    void visit(const tastr::ast::EnvironmentTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::ExpressionTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::LanguageTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::SymbolTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::ExternalPointerTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::BytecodeTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::PairlistTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::S4TypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::WeakReferenceTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::AnyTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::UnknownTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::FunctionTypeNode& node) override final {
        ast_([this, &node] {
            const tastr::ast::TypeNodeSequenceNode& parameter_types =
                node.get_parameter_types();

            os_ << "<";
            const std::string& separator = parameter_types.get_separator();
            int show_separator = parameter_types.size() - 1;
            for (auto i = parameter_types.cbegin(); i != parameter_types.cend();
                 ++i) {
                (**i).accept(*this);
                if (show_separator) {
                    os_ << separator << " ";
                }
                --show_separator;
            }
            os_ << ">";

            os_ << " ";
            visit(node.get_operator());
            os_ << " ";

            node.get_return_type().accept(*this);
        });
    }

    void visit(const tastr::ast::ListTypeNode& node) override final {
        ast_([this, &node] {
            os_ << node.get_opening_bracket();
            node.get_element_types().accept(*this);
            os_ << node.get_closing_bracket();
        });
    }

    void visit(const tastr::ast::StructTypeNode& node) override final {
        ast_([this, &node] {
            os_ << node.get_opening_bracket();
            node.get_element_types().accept(*this);
            os_ << node.get_closing_bracket();
        });
    }

    void visit(const tastr::ast::TupleTypeNode& node) override final {
        ast_([this, &node] {
            os_ << node.get_opening_bracket();
            node.get_element_types().accept(*this);
            os_ << node.get_closing_bracket();
        });
    }

    void visit(const tastr::ast::GroupTypeNode& node) override final {
        ast_([this, &node] {
            os_ << node.get_opening_bracket();
            node.get_inner_type().accept(*this);
            os_ << node.get_closing_bracket();
        });
    }

    void visit(const tastr::ast::UnionTypeNode& node) override final {
        ast_([this, &node] {
            node.get_first_type().accept(*this);
            os_ << " ";
            visit(node.get_operator());
            os_ << " ";
            node.get_second_type().accept(*this);
        });
    }

    void visit(const tastr::ast::VarargTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::NullTypeNode& node) override final {
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::NullableTypeNode& node) override final {
        ast_([this, &node] {
            visit(node.get_operator());
            node.get_inner_type().accept(*this);
        });
    }

    void visit(const tastr::ast::TypeNodeSequenceNode& node) override final {
        const std::string& separator = node.get_separator();
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            (**i).accept(*this);
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
            (**i).accept(*this);
            if (show_separator) {
                os_ << separator << " ";
            }
            --show_separator;
        }
    }

    void visit(const tastr::ast::TypeDeclarationNode& node) override final {
        visit(node.get_keyword());
        os_ << " ";
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
            (**i).accept(*this);
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
    template <typename T, typename U, typename V>
    void style_(T style_setter, U style_resetter, V code) {
        if (should_style_output()) {
            os_ << style_setter;
        }

        code();

        if (should_style_output()) {
            os_ << style_resetter;
        }
    }

    template <typename V>
    void bright_gray_(V code) {
        style_(rang::fgB::gray, rang::fg::reset, code);
    }

    template <typename V>
    void bright_blue_(V code) {
        style_(rang::fgB::blue, rang::fg::reset, code);
    }

    template <typename V>
    void bright_red_(V code) {
        style_(rang::fgB::red, rang::fg::reset, code);
    }

    template <typename V>
    void bright_green_(V code) {
        style_(rang::fgB::green, rang::fg::reset, code);
    }

    template <typename V>
    void bold_(V code) {
        style_(rang::style::bold, rang::style::reset, code);
    }

    template <typename V>
    void italic_(V code) {
        style_(rang::style::italic, rang::style::reset, code);
    }

    template <typename V>
    void ast_(V code) {
        if (should_show_ast()) {
            bright_gray_([this] { os_ << "«"; });
        }

        code();

        if (should_show_ast()) {
            bright_gray_([this] { os_ << "»"; });
        }
    }

    void visit(const tastr::ast::Keyword& keyword) {
        bright_green_([this, &keyword] { os_ << keyword.get_value(); });
    }

    void visit(const tastr::ast::Operator& op) {
        bright_red_([this, &op] { os_ << op.get_value(); });
    }

    std::ostream& os_;
    bool show_ast_;
    bool style_output_;
};

} // namespace tastr::visitor

#endif /* TASTR_PARSER_UNPARSER_HPP */
