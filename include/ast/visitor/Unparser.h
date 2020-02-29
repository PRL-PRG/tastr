#ifndef R_TYPE_AST_VISITOR_UNPARSER_H
#define R_TYPE_AST_VISITOR_UNPARSER_H

#include "ast/visitor/Visitor.h"

#include <ostream>

namespace rtype::ast::visitor {

class Unparser final: public Visitor {
  public:
    explicit Unparser(std::ostream& os): Visitor(), os_(os) {
    }

    ~Unparser() {
    }

    void visit(const rtype::ast::node::Node& node) override final {
        node.accept(*this);
    }

    void visit(const rtype::ast::node::Type& node) override final {
        node.accept(*this);
    }

    void visit(const rtype::ast::node::ScalarType& node) override final {
        node.accept(*this);
    }

    void visit(const rtype::ast::node::CompositeType& node) override final {
        node.accept(*this);
    }

    void visit(const rtype::ast::node::SequenceType<rtype::ast::node::Type>&
                   type) override final {
    }

    void
    visit(const rtype::ast::node::SequenceType<rtype::ast::node::TaggedType>&
              node) override final {
    }

    void visit(const rtype::ast::node::TaggedType& node) override final {
        node.get_identifier().accept(*this);
        os_ << ":";
        node.get_type().accept(*this);
    }

    void visit(const rtype::ast::node::CharacterType& node) override final {
        os_ << "character";
    }

    void visit(const rtype::ast::node::EnvironmentType& node) override final {
        os_ << "environment";
    }

    void visit(const rtype::ast::node::ExpressionType& node) override final {
        os_ << "expression";
    }

    void visit(const rtype::ast::node::LanguageType& node) override final {
        os_ << "language";
    }

    void visit(const rtype::ast::node::SymbolType& node) override final {
        os_ << "symbol";
    }

    void visit(const rtype::ast::node::ComplexType& node) override final {
        os_ << "complex";
    }

    void visit(const rtype::ast::node::DoubleType& node) override final {
        os_ << "double";
    }

    void visit(const rtype::ast::node::FunctionType& node) override final {
        node.get_parameter_types().accept(*this);
        os_ << " => ";
        node.get_return_type().accept(*this);
    }

    void visit(const rtype::ast::node::ParameterType& node) override final {
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

    void visit(const rtype::ast::node::GroupType& node) override final {
        os_ << "(";
        node.get_inner_type().accept(*this);
        os_ << ")";
    }

    void visit(const rtype::ast::node::IntegerType& node) override final {
        os_ << "integer";
    }

    void visit(const rtype::ast::node::ListType& node) override final {
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

    void visit(const rtype::ast::node::LogicalType& node) override final {
        os_ << "logical";
    }

    void visit(const rtype::ast::node::NoNaType& node) override final {
        os_ << "!";
        node.get_inner_type().accept(*this);
    }

    void visit(const rtype::ast::node::RawType& node) override final {
        os_ << "raw";
    }

    void visit(const rtype::ast::node::StructType& node) override final {
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

    void visit(const rtype::ast::node::UnionType& node) override final {
        node.get_first_type().accept(*this);
        os_ << "|";
        node.get_second_type().accept(*this);
    }

    void visit(const rtype::ast::node::VectorType& node) override final {
        node.get_scalar_type().accept(*this);
        os_ << "[]";
    }

    void visit(const rtype::ast::node::TypeDeclaration& node) override final {
        os_ << "type ";
        node.get_identifier().accept(*this);
        os_ << " ";
        node.get_type().accept(*this);
        os_ << ";";
    }

    void visit(
        const rtype::ast::node::TypeDeclarationSequence& node) override final {
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << std::endl;
            }
            --show_separator;
        }
    }

    void visit(const rtype::ast::node::Identifier& node) override final {
        os_ << node.get_name();
    }

  private:
    std::ostream& os_;
};

} // namespace rtype::ast::visitor

#endif /* R_TYPE_AST_VISITOR_UNPARSER_H */
