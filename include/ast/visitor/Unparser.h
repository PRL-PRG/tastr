#ifndef R_TYPE_AST_VISITOR_UNPARSER_H
#define R_TYPE_AST_VISITOR_UNPARSER_H

#include "ast/visitor/Visitor.h"

#include <ostream>

namespace rtype::ast::visitor {

class Unparser: public Visitor {
  public:
    explicit Unparser(std::ostream& os): Visitor(), os_(os) {
    }

    ~Unparser() {
    }

    void visit(const rtype::ast::node::Node& node) override {
        node.accept(*this);
    }

    void visit(const rtype::ast::node::Type& node) override {
        node.accept(*this);
    }

    void visit(const rtype::ast::node::ScalarType& node) override {
        node.accept(*this);
    }

    void visit(const rtype::ast::node::CompositeType& node) override {
        node.accept(*this);
    }

    void visit(const rtype::ast::node::SequenceType<rtype::ast::node::Type>&
                   type) override {
    }

    void visit(
        const rtype::ast::node::SequenceType<rtype::ast::node::NamedType>& node)
        override {
    }

    void visit(const rtype::ast::node::NamedType& node) override {
        os_ << node.get_name();
        os_ << ":";
        node.get_type().accept(*this);
    }

    void visit(const rtype::ast::node::CharacterType& node) override {
        os_ << "character";
    }

    void visit(const rtype::ast::node::ComplexType& node) override {
        os_ << "complex";
    }

    void visit(const rtype::ast::node::DoubleType& node) override {
        os_ << "double";
    }

    void visit(const rtype::ast::node::FunctionType& node) override {
        node.get_parameter_types().accept(*this);
        os_ << " => ";
        node.get_return_type().accept(*this);
    }

    void visit(const rtype::ast::node::ParameterType& node) override {
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

    void visit(const rtype::ast::node::GroupType& node) override {
        os_ << "(";
        node.get_inner_type().accept(*this);
        os_ << ")";
    }

    void visit(const rtype::ast::node::IntegerType& node) override {
        os_ << "integer";
    }

    void visit(const rtype::ast::node::ListType& node) override {
        os_ << "list<";
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

    void visit(const rtype::ast::node::LogicalType& node) override {
        os_ << "logical";
    }

    void visit(const rtype::ast::node::NoNaType& node) override {
        os_ << "!";
        node.get_inner_type().accept(*this);
    }

    void visit(const rtype::ast::node::RawType& node) override {
        os_ << "raw";
    }

    void visit(const rtype::ast::node::StructType& node) override {
        os_ << "struct<";
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

    void visit(const rtype::ast::node::UnionType& node) override {
        node.get_first_type().accept(*this);
        os_ << "|";
        node.get_second_type().accept(*this);
    }

    void visit(const rtype::ast::node::VectorType& node) override {
        node.get_scalar_type().accept(*this);
        os_ << "[]";
    }

    void visit(const rtype::ast::node::TypeDeclaration& node) override {
        os_ << "type ";
        os_ << node.get_identifier() << " ";
        node.get_type().accept(*this);
        os_ << ";\n";
    }

  private:
    std::ostream& os_;
};

} // namespace rtype::ast::visitor

#endif /* R_TYPE_AST_VISITOR_UNPARSER_H */
