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
        os_ << node.get_location().get_token_prefix();
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
        os_ << node.get_location().get_token_prefix();
        bright_green_([this, &node] { os_ << node.get_value(); });
    }

    void visit(const tastr::ast::OperatorNode& node) override final {
        os_ << node.get_location().get_token_prefix();
        bright_red_([this, &node] { os_ << node.get_value(); });
    }

    void visit(const tastr::ast::TerminatorNode& node) override final {
        os_ << node.get_location().get_token_prefix();
        bright_red_([this, &node] { os_ << node.get_value(); });
    }

    void visit(const tastr::ast::SeparatorNode& node) override final {
        os_ << node.get_location().get_token_prefix();
        bright_red_([this, &node] { os_ << node.get_value(); });
    }

    void visit(const tastr::ast::EmptyNode& node) override final {
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

    void visit(const tastr::ast::CommaSeparatorNode& node) override final {
        ast_([this, &node] {
            node.get_first_node().accept(*this);
            node.get_separator().accept(*this);
            node.get_second_node().accept(*this);
        });
    }

    void visit(const tastr::ast::ParameterNode& node) override final {
        ast_([this, &node] {
            node.get_opening_bracket().accept(*this);
            node.get_elements().accept(*this);
            node.get_closing_bracket().accept(*this);
        });
    }

    void visit(const tastr::ast::FunctionTypeNode& node) override final {
        ast_([this, &node] {
            node.get_parameter().accept(*this);
            node.get_operator().accept(*this);
            node.get_return_type().accept(*this);
        });
    }

    void visit(const tastr::ast::ListTypeNode& node) override final {
        ast_([this, &node] {
            node.get_opening_bracket().accept(*this);
            node.get_elements().accept(*this);
            node.get_closing_bracket().accept(*this);
        });
    }

    void visit(const tastr::ast::StructTypeNode& node) override final {
        ast_([this, &node] {
            node.get_opening_bracket().accept(*this);
            node.get_elements().accept(*this);
            node.get_closing_bracket().accept(*this);
        });
    }

    void visit(const tastr::ast::TupleTypeNode& node) override final {
        ast_([this, &node] {
            node.get_opening_bracket().accept(*this);
            node.get_elements().accept(*this);
            node.get_closing_bracket().accept(*this);
        });
    }

    void visit(const tastr::ast::GroupTypeNode& node) override final {
        ast_([this, &node] {
            node.get_opening_bracket().accept(*this);
            node.get_inner_type().accept(*this);
            node.get_closing_bracket().accept(*this);
        });
    }

    void visit(const tastr::ast::UnionTypeNode& node) override final {
        ast_([this, &node] {
            node.get_first_type().accept(*this);
            visit(node.get_operator());
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

    void visit(const tastr::ast::TagTypePairNode& node) override final {
        ast_([this, &node] {
            node.get_identifier().accept(*this);
            node.get_separator().accept(*this);
            node.get_type().accept(*this);
        });
    }

    void visit(const tastr::ast::TypeDeclarationNode& node) override final {
        ast_([this, &node] {
            visit(node.get_keyword());
            node.get_identifier().accept(*this);
            node.get_type().accept(*this);
            os_ << ";";
        });
    }

    void visit(const tastr::ast::TopLevelNode& node) override final {
        ast_([this, &node] {
            for (int index = 0; index < node.size(); ++index) {
                node.at(index).accept(*this);
            }
        });
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

    std::ostream& os_;
    bool show_ast_;
    bool style_output_;
};

} // namespace tastr::visitor

#endif /* TASTR_PARSER_UNPARSER_HPP */
