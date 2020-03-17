#ifndef TASTR_AST_PARAMETER_TYPE_NODE_HPP
#define TASTR_AST_PARAMETER_TYPE_NODE_HPP

#include "ast/Bracket.hpp"
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
    }

    ~ParameterNode() = default;

    ParameterNode(const ParameterNode& node)
        : Node(node), Bracketed(node), elements_(node.elements_->clone()) {
    }

    ParameterNode(ParameterNode&& node)
        : Node(std::move(node))
        , Bracketed(std::move(node))
        , elements_(std::move(node.elements_)) {
    }

    ParameterNode& operator=(const ParameterNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        Bracketed::operator=(node);
        elements_ = node.elements_->clone();
        return *this;
    }

    ParameterNode& operator=(ParameterNode&& node) {
        Node::operator=(std::move(node));
        Bracketed::operator=(std::move(node));
        elements_ = std::move(node.elements_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ParameterNode> clone() const {
        return std::unique_ptr<ParameterNode>(this->clone_impl());
    }

    bool is_parameter_node() const override final {
        return true;
    }

    Node& get_elements() const {
        return *elements_.get();
    }

  private:
    virtual ParameterNode* clone_impl() const override final {
        return new ParameterNode(*this);
    }

    NodeUPtr elements_;
};

using ParameterNodePtr = ParameterNode*;
using ParameterNodeUPtr = std::unique_ptr<ParameterNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_PARAMETER_TYPE_NODE_HPP */
