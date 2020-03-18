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
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_operator().accept(*this);
            node.get_a_scalar_type().accept(*this);
        });
    }

    void visit(const tastr::ast::IdentifierNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            if (node.is_quoted()) {
                os_ << "`";
            }

            italic_([this, &node] {
                bright_blue_([this, &node] { os_ << node.get_name(); });
            });

            if (node.is_quoted()) {
                os_ << "`";
            }
        });
    }

    void visit(const tastr::ast::KeywordNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            bright_green_([this, &node] { os_ << node.get_value(); });
        });
    }

    void visit(const tastr::ast::OperatorNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            bright_red_([this, &node] { os_ << node.get_value(); });
        });
    }

    void visit(const tastr::ast::TerminatorNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            bright_red_([this, &node] { os_ << node.get_value(); });
        });
    }

    void visit(const tastr::ast::SeparatorNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            bright_red_([this, &node] { os_ << node.get_value(); });
        });
    }

    void visit(const tastr::ast::EmptyNode& node) override final {
        visit_(node.get_location());
        ast_([] {});
    }

    void visit(const tastr::ast::EofNode& node) override final {
        visit_(node.get_location());
        ast_([] {});
    }

    void
    visit(const tastr::ast::CharacterAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::ComplexAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::DoubleAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::IntegerAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::LogicalAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::RawAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::VectorTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_scalar_type().accept(*this);
            visit(node.get_operator());
        });
    }

    void visit(const tastr::ast::EnvironmentTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::ExpressionTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::LanguageTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::SymbolTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::ExternalPointerTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::BytecodeTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::PairlistTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::S4TypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::WeakReferenceTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::AnyTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::UnknownTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::CommaSeparatorNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_first_node().accept(*this);
            format_ast_view(" ");
            node.get_separator().accept(*this);
            format_ast_view(" ");
            node.get_second_node().accept(*this);
        });
    }

    void visit(const tastr::ast::ParameterNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_opening_bracket().accept(*this);
            format_ast_view(" ");
            node.get_elements().accept(*this);
            format_ast_view(" ");
            node.get_closing_bracket().accept(*this);
        });
    }

    void visit(const tastr::ast::FunctionTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_parameter().accept(*this);
            format_ast_view(" ");
            node.get_operator().accept(*this);
            format_ast_view(" ");
            node.get_return_type().accept(*this);
        });
    }

    void visit(const tastr::ast::ListTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_keyword().accept(*this);
            node.get_parameters().accept(*this);
        });
    }

    void visit(const tastr::ast::StructTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_keyword().accept(*this);
            node.get_parameters().accept(*this);
        });
    }

    void visit(const tastr::ast::TupleTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_keyword().accept(*this);
            node.get_parameters().accept(*this);
        });
    }

    void visit(const tastr::ast::GroupTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_opening_bracket().accept(*this);
            format_ast_view(" ");
            node.get_inner_type().accept(*this);
            format_ast_view(" ");
            node.get_closing_bracket().accept(*this);
        });
    }

    void visit(const tastr::ast::UnionTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_first_type().accept(*this);
            format_ast_view(" ");
            visit(node.get_operator());
            format_ast_view(" ");
            node.get_second_type().accept(*this);
        });
    }

    void visit(const tastr::ast::VarargTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::NullTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::NullableTypeNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            visit(node.get_operator());
            node.get_inner_type().accept(*this);
        });
    }

    void visit(const tastr::ast::TagTypePairNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            node.get_identifier().accept(*this);
            format_ast_view(" ");
            node.get_separator().accept(*this);
            format_ast_view(" ");
            node.get_type().accept(*this);
        });
    }

    void visit(const tastr::ast::TypeDeclarationNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            visit(node.get_keyword());
            format_ast_view(" ");
            node.get_identifier().accept(*this);
            format_ast_view(" ");
            node.get_type().accept(*this);
            format_ast_view(" ");
            node.get_terminator().accept(*this);
        });
    }

    void visit(const tastr::ast::TopLevelNode& node) override final {
        visit_(node.get_location());
        ast_([this, &node] {
            for (int index = 0; index < node.size(); ++index) {
                node.at(index).accept(*this);
                format_ast_view("\n");
            }
            node.get_eof_node().accept(*this);
        });
    }

  private:
    void visit_(const tastr::parser::Location& node) {
        if (!should_show_ast()) {
            bright_gray_([this, &node] { os_ << node.get_prefix(); });
        }
    }

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
            bright_gray_([this] { os_ << "❬"; });
        }

        code();

        if (should_show_ast()) {
            bright_gray_([this] { os_ << "❭"; });
        }
    }

    void format_ast_view(const std::string& formatting = "") {
        if (should_show_ast()) {
            os_ << formatting;
        }
    }

    std::ostream& os_;
    bool show_ast_;
    bool style_output_;
};

} // namespace tastr::visitor

#endif /* TASTR_PARSER_UNPARSER_HPP */
