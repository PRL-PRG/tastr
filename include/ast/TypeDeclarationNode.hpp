#ifndef TASTR_AST_TYPE_DECLARATION_NODE_HPP
#define TASTR_AST_TYPE_DECLARATION_NODE_HPP

#include "ast/IdentifierNode.hpp"
#include "ast/Keyword.hpp"
#include "ast/TypeNode.hpp"

#include <memory>
#include <string>

namespace tastr::ast {

class TypeDeclarationNode final: public Node {
  public:
    explicit TypeDeclarationNode(const Keyword& keyword,
                                 std::unique_ptr<IdentifierNode> identifier,
                                 std::unique_ptr<TypeNode> type)
        : Node()
        , keyword_(keyword)
        , identifier_(std::move(identifier))
        , type_(std::move(type)) {
    }

    TypeDeclarationNode(const TypeDeclarationNode& node)
        : Node(node)
        , keyword_(node.keyword_)
        , identifier_(node.identifier_->clone())
        , type_(node.type_->clone()) {
    }

    ~TypeDeclarationNode() = default;

    TypeDeclarationNode(TypeDeclarationNode&& node)
        : Node(std::move(node))
        , keyword_(std::move(node.keyword_))
        , identifier_(std::move(node.identifier_))
        , type_(std::move(node.type_)) {
    }

    TypeDeclarationNode& operator=(const TypeDeclarationNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        keyword_ = node.keyword_;
        identifier_ = node.identifier_->clone();
        type_ = node.type_->clone();
        return *this;
    }

    TypeDeclarationNode& operator=(TypeDeclarationNode&& node) {
        Node::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        identifier_ = std::move(node.identifier_);
        type_ = std::move(node.type_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

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

    const Keyword& get_keyword() const {
        return keyword_;
    }

  private:
    virtual TypeDeclarationNode* clone_impl() const override final {
        return new TypeDeclarationNode(*this);
    }

    Keyword keyword_;
    std::unique_ptr<IdentifierNode> identifier_;
    std::unique_ptr<TypeNode> type_;
};

using TypeDeclarationNodePtr = TypeDeclarationNode*;
using TypeDeclarationNodeUPtr = std::unique_ptr<TypeDeclarationNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_DECLARATION_NODE_HPP */
