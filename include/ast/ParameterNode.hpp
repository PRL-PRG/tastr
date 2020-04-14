#ifndef TASTR_AST_PARAMETER_TYPE_NODE_HPP
#define TASTR_AST_PARAMETER_TYPE_NODE_HPP

#include "ast/Bracket.hpp"
#include "ast/CommaSeparatorNode.hpp"
#include "ast/Node.hpp"

namespace tastr::ast {

class ParameterNode final
    : public Node
    , public Bracketed {
  public:
    explicit ParameterNode(OperatorNodeUPtr opening_bracket,
                           OperatorNodeUPtr closing_bracket,
                           NodeUPtr elements)
        : Node()
        , Bracketed(std::move(opening_bracket), std::move(closing_bracket))
        , elements_(std::move(elements)) {
        initialize_size_();
    }

    ~ParameterNode() = default;

    ParameterNode(const ParameterNode& node)
        : Node(node)
        , Bracketed(node)
        , elements_(node.elements_->clone())
        , count_(node.count_) {
    }

    ParameterNode(ParameterNode&& node)
        : Node(std::move(node))
        , Bracketed(std::move(node))
        , elements_(std::move(node.elements_))
        , count_(std::move(node.count_)) {
    }

    ParameterNode& operator=(const ParameterNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        Bracketed::operator=(node);
        elements_ = node.elements_->clone();
        count_ = node.count_;
        return *this;
    }

    ParameterNode& operator=(ParameterNode&& node) {
        Node::operator=(std::move(node));
        Bracketed::operator=(std::move(node));
        elements_ = std::move(node.elements_);
        count_ = std::move(node.count_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ParameterNode> clone() const {
        return std::unique_ptr<ParameterNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    Node& get_elements() const {
        return *elements_.get();
    }

    count_t get_parameter_count() const {
        return count_;
    }

    const Node& at(count_t index) const {
        count_t count = get_parameter_count();
        const Node& node = get_elements();

        // TODO: std::assert(index < count);
        // TODO: error if index >= count or index < 0

        if (count == 1) {
            return node;
        } else {
            return at_(index, node);
        }
    }

  private:
    virtual ParameterNode* clone_impl() const override final {
        return new ParameterNode(*this);
    }

    const Node& at_(count_t index, const Node& node) const {
        if (index == 0 && !node.is_comma_separator_node()) {
            // TODO: assert(!node.is_comma_separator_node());
            // TODO: error
            return node;
        }

        // TODO: assert(node.is_comma_separator_node());
        // TODO: error

        const CommaSeparatorNode& csnode = as<CommaSeparatorNode>(node);
        const Node& first_node = csnode.get_first_node();
        const Node& second_node = csnode.get_second_node();

        count_t first_node_count = 1;

        if (first_node.is_comma_separator_node()) {
            first_node_count =
                as<CommaSeparatorNode>(first_node).get_node_count();
        }

        if (index < first_node_count) {
            return at_(index, first_node);
        } else {
            return at_(index - first_node_count, second_node);
        }
    }

    void initialize_size_() {
        Node& elements = get_elements();

        if (elements.is_empty_node()) {
            count_ = 0;
        } else if (elements.is_comma_separator_node()) {
            CommaSeparatorNode& all_elements = as<CommaSeparatorNode>(elements);
            count_ = all_elements.get_node_count();
        } else {
            count_ = 1;
        }
    }

    NodeUPtr elements_;
    count_t count_;

    static const Kind kind_;
};

using ParameterNodePtr = ParameterNode*;
using ParameterNodeUPtr = std::unique_ptr<ParameterNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_PARAMETER_TYPE_NODE_HPP */
