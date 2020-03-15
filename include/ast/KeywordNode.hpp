#ifndef TASTR_AST_KEYWORD_NODE_HPP
#define TASTR_AST_KEYWORD_NODE_HPP

#include "ast/Node.hpp"

#include <string>

namespace tastr::ast {

class KeywordNode final: public Node {
  public:
    explicit KeywordNode(const std::string& value): Node(), value_(value) {
    }

    ~KeywordNode() = default;

    KeywordNode(const KeywordNode& node): Node(node), value_(node.value_) {
    }

    KeywordNode(KeywordNode&& node)
        : Node(std::move(node)), value_(std::move(node.value_)) {
    }

    KeywordNode& operator=(const KeywordNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        value_ = node.value_;
        return *this;
    }

    KeywordNode& operator=(KeywordNode&& node) {
        Node::operator=(std::move(node));
        value_ = std::move(node.value_);
        return *this;
    }

    std::unique_ptr<KeywordNode> clone() const {
        return std::unique_ptr<KeywordNode>(this->clone_impl());
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    const std::string& get_value() const {
        return value_;
    }

  private:
    virtual KeywordNode* clone_impl() const override final {
        return new KeywordNode(*this);
    }

    std::string value_;
};

using KeywordNodePtr = KeywordNode*;
using KeywordNodeUPtr = std::unique_ptr<KeywordNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_KEYWORD_NODE_HPP */
