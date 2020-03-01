#ifndef TASTR_AST_TYPE_DECLARATION_H
#define TASTR_AST_TYPE_DECLARATION_H

#include "ast/IdentifierNode.h"
#include "ast/TypeNode.h"

#include <memory>
#include <string>

namespace tastr::ast {

class TypeDeclarationNode final: public Node {
  public:
    explicit TypeDeclarationNode(std::unique_ptr<IdentifierNode> identifier,
                                 std::unique_ptr<TypeNode> type)
        : Node(), identifier_(std::move(identifier)), type_(std::move(type)) {
    }

    TypeDeclarationNode(const TypeDeclarationNode& node)
        : Node(node)
        , identifier_(node.get_identifier().clone())
        , type_(node.get_type().clone()) {
    }

    ~TypeDeclarationNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<TypeDeclarationNode> clone() const {
        return std::unique_ptr<TypeDeclarationNode>(this->clone_impl());
    }

    const tastr::ast::IdentifierNode& get_identifier() const {
        return *identifier_.get();
    }

    const tastr::ast::TypeNode& get_type() const {
        return *type_.get();
    }

    bool is_type_declaration_node() const override final {
        return true;
    }

  private:
    virtual TypeDeclarationNode* clone_impl() const override final {
        return new TypeDeclarationNode(*this);
    }

    std::unique_ptr<IdentifierNode> identifier_;
    std::unique_ptr<TypeNode> type_;
};

using TypeDeclarationNodePtr = TypeDeclarationNode*;
using TypeDeclarationNodeUPtr = std::unique_ptr<TypeDeclarationNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_DECLARATION_H */