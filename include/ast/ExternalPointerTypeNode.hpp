#ifndef TASTR_AST_EXTERNAL_POINTER_TYPE_NODE_HPP
#define TASTR_AST_EXTERNAL_POINTER_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class ExternalPointerTypeNode final: public TypeNode {
  public:
    explicit ExternalPointerTypeNode(KeywordNodeUPtr keyword)
        : TypeNode(), keyword_(std::move(keyword)) {
    }

    ~ExternalPointerTypeNode() = default;

    ExternalPointerTypeNode(const ExternalPointerTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    ExternalPointerTypeNode(ExternalPointerTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    ExternalPointerTypeNode& operator=(const ExternalPointerTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        return *this;
    }

    ExternalPointerTypeNode& operator=(ExternalPointerTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ExternalPointerTypeNode> clone() const {
        return std::unique_ptr<ExternalPointerTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual ExternalPointerTypeNode* clone_impl() const override final {
        return new ExternalPointerTypeNode(*this);
    };

    KeywordNodeUPtr keyword_;

    static const Kind kind_;
};

using ExternalPointerTypeNodePtr = ExternalPointerTypeNode*;
using ExternalPointerTypeNodeUPtr = std::unique_ptr<ExternalPointerTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_EXTERNAL_POINTER_TYPE_NODE_HPP */
