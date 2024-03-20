// File: optional_node.cpp
// Purpose: The optional node quantifier
// Author: Krishna sai
#include "optional_node.h"

OptionalNode::OptionalNode(RegexNode* _node)
{
  this->_node = _node;  
}

// attempt to match the string at position pos
bool OptionalNode::match(const std::string& str, size_t &pos)
{
  // Check if the position is within the bounds of the string
  if (pos >= str.length()) {
    return true; // The optional node matches if the position is out of bounds
  }

  // Try to match the inner node
  size_t original_pos = pos; // Store the original position
  if (_node->match(str, pos)) {
    // If the inner node matches, return true
    return true;
  } else {
    // If the inner node does not match, return true (optional node)
    pos = original_pos; // Reset the position
    return true;
  }
}
