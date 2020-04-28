#ifndef TASTR_AST_TYPE_DECLARATION_NODE_HPP
#define TASTR_AST_TYPE_DECLARATION_NODE_HPP

#include "ast/IdentifierNode.hpp"
#include "ast/KeywordNode.hpp"
#include "ast/TerminatorNode.hpp"
#include "ast/TypeNode.hpp"

#include <memory>
#include <string>

namespace tastr {
namespace ast {

class TypeDeclarationNode final: public Node {
  public:
    explicit TypeDeclarationNode(KeywordNodeUPtr keyword,
                                 IdentifierNodeUPtr identifier,
                                 TypeNodeUPtr type,
                                 TerminatorNodeUPtr terminator)
        : Node()
        , keyword_(std::move(keyword))
        , identifier_(std::move(identifier))
        , type_(std::move(type))
        , terminator_(std::move(terminator)) {
    }

    TypeDeclarationNode(const TypeDeclarationNode& node)
        : Node(node)
        , keyword_(node.keyword_->clone())
        , identifier_(node.identifier_->clone())
        , type_(node.type_->clone())
        , terminator_(node.terminator_->clone()) {
    }

    ~TypeDeclarationNode() = default;

    TypeDeclarationNode(TypeDeclarationNode&& node)
        : Node(std::move(node))
        , keyword_(std::move(node.keyword_))
        , identifier_(std::move(node.identifier_))
        , type_(std::move(node.type_))
        , terminator_(std::move(node.terminator_)) {
    }

    TypeDeclarationNode& operator=(const TypeDeclarationNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        keyword_ = node.keyword_->clone();
        identifier_ = node.identifier_->clone();
        type_ = node.type_->clone();
        terminator_ = node.terminator_->clone();
        return *this;
    }

    TypeDeclarationNode& operator=(TypeDeclarationNode&& node) {
        Node::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        identifier_ = std::move(node.identifier_);
        type_ = std::move(node.type_);
        terminator_ = std::move(node.terminator_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<TypeDeclarationNode> clone() const {
        return std::unique_ptr<TypeDeclarationNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const tastr::ast::IdentifierNode& get_identifier() const {
        return *identifier_.get();
    }

    const tastr::ast::TypeNode& get_type() const {
        return *type_.get();
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

    const TerminatorNode& get_terminator() const {
        return *terminator_.get();
    }

  private:
    virtual TypeDeclarationNode* clone_impl() const override final {
        return new TypeDeclarationNode(*this);
    }

    KeywordNodeUPtr keyword_;
    IdentifierNodeUPtr identifier_;
    TypeNodeUPtr type_;
    TerminatorNodeUPtr terminator_;

    static const Kind kind_;
};

using TypeDeclarationNodePtr = TypeDeclarationNode*;
using TypeDeclarationNodeUPtr = std::unique_ptr<TypeDeclarationNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_TYPE_DECLARATION_NODE_HPP */
