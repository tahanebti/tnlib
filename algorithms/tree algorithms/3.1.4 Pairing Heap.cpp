/*

Maintain a mergeable min-priority queue, that is, a collection of elements with
support for querying and extraction of the minimum as well as efficient merging
with other instances. This implementation requires an ordering on the set of
possible elements defined by the < operator. A pairing heap is a heap-ordered
multi-way tree, using a two-pass merge to self-adjust during each deletion.

- pairing_heap() constructs an empty priority queue.
- pairing_heap(lo, hi) constructs a priority queue from two ForwardIterators,
  consisting of elements in the range [lo, hi).
- size() returns the size of the priority queue.
- empty() returns whether the priority queue is empty.
- push(v) inserts the value v into the priority queue.
- pop() removes the minimum element from the priority queue.
- top() returns the minimum element in the priority queue.
- absorb(h) inserts every value from h and sets h to the empty priority queue.

Time Complexity:
- O(1) per call to the first constructor, size(), empty(), top(), push(), and
  absorb().
- O(log n) amortized per call to pop().
- O(n) per call to the second constructor on the distance between lo and hi.

Space Complexity:
- O(n) for storage of the priority queue elements.
- O(log n) amortized auxiliary stack space for pop().
- O(1) auxiliary for all other operations.

*/

#include <cstddef>
#include <stdexcept>

template<class T>
class pairing_heap {
  struct node_t {
    T value;
    node_t *left, *next;

    node_t(const T &v) : value(v), left(NULL), next(NULL) {}

    void add_child(node_t *n) {
      if (left == NULL) {
        left = n;
      } else {
        n->next = left;
        left = n;
      }
    }
  } *root;

  int num_nodes;

  static node_t* merge(node_t *a, node_t *b) {
    if (a == NULL) {
      return b;
    }
    if (b == NULL) {
      return a;
    }
    if (a->value < b->value) {
      a->add_child(b);
      return a;
    }
    b->add_child(a);
    return b;
  }

  static node_t* merge_pairs(node_t *n) {
    if (n == NULL || n->next == NULL) {
      return n;
    }
    node_t *a = n, *b = n->next, *c = n->next->next;
    a->next = b->next = NULL;
    return merge(merge(a, b), merge_pairs(c));
  }

  static void clean_up(node_t *n) {
    if (n != NULL) {
      clean_up(n->left);
      clean_up(n->next);
      delete n;
    }
  }

 public:
  pairing_heap() : root(NULL), num_nodes(0) {}

  template<class It>
  pairing_heap(It lo, It hi) : root(NULL), num_nodes(0) {
    while (lo != hi) {
      push(*(lo++));
    }
  }

  ~pairing_heap() {
    clean_up(root);
  }

  int size() const {
    return num_nodes;
  }

  bool empty() const {
    return root == NULL;
  }

  void push(const T &v) {
    root = merge(root, new node_t(v));
    num_nodes++;
  }

  void pop() {
    if (empty()) {
      throw std::runtime_error("Cannot pop from empty heap.");
    }
    node_t *tmp = root;
    root = merge_pairs(root->left);
    delete tmp;
    num_nodes--;
  }

  T top() const {
    if (empty()) {
      throw std::runtime_error("Cannot get top of empty heap.");
    }
    return root->value;
  }

  void absorb(pairing_heap &h) {
    root = merge(root, h.root);
    h.root = NULL;
  }
};

/*** Example Usage and Output:

-1
0
5
10
12

***/

#include <iostream>
using namespace std;

int main() {
  pairing_heap<int> h, h2;
  h.push(12);
  h.push(10);
  h2.push(5);
  h2.push(-1);
  h2.push(0);
  h.absorb(h2);
  while (!h.empty()) {
    cout << h.top() << endl;
    h.pop();
  }
  return 0;
}
