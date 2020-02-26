#ifndef R_TYPE_AST_VISITOR_TYPE_SERIALIZER_H
#define R_TYPE_AST_VISITOR_TYPE_SERIALIZER_H

#include "ast/visitor/TypeVisitor.h"

#include <ostream>

namespace rtype::ast::visitor {

class TypeSerializer: public TypeVisitor {
  public:
    explicit TypeSerializer(std::ostream& os): TypeVisitor(), os_(os) {
    }

    ~TypeSerializer() {
    }

    void visit(const rtype::ast::node::Type& type) override {
        type.accept(*this);
    }

    void visit(const rtype::ast::node::ScalarType& type) override {
        type.accept(*this);
    }

    void visit(const rtype::ast::node::CompositeType& type) override {
        type.accept(*this);
    }

    void visit(const rtype::ast::node::SequenceType<rtype::ast::node::Type>&
                   type) override {
    }

    void visit(
        const rtype::ast::node::SequenceType<rtype::ast::node::NamedType>& type)
        override {
    }

    void visit(const rtype::ast::node::NamedType& type) override {
        os_ << type.get_name();
        os_ << ":";
        type.get_type().accept(*this);
    }

    void visit(const rtype::ast::node::CharacterType& type) override {
        os_ << "character";
    }

    void visit(const rtype::ast::node::ComplexType& type) override {
        os_ << "complex";
    }

    void visit(const rtype::ast::node::DoubleType& type) override {
        os_ << "double";
    }

    void visit(const rtype::ast::node::FunctionType& type) override {
        type.get_parameter_types().accept(*this);
        os_ << " => ";
        type.get_return_type().accept(*this);
    }

    void visit(const rtype::ast::node::ParameterType& type) override {
        os_ << "<";
        int show_separator = type.size() - 1;
        for (auto i = type.cbegin(); i != type.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << ", ";
            }
            --show_separator;
        }
        os_ << ">";
    }

    void visit(const rtype::ast::node::GroupType& type) override {
        os_ << "(";
        type.get_inner_type().accept(*this);
        os_ << ")";
    }

    void visit(const rtype::ast::node::IntegerType& type) override {
        os_ << "integer";
    }

    void visit(const rtype::ast::node::ListType& type) override {
        os_ << "list<";
        int show_separator = type.size() - 1;
        for (auto i = type.cbegin(); i != type.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << ", ";
            }
            --show_separator;
        }
        os_ << ">";
    }

    void visit(const rtype::ast::node::LogicalType& type) override {
        os_ << "logical";
    }

    void visit(const rtype::ast::node::NoNaType& type) override {
        os_ << "!";
        type.get_inner_type().accept(*this);
    }

    void visit(const rtype::ast::node::RawType& type) override {
        os_ << "raw";
    }

    void visit(const rtype::ast::node::StructType& type) override {
        os_ << "struct<";
        int show_separator = type.size() - 1;
        for (auto i = type.cbegin(); i != type.cend(); ++i) {
            os_ << **i;
            if (show_separator) {
                os_ << ", ";
            }
            --show_separator;
        }
        os_ << ">";
    }

    void visit(const rtype::ast::node::UnionType& type) override {
        type.get_first_type().accept(*this);
        os_ << "|";
        type.get_second_type().accept(*this);
    }

    void visit(const rtype::ast::node::VectorType& type) override {
        type.get_scalar_type().accept(*this);
        os_ << "[]";
    }

  private:
    std::ostream& os_;
};

} // namespace rtype::ast::visitor

#endif /* R_TYPE_AST_VISITOR_TYPE_SERIALIZER_H */
