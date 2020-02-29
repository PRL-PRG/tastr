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

    void visit(const tastr::ast::Type& node) override final {
        node.accept(*this);
    }

    void visit(const tastr::ast::ScalarType& node) override final {
        node.accept(*this);
    }

    void visit(const tastr::ast::CompositeType& node) override final {
        node.accept(*this);
    }

    void visit(const tastr::ast::SequenceType<tastr::ast::Type>&
                   type) override final {
    }

    void
    visit(const tastr::ast::SequenceType<tastr::ast::TaggedType>&
              node) override final {
    }

    void visit(const tastr::ast::TaggedType& node) override final {
        node.get_identifier().accept(*this);
        os_ << ":";
        node.get_type().accept(*this);
    }

    void visit(const tastr::ast::CharacterType& node) override final {
        os_ << "character";
    }

    void visit(const tastr::ast::EnvironmentType& node) override final {
        os_ << "environment";
    }

    void visit(const tastr::ast::ExpressionType& node) override final {
        os_ << "expression";
    }

    void visit(const tastr::ast::LanguageType& node) override final {
        os_ << "language";
    }

    void visit(const tastr::ast::SymbolType& node) override final {
        os_ << "symbol";
    }

    void visit(const tastr::ast::ComplexType& node) override final {
        os_ << "complex";
    }

    void visit(const tastr::ast::DoubleType& node) override final {
        os_ << "double";
    }

    void visit(const tastr::ast::FunctionType& node) override final {
        node.get_parameter_types().accept(*this);
        os_ << " => ";
        node.get_return_type().accept(*this);
    }

    void visit(const tastr::ast::ParameterType& node) override final {
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

    void visit(const tastr::ast::GroupType& node) override final {
        os_ << "(";
        node.get_inner_type().accept(*this);
        os_ << ")";
    }

    void visit(const tastr::ast::IntegerType& node) override final {
        os_ << "integer";
    }

    void visit(const tastr::ast::ListType& node) override final {
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

    void visit(const tastr::ast::LogicalType& node) override final {
        os_ << "logical";
    }

    void visit(const tastr::ast::NoNaType& node) override final {
        os_ << "!";
        node.get_inner_type().accept(*this);
    }

    void visit(const tastr::ast::RawType& node) override final {
        os_ << "raw";
    }

    void visit(const tastr::ast::StructType& node) override final {
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

    void visit(const tastr::ast::UnionType& node) override final {
        node.get_first_type().accept(*this);
        os_ << "|";
        node.get_second_type().accept(*this);
    }

    void visit(const tastr::ast::VectorType& node) override final {
        node.get_scalar_type().accept(*this);
        os_ << "[]";
    }

    void visit(const tastr::ast::TypeDeclaration& node) override final {
        os_ << "type ";
        node.get_identifier().accept(*this);
        os_ << " ";
        node.get_type().accept(*this);
        os_ << ";";
    }

    void visit(
        const tastr::ast::TypeDeclarationSequence& node) override final {
        int show_separator = node.size() - 1;
        for (auto i = node.cbegin(); i != node.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << std::endl;
            }
            --show_separator;
        }
    }

    void visit(const tastr::ast::Identifier& node) override final {
        os_ << node.get_name();
    }

    void visit(const tastr::ast::VarargType& node) override final {
        os_ << "...";
    }

  private:
    std::ostream& os_;
};

} // namespace tastr::visitor

#endif /* TASTR_VISITOR_UNPARSER_H */
