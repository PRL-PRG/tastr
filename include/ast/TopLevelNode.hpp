#ifndef TASTR_AST_TOP_LEVEL_NODE_HPP
#define TASTR_AST_TOP_LEVEL_NODE_HPP

#include "Sequence.hpp"
#include "TypeDeclarationNodeSequenceNode.hpp"
#include "TypeNode.hpp"

#include <string>

namespace tastr::ast {

class TopLevelNode final: public Node {
  public:
    explicit TopLevelNode(const std::string& name)
        : name_(name), sequence_(new TypeDeclarationNodeSequenceNode()) {
    }

    explicit TopLevelNode(const std::string& name,
                          TypeDeclarationNodeSequenceNodeUPtr sequence)
        : name_(name), sequence_(std::move(sequence)) {
    }

    ~TopLevelNode() = default;

    TopLevelNode(const TopLevelNode& node)
        : Node(node), name_(node.name_), sequence_(node.sequence_->clone()) {
    }

    TopLevelNode(TopLevelNode&& node)
        : Node(std::move(node))
        , name_(std::move(node.name_))
        , sequence_(std::move(node.sequence_)) {
    }

    TopLevelNode& operator=(const TopLevelNode& node) {
        if (&node == this) {
            return *this;
        }
        Node::operator=(node);
        name_ = node.name_;
        sequence_ = node.sequence_->clone();
        return *this;
    }

    TopLevelNode& operator=(TopLevelNode&& node) {
        Node::operator=(std::move(node));
        name_ = std::move(node.name_);
        sequence_ = std::move(node.sequence_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<TopLevelNode> clone() const {
        return std::unique_ptr<TopLevelNode>(this->clone_impl());
    }

    bool is_top_level_node() const override final {
        return true;
    }

    const TypeDeclarationNodeSequenceNode& get_type_declarations() const {
        return *sequence_.get();
    }

    TypeDeclarationNodeSequenceNode& get_type_declarations() {
        return *sequence_.get();
    }

  private:
    virtual TopLevelNode* clone_impl() const override final {
        return new TopLevelNode(*this);
    }

    std::string name_;
    TypeDeclarationNodeSequenceNodeUPtr sequence_;
};

using TopLevelNodePtr = TopLevelNode*;
using TopLevelNodeUPtr = std::unique_ptr<TopLevelNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TOP_LEVEL_NODE_HPP */
