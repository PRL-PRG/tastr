#ifndef TASTR_AST_COMMA_SEPARATOR_NODE_HPP
#define TASTR_AST_COMMA_SEPARATOR_NODE_HPP

#include "ast/Node.hpp"
#include "ast/SeparatorNode.hpp"

#include <memory>
#include <string>

namespace tastr::ast {

class CommaSeparatorNode final: public Node {
  public:
    explicit CommaSeparatorNode(std::unique_ptr<SeparatorNode> separator,
                                std::unique_ptr<Node> first_node,
                                std::unique_ptr<Node> second_node)
        : Node()
        , separator_(std::move(separator))
        , first_node_(std::move(first_node))
        , second_node_(std::move(second_node)) {
    }

    ~CommaSeparatorNode() = default;

    CommaSeparatorNode(const CommaSeparatorNode& node)
        : Node(node)
        , separator_(node.separator_->clone())
        , first_node_(node.first_node_->clone())
        , second_node_(node.second_node_->clone()) {
    }

    CommaSeparatorNode(CommaSeparatorNode&& node)
        : Node(std::move(node))
        , separator_(std::move(node.separator_))
        , first_node_(std::move(node.first_node_))
        , second_node_(std::move(node.second_node_)) {
    }

    CommaSeparatorNode& operator=(const CommaSeparatorNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        separator_ = node.separator_->clone();
        first_node_ = node.first_node_->clone();
        second_node_ = node.second_node_->clone();
        return *this;
    }

    CommaSeparatorNode& operator=(CommaSeparatorNode&& node) {
        Node::operator=(std::move(node));
        separator_ = std::move(node.separator_);
        first_node_ = std::move(node.first_node_);
        second_node_ = std::move(node.second_node_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<CommaSeparatorNode> clone() const {
        return std::unique_ptr<CommaSeparatorNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const tastr::ast::SeparatorNode& get_separator() const {
        return *separator_.get();
    }

    const tastr::ast::Node& get_first_node() const {
        return *first_node_.get();
    }

    const tastr::ast::Node& get_second_node() const {
        return *second_node_.get();
    }

    bool is_comma_separator_node() const override final {
        return true;
    }

  private:
    virtual CommaSeparatorNode* clone_impl() const override final {
        return new CommaSeparatorNode(*this);
    }

    std::unique_ptr<SeparatorNode> separator_;
    std::unique_ptr<Node> first_node_;
    std::unique_ptr<Node> second_node_;

    static const Kind kind_;
};

using CommaSeparatorNodePtr = CommaSeparatorNode*;
using CommaSeparatorNodeUPtr = std::unique_ptr<CommaSeparatorNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_COMMA_SEPARATOR_NODE_HPP */
