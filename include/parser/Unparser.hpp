#ifndef TASTR_PARSER_UNPARSER_HPP
#define TASTR_PARSER_UNPARSER_HPP

#include "rang/rang.hpp"
#include "visitor/visitor.hpp"

#include <ostream>

namespace tastr {
namespace visitor {

class Unparser final: public ConstNodeVisitor {
  public:
    Unparser(std::ostream& os, bool show_ast, bool style_output)
        : ConstNodeVisitor()
        , os_(os)
        , show_ast_(show_ast)
        , style_output_(style_output)
        , indentation_(0)
        , children_stack_({0})
        , fgb_stack_()
        , style_stack_({rang::style::reset}) {
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
        ast_(node, [this, &node] {
            node.get_operator().accept(*this);
            node.get_a_scalar_type().accept(*this);
        });
    }

    void visit(const tastr::ast::IdentifierNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
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
        ast_(node, [this, &node] {
            bright_green_([this, &node] { os_ << node.get_value(); });
        });
    }

    void visit(const tastr::ast::OperatorNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            bright_red_([this, &node] { os_ << node.get_value(); });
        });
    }

    void visit(const tastr::ast::TerminatorNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            bright_cyan_([this, &node] { os_ << node.get_value(); });
        });
    }

    void visit(const tastr::ast::SeparatorNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            bright_yellow_([this, &node] { os_ << node.get_value(); });
        });
    }

    void visit(const tastr::ast::EmptyNode& node) override final {
        visit_(node.get_location());
        ast_(node, [] {});
    }

    void visit(const tastr::ast::EofNode& node) override final {
        visit_(node.get_location());
        ast_(node, [] {});
    }

    void
    visit(const tastr::ast::CharacterAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::ComplexAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::DoubleAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::IntegerAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::LogicalAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::RawAScalarTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::VectorTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            node.get_scalar_type().accept(*this);
            visit(node.get_operator());
        });
    }

    void visit(const tastr::ast::EnvironmentTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::ExpressionTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::LanguageTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::SymbolTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::ExternalPointerTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::BytecodeTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::PairlistTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::S4TypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::WeakReferenceTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::DataFrameTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::AnyTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::UnknownTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::CommaSeparatorNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            node.get_first_node().accept(*this);
            format_ast_view(" ");
            node.get_separator().accept(*this);
            format_ast_view(" ");
            node.get_second_node().accept(*this);
        });
    }

    void visit(const tastr::ast::ParameterNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            node.get_opening_bracket().accept(*this);
            format_ast_view(" ");
            node.get_elements().accept(*this);
            format_ast_view(" ");
            node.get_closing_bracket().accept(*this);
        });
    }

    void visit(const tastr::ast::FunctionTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            node.get_parameter().accept(*this);
            format_ast_view(" ");
            node.get_operator().accept(*this);
            format_ast_view(" ");
            node.get_return_type().accept(*this);
        });
    }

    void visit(const tastr::ast::ListTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            node.get_keyword().accept(*this);
            node.get_parameters().accept(*this);
        });
    }

    void visit(const tastr::ast::StructTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            node.get_keyword().accept(*this);
            node.get_parameters().accept(*this);
        });
    }

    void visit(const tastr::ast::TupleTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            node.get_keyword().accept(*this);
            node.get_parameters().accept(*this);
        });
    }

    void visit(const tastr::ast::GroupTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            node.get_opening_bracket().accept(*this);
            format_ast_view(" ");
            node.get_inner_type().accept(*this);
            format_ast_view(" ");
            node.get_closing_bracket().accept(*this);
        });
    }

    void visit(const tastr::ast::UnionTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            node.get_first_type().accept(*this);
            format_ast_view(" ");
            visit(node.get_operator());
            format_ast_view(" ");
            node.get_second_type().accept(*this);
        });
    }

    void visit(const tastr::ast::VarargTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::NullTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] { visit(node.get_keyword()); });
    }

    void visit(const tastr::ast::NullableTypeNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            visit(node.get_operator());
            node.get_inner_type().accept(*this);
        });
    }

    void visit(const tastr::ast::TagTypePairNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
            node.get_identifier().accept(*this);
            format_ast_view(" ");
            node.get_separator().accept(*this);
            format_ast_view(" ");
            node.get_type().accept(*this);
        });
    }

    void visit(const tastr::ast::TypeDeclarationNode& node) override final {
        visit_(node.get_location());
        ast_(node, [this, &node] {
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
        ast_(node, [this, &node] {
            for (int index = 0; index < node.size(); ++index) {
                node.at(index).accept(*this);
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

    template <typename V>
    void bright_gray_(V code) {
        color_(rang::fgB::gray, code);
    }

    template <typename V>
    void bright_blue_(V code) {
        color_(rang::fgB::blue, code);
    }

    template <typename V>
    void bright_cyan_(V code) {
        color_(rang::fgB::cyan, code);
    }

    template <typename V>
    void bright_yellow_(V code) {
        color_(rang::fgB::yellow, code);
    }

    template <typename V>
    void bright_red_(V code) {
        color_(rang::fgB::red, code);
    }

    template <typename V>
    void bright_green_(V code) {
        color_(rang::fgB::green, code);
    }

    template <typename V>
    void color_(rang::fgB fgb, V code) {
        if (should_style_output()) {
            set_bright_foreground_(fgb);
        }

        code();

        if (should_style_output()) {
            unset_bright_foreground_();
        }
    }

    template <typename V>
    void style_(rang::style style, V code) {
        if (should_style_output()) {
            set_style_(style);
        }

        code();

        if (should_style_output()) {
            unset_style_();
        }
    }

    template <typename V>
    void bold_(V code) {
        style_(rang::style::bold, code);
    }

    template <typename V>
    void italic_(V code) {
        style_(rang::style::italic, code);
    }

    template <typename V>
    void ast_(const Node& node, V code) {
        if (should_show_ast()) {
            bright_gray_([this, &node] {
                ++children_stack_.back();
                os_ << std::endl;
                indent_();
                os_ << rang::style::reset << node.get_kind() << "❰";
                increase_indentation_();
                children_stack_.push_back(0);
            });
        }

        if (should_show_ast()) {
            bold_([&code] { code(); });
        } else {
            code();
        }

        if (should_show_ast()) {
            fix_previous_indentation_();
            decrease_indentation_();
            if (children_stack_.back()) {
                os_ << std::endl;
                indent_();
            }
            children_stack_.pop_back();
            bright_gray_([this] { os_ << "❱"; });
        }
    }

    void increase_indentation_() {
        ++indentation_;
    }

    void decrease_indentation_() {
        --indentation_;
    }

    void fix_previous_indentation_() {
        if (children_stack_.back() == 0) {
            return;
        }

        os_ << "\r";
        for (int i = 0; i < indentation_ - 1; ++i) {
            os_ << "│   ";
        }

        if (indentation_) {
            os_ << "└── ";
        }
    }

    void indent_() {
        for (int i = 0; i < indentation_ - 1; ++i) {
            os_ << "│   ";
        }

        if (indentation_) {
            os_ << "├── ";
        }
    }

    void format_ast_view(const std::string& formatting = "") {
        return;
        if (should_show_ast()) {
            os_ << formatting;
        }
    }

    void set_bright_foreground_(rang::fgB fgb) {
        os_ << fgb;
        fgb_stack_.push_back(fgb);
    }

    void unset_bright_foreground_() {
        if (fgb_stack_.size()) {
            fgb_stack_.pop_back();
            os_ << fgb_stack_.back();
        }
    }

    void set_style_(rang::style style) {
        os_ << style;
        style_stack_.push_back(style);
    }

    void unset_style_() {
        if (style_stack_.size()) {
            style_stack_.pop_back();
            os_ << style_stack_.back();
        }
    }

    std::ostream& os_;
    bool show_ast_;
    bool style_output_;
    int indentation_;
    std::vector<int> children_stack_;
    std::vector<rang::fgB> fgb_stack_;
    std::vector<rang::style> style_stack_;
};

} // namespace visitor
} // namespace tastr

#endif /* TASTR_PARSER_UNPARSER_HPP */
