#ifndef TASTR_AST_S4_TYPE_NODE_HPP
#define TASTR_AST_S4_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class S4TypeNode final: public TypeNode {
  public:
    explicit S4TypeNode(KeywordNodeUPtr keyword): TypeNode(), keyword_(std::move(keyword)) {
    }

    ~S4TypeNode() = default;

    S4TypeNode(const S4TypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    S4TypeNode(S4TypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    S4TypeNode& operator=(const S4TypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        return *this;
    }

    S4TypeNode& operator=(S4TypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<S4TypeNode> clone() const {
        return std::unique_ptr<S4TypeNode>(this->clone_impl());
    }

    bool is_s4_type_node() const override final {
        return true;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual S4TypeNode* clone_impl() const override final {
        return new S4TypeNode(*this);
    };

    KeywordNodeUPtr keyword_;
};

using S4TypeNodePtr = S4TypeNode*;
using S4TypeNodeUPtr = std::unique_ptr<S4TypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_S4_TYPE_NODE_HPP */
