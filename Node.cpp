// Node.cpp
// tom bailey   1050  31 jan 2011
// Definitions of the Node class methods
// MODIFIED: by rafe cooley 11/13/2017

#include "Node.h"
#include <string>

using namespace std;

Node::Node(string entry)
	: entry_(entry), next_(NULL)
{
}

Node::Node(string entry, Node * next)
	: entry_(entry), next_(next)
{
}

Node::~Node()
{

}
