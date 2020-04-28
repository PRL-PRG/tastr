#ifndef TASTR_AST_COMMA_SEPARATOR_NODE_HPP
#define TASTR_AST_COMMA_SEPARATOR_NODE_HPP

#include "ast/Node.hpp"
#include "ast/SeparatorNode.hpp"

#include <memory>
#include <string>

namespace tastr {
namespace ast {

class CommaSeparatorNode final: public Node {
  public:
    explicit CommaSeparatorNode(std::unique_ptr<SeparatorNode> separator,
                                std::unique_ptr<Node> first_node,
                                std::unique_ptr<Node> second_node)
        : Node()
        , separator_(std::move(separator))
        , first_node_(std::move(first_node))
        , second_node_(std::move(second_node))
        , node_count_(0) {
        initialize_node_count_();
    }

    ~CommaSeparatorNode() = default;

    CommaSeparatorNode(const CommaSeparatorNode& node)
        : Node(node)
        , separator_(node.separator_->clone())
        , first_node_(node.first_node_->clone())
        , second_node_(node.second_node_->clone())
        , node_count_(node.node_count_) {
    }

    CommaSeparatorNode(CommaSeparatorNode&& node)
        : Node(std::move(node))
        , separator_(std::move(node.separator_))
        , first_node_(std::move(node.first_node_))
        , second_node_(std::move(node.second_node_))
        , node_count_(std::move(node.node_count_)) {
    }

    CommaSeparatorNode& operator=(const CommaSeparatorNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        separator_ = node.separator_->clone();
        first_node_ = node.first_node_->clone();
        second_node_ = node.second_node_->clone();
        node_count_ = node.node_count_;
        return *this;
    }

    CommaSeparatorNode& operator=(CommaSeparatorNode&& node) {
        Node::operator=(std::move(node));
        separator_ = std::move(node.separator_);
        first_node_ = std::move(node.first_node_);
        second_node_ = std::move(node.second_node_);
        node_count_ = std::move(node.node_count_);
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

    count_t get_node_count() const {
        return node_count_;
    }

  private:
    virtual CommaSeparatorNode* clone_impl() const override final {
        return new CommaSeparatorNode(*this);
    }

    void initialize_node_count_() {
        count_t first_node_count = 1;

        if (first_node_->is_comma_separator_node()) {
            first_node_count =
                as<CommaSeparatorNode>(first_node_.get())->get_node_count();
        }

        count_t second_node_count = 1;
        if (second_node_->is_comma_separator_node()) {
            second_node_count =
                as<CommaSeparatorNode>(second_node_.get())->get_node_count();
        }

        node_count_ = first_node_count + second_node_count;
    }

    std::unique_ptr<SeparatorNode> separator_;
    std::unique_ptr<Node> first_node_;
    std::unique_ptr<Node> second_node_;
    count_t node_count_;

    static const Kind kind_;
};

using CommaSeparatorNodePtr = CommaSeparatorNode*;
using CommaSeparatorNodeUPtr = std::unique_ptr<CommaSeparatorNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_COMMA_SEPARATOR_NODE_HPP */
