#ifndef TASTR_AST_IDENTIFIER_NODE_HPP
#define TASTR_AST_IDENTIFIER_NODE_HPP

#include "ast/Node.hpp"

#include <iostream>

namespace tastr::ast {

class IdentifierNode final: public Node {
  public:
    explicit IdentifierNode(const std::string& name,
                            bool quoted = false,
                            bool missing = false)
        : Node(), name_(name), quoted_(quoted), missing_(missing) {
    }

    ~IdentifierNode() = default;

    IdentifierNode(const IdentifierNode& node)
        : Node(node)
        , name_(node.name_)
        , quoted_(node.quoted_)
        , missing_(node.missing_) {
    }

    IdentifierNode(IdentifierNode&& node)
        : Node(std::move(node))
        , name_(std::move(node.name_))
        , quoted_(std::move(node.quoted_))
        , missing_(std::move(node.missing_)) {
    }

    IdentifierNode& operator=(const IdentifierNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        name_ = node.name_;
        quoted_ = node.quoted_;
        missing_ = node.missing_;
        return *this;
    }

    IdentifierNode& operator=(IdentifierNode&& node) {
        Node::operator=(std::move(node));
        name_ = std::move(node.name_);
        quoted_ = std::move(node.quoted_);
        missing_ = std::move(node.missing_);
        return *this;
    }

    std::unique_ptr<IdentifierNode> clone() const {
        return std::unique_ptr<IdentifierNode>(this->clone_impl());
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    Kind get_kind() const override final {
        return kind_;
    }

    const std::string& get_name() const {
        return name_;
    }

    bool is_quoted() const {
        return quoted_;
    }

    bool is_missing() const {
        return missing_;
    }

  private:
    virtual IdentifierNode* clone_impl() const override final {
        return new IdentifierNode(*this);
    }

    std::string name_;
    bool quoted_;
    bool missing_;
    static const Kind kind_;
};

using IdentifierNodePtr = IdentifierNode*;
using IdentifierNodeUPtr = std::unique_ptr<IdentifierNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_IDENTIFIER_NODE_HPP */
